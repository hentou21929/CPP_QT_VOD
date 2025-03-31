#include"LogicSystem.h"
#include "httpconnection.h" 
#include "MySQLWrapper.h"
#include "DBError.h"
#include "SafeConvert.h"
#include <cstdlib> // for system()
#include <string>
#include <jwt-cpp/jwt.h> 
#include <openssl/opensslv.h>  
#include <openssl/hmac.h>      
#include <unistd.h>
#include <boost/process.hpp>
#include <sys/wait.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <future>
#include <cstdlib>
#include <sstream>
#include <iomanip>

namespace bp = boost::process;  // 定义命名空间别名
void LogicSystem::RegGet(std::string url, HttpHandler handler) {
    _get_handlers.insert(make_pair(url, handler));
}

void LogicSystem::RegPost(std::string url, HttpHandler handler) {
    _post_handlers.insert(std::make_pair(url, handler));
}

void LogicSystem::HandleVideoRequest(std::shared_ptr<HttpConnection> con) {
    try {
        MySQLWrapper db("localhost", "root", "", "chat_database");
        auto result = db.ExecuteQuery("SELECT * FROM videos");

        // 创建一个顶层 JSON 对象
        Json::Value response;
        Json::Value dataArray(Json::arrayValue); // 用于存储视频数组

        // 遍历查询结果并构建 JSON 数组
        for (const auto& row : result) {  // row 自动推断为 MYSQL_ROW (char**)
            if (!row) continue;  // 跳过空行

            Json::Value item;
            item["id"] = std::to_string(SafeConvert<int>(row[0])); 
            item["pic"] = SafeConvert(row[1]);
            item["title"] = SafeConvert(row[2]);
            item["author"] = SafeConvert(row[3]);
            item["duration"] = SafeConvert<int>(row[4]);
            item["pubdate"] = SafeConvert<int>(row[5]);
            item["danmaku"] = SafeConvert<int>(row[6]);
            item["views"] = Json::Int64(SafeConvert<int64_t>(row[7]));
            item["likes"] = Json::Int64(SafeConvert<int64_t>(row[8]));
            item["video_url"] = SafeConvert(row[9]);

            dataArray.append(item); // 将每个视频对象添加到数组中
        }

        // 构造嵌套的 JSON 结构
        response["data"]["item"] = dataArray;

        // 发送响应
        SendSuccessResponse(con, response);
    } catch (const MySQLException& e) {
        DBError::SendResponse(con, DBCode::QueryFailed, e.what());
    }
}
// 辅助函数：发送成功响应
void LogicSystem::SendSuccessResponse(std::shared_ptr<HttpConnection> con, const Json::Value& data) {
    // 使用 Json::StreamWriterBuilder 生成 JSON 字符串
    Json::StreamWriterBuilder writer;
    writer["indentation"] = ""; // 禁用缩进，生成紧凑格式

    std::string json_str = Json::writeString(writer, data); // 生成紧凑格式的 JSON

    // 设置 HTTP 响应状态码和内容类型
    auto& response = con->_response;
    response.result(http::status::ok);
    response.set(http::field::content_type, "application/json");

    // 将 JSON 数据写入响应体
    beast::ostream(response.body()) << json_str;
}

// 辅助函数：发送错误响应
void LogicSystem::SendErrorResponse(std::shared_ptr<HttpConnection> con, int code, const std::string& error) {
    Json::Value root;
    root["code"] = code;
    root["error"] = error;

    Json::StreamWriterBuilder writer;
    std::string json_str = Json::writeString(writer, root);

    auto& response = con->_response;
    response.result(code == 500 ? http::status::internal_server_error : http::status::bad_request);
    response.set(http::field::content_type, "application/json");
    beast::ostream(response.body()) << json_str;
}
void LogicSystem::StartStream(std::shared_ptr<HttpConnection> con) {
    try {
        // 解析 JSON 请求体
        Json::Value root;
        if (!ParseJsonRequest(con, root)) {
            SendErrorResponse(con, 400, "Invalid JSON format");
            return;
        }

        //std::string username = root["username"].asString();
        
        // 定义输入和输出参数
        //std::string inputUrl = "http://videomaster.oss-cn-shenzhen.aliyuncs.com/videos/1.mp4";
        std::string inputUrl = root["video_url"].asString();
        // 1. 更新数据库播放量
        try {
            MySQLWrapper db("localhost", "root", "", "chat_database");
            std::string query = 
                "UPDATE videos SET view = view + 1 WHERE video_url = '" + 
                db.EscapeString(inputUrl) + "'";
            
           db.ExecuteUpdate(query);
            
        } catch (const MySQLException& e) {
            SendErrorResponse(con, 500, std::string("Database error: ") + e.what());
            return;
        }
        std::string videoid = generateUniqueTimestamp();

        std::string outputUrl = "rtmp://119.91.46.232/live/";
        outputUrl+=videoid;

        // 构造 FFmpeg 命令
        std::string ffmpegCommand = "ffmpeg "
            "-re "
            "-i " + inputUrl + " " +          // 输入文件
            "-c:v libx264 "                  // 视频编码器
            "-c:a aac "                      // 音频编码器
            //"-strict experimental "          // 允许实验性功能
            //"-f hls "                        // 输出格式为 HLS
            //"-hls_time 10 "                  // 每个片段的时间长度（秒）
            //"-hls_list_size 6 "              // 播放列表中保留的片段数量
            //"-hls_flags delete_segments "    // 删除旧的片段
            "-f flv "
            + outputUrl;                     // 输出 URL

             // 异步执行 FFmpeg 命令
        // 异步执行 FFmpeg 命令
        std::future<int> result = std::async(std::launch::async, [this, ffmpegCommand]() {
            return this->runFFmpegCommand(ffmpegCommand);
        });

        // 立即发送响应
        Json::Value response;
        std::string seroutputUrl = "http://119.91.46.232:8080/live/";
        seroutputUrl+=videoid+".m3u8";
        response["message"] = "Stream starting in background";
        response["output_url"] = seroutputUrl;  // 添加输出 URL
        SendSuccessResponse(con, response);

        // 在后台处理异步任务的结果
        std::thread([result = std::move(result)]() mutable {
            try {
                int exitCode = result.get();
                if (exitCode == 0) {
                    std::cout << "Stream started successfully." << std::endl;
                } else {
                    std::cerr << "Failed to start stream. Exit code: " << exitCode << std::endl;
                }
            } catch (const std::exception& e) {
                std::cerr << "Exception in async task: " << e.what() << std::endl;
            }
        }).detach();  // 分离线程，让其在后台运行
    } catch (const std::exception& e) {
        SendErrorResponse(con, 500, std::string("Exception: ") + e.what());
    }
}
void LogicSystem::HandleRegister(std::shared_ptr<HttpConnection> con) {
    try {
        // 解析 JSON 请求体
        Json::Value root;
        if (!ParseJsonRequest(con, root)) {
            SendErrorResponse(con, 400, "Invalid JSON format");
            return;
        }

        std::string username = root["username"].asString();
        std::string password = root["password"].asString();

        // 检查用户名和密码是否为空
        if (username.empty() || password.empty()) {
            SendErrorResponse(con, 400, "Username and password are required");
            return;
        }

        // 连接数据库
        MySQLWrapper db("localhost", "root", "", "chat_database");

        // 检查用户名是否已存在
        auto checkResult = db.ExecuteQuery(
            "SELECT id FROM users WHERE username = '" + db.EscapeString(username) + "'"
        );
        if (!checkResult.empty()) {
            SendErrorResponse(con, 409, "Username already exists");
            return;
        }

        // 加密密码
        std::string hashed_password = HashPassword(password);

        // 插入新用户
        db.ExecuteUpdate(
            "INSERT INTO users (username, password_hash) VALUES ('" + 
            db.EscapeString(username) + "', '" + 
            db.EscapeString(hashed_password) + "')"
        );

        // 返回成功响应
        Json::Value response;
        response["code"] = 200;
        response["message"] = "User registered successfully";
        SendSuccessResponse(con, response);

    } catch (const MySQLException& e) {
        SendErrorResponse(con, 500, std::string("Database error: ") + e.what());
    } catch (const std::exception& e) {
        SendErrorResponse(con, 500, std::string("Internal error: ") + e.what());
    }
}
void LogicSystem::HandleUploadFile(std::shared_ptr<HttpConnection> con) {
    try {
        // 解析 JSON 请求体
        Json::Value root;
        if (!ParseJsonRequest(con, root)) {
            SendErrorResponse(con, 400, "Invalid JSON format");
            return;
        }

        // 提取请求参数
        std::string username = root["username"].asString();
        std::string imagefilename = root["imagename"].asString();
        std::string videofilename = root["videoname"].asString();
        std::string videoduration = root["duration"].asString();

        // 检查必要字段是否为空
        if (username.empty() || imagefilename.empty() || videofilename.empty()) {
            SendErrorResponse(con, 400, "Missing required fields: username, imagename, or videoname");
            return;
        }

        // 去掉 imagename 的文件扩展名，作为视频标题
        size_t pos = imagefilename.find_last_of('.');
        std::string title = (pos != std::string::npos) ? imagefilename.substr(0, pos) : imagefilename;

        // 构造 pic 和 video_url
        std::string pic_url = "https://videomaster.oss-cn-shenzhen.aliyuncs.com/" + imagefilename;
        std::string video_url = "https://videomaster.oss-cn-shenzhen.aliyuncs.com/" + videofilename;

        // 获取当前时间戳
        time_t pubdate = std::time(nullptr);

        // 连接数据库
        MySQLWrapper db("localhost", "root", "", "chat_database");

        // 插入数据到 videos 表
        // 插入数据到 videos 表
        std::string query = "INSERT INTO videos (pic, title, name, duration, pubdate, danmu, view, `like`, video_url) "
                            "VALUES ('" +
                            db.EscapeString(pic_url) + "', '" +
                            db.EscapeString(title) + "', '" +
                            db.EscapeString(username) + "', " +
                            videoduration + ", " + // 直接插入 duration 的值（不加引号）
                            std::to_string(pubdate) + ", " +
                            "0, " + // danmu 随意设置为 0
                            "0, " + // view 随意设置为 0
                            "0, '" + // like 随意设置为 0
                            db.EscapeString(video_url) + "')";

        db.ExecuteQuery(query);

        // 返回成功响应
        Json::Value response;
        response["code"] = 200;
        response["message"] = "Upload file successfully";
        SendSuccessResponse(con, response);

    } catch (const MySQLException& e) {
        SendErrorResponse(con, 500, std::string("Database error: ") + e.what());
    } catch (const std::exception& e) {
        SendErrorResponse(con, 500, std::string("Internal error: ") + e.what());
    }
}
void LogicSystem::HandleLogin(std::shared_ptr<HttpConnection> con) {
    try {
        // 解析 JSON 请求体
        Json::Value root;
        if (!ParseJsonRequest(con, root)) {
            SendErrorResponse(con, 400, "Invalid JSON format");
            return;
        }

        std::string username = root["username"].asString();
        std::string password = root["password"].asString();

        // 连接数据库
        MySQLWrapper db("localhost", "root", "", "chat_database");

        // 查询用户信息
        auto result = db.ExecuteQuery("SELECT id, password_hash FROM users WHERE username = '" + db.EscapeString(username) + "'");

        // 检查结果是否为空
        if (result.empty()) {  // 使用新增的 empty() 方法
            SendErrorResponse(con, 401, "Invalid username or password");
            return;
        }

        // 获取第一行数据
        auto it = result.begin();
        MYSQL_ROW row = *it;

        // 验证密码
        std::string stored_hash = row[1];
        if (HashPassword(password) != stored_hash) {
            SendErrorResponse(con, 401, "Invalid username or password");
            return;
        }

        // 获取用户 ID
        int user_id = SafeConvert<int>(row[0]);  // 第一列是 id

        // 生成 Token
        auto token = jwt::create()
            .set_payload_claim("user_id", jwt::claim(std::to_string(user_id)))
            .sign(jwt::algorithm::hs256{"your_secret_key"});

        // 返回 Token
        Json::Value response;
        response["code"] = 200;
        response["token"] = token;
        SendSuccessResponse(con, response);

    } catch (const MySQLException& e) {
        SendErrorResponse(con, 500, std::string("Database error: ") + e.what());
    } catch (const std::exception& e) {
        SendErrorResponse(con, 500, std::string("Internal error: ") + e.what());
    }
}
// 解析 JSON 请求体
bool LogicSystem::ParseJsonRequest(std::shared_ptr<HttpConnection> con, Json::Value& root) {
    try {
        // 读取请求体
        std::string body = beast::buffers_to_string(con->_request.body().data());
        Json::CharReaderBuilder reader;
        std::string errors;
        std::istringstream iss(body);
        return Json::parseFromStream(reader, iss, &root, &errors);
    } catch (...) {
        return false;
    }
}
std::string LogicSystem::generateUniqueTimestamp() {
    // 获取当前时间点
    auto now = std::chrono::system_clock::now();

    // 转换为时间结构体
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // 格式化时间为字符串（YYYYMMDDHHMMSS）
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&currentTime), "%Y%m%d%H%M%S");

    // 如果需要更高的精度，可以添加毫秒或微秒
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count() % 1000;
    oss << std::setfill('0') << std::setw(3) << milliseconds;

    return oss.str();
}
// 密码加密（使用 bcrypt 算法）
std::string LogicSystem::HashPassword(const std::string& password) {
    // 实际项目中应使用 bcrypt 或 Argon2，此处示例使用简单哈希
    std::hash<std::string> hasher;
    return std::to_string(hasher(password));
}
//ffmpeg 命令执行
int LogicSystem::runFFmpegCommand(const std::string& command) {
    return std::system(command.c_str());
}
LogicSystem::~LogicSystem() {
   
}

LogicSystem::LogicSystem() {
    RegGet("/get_test", [](std::shared_ptr<HttpConnection> connection) {
        beast::ostream(connection->_response.body()) << "receive get_test req";
    });
     // 新增视频数据接口
     RegGet("/api/videos", [this](std::shared_ptr<HttpConnection> con) {
        HandleVideoRequest(con);
    });
    // 新增推流接口
    RegPost("/api/start_stream", [this](std::shared_ptr<HttpConnection> con) {
        StartStream(con);
    });
    // 注册 POST 路由
    RegPost("/api/register", [this](std::shared_ptr<HttpConnection> con) {
        HandleRegister(con);
    });
    RegPost("/api/login", [this](std::shared_ptr<HttpConnection> con) {
        HandleLogin(con);
    });
    RegPost("/api/upload", [this](std::shared_ptr<HttpConnection> con) {
        HandleUploadFile(con);
    });

}

bool LogicSystem::HandleGet(std::string path, std::shared_ptr<HttpConnection> con) {
    if (_get_handlers.find(path) == _get_handlers.end()) {
        return false;
    }

    _get_handlers[path](con);
    return true;
}
bool LogicSystem::HandlePost(std::string path, std::shared_ptr<HttpConnection> con) {
    if (_post_handlers.find(path) == _post_handlers.end()) {
        return false;
    }

    _post_handlers[path](con);
    return true;
}

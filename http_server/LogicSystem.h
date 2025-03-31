#ifndef LOGICSYSTEM_H
#define LOGICSYSTEM_H
#include "Singleton.h"
#include <functional>
#include <map>
#include "const.h"
#include <json/json.h>
#include <mysql/mysql.h>
class HttpConnection;
typedef std::function<void(std::shared_ptr<HttpConnection>)> HttpHandler;
class LogicSystem :public Singleton<LogicSystem>
{
    friend class Singleton<LogicSystem>;
public:
    ~LogicSystem();
    bool HandleGet(std::string, std::shared_ptr<HttpConnection>);
    bool HandlePost(std::string path, std::shared_ptr<HttpConnection> con);
    void RegGet(std::string, HttpHandler handler);
    void HandleVideoRequest(std::shared_ptr<HttpConnection> con);
    void SendSuccessResponse(std::shared_ptr<HttpConnection> con, const Json::Value& data);
    void SendErrorResponse(std::shared_ptr<HttpConnection> con, int code, const std::string& error);
    void HandleImageRequest(std::shared_ptr<HttpConnection> con);
    void StartStream(std::shared_ptr<HttpConnection> con);
   
    
    // 新增 POST 路由注册方法
    void RegPost(std::string url, HttpHandler handler);
    
    // 注册和登录处理函数
    void HandleRegister(std::shared_ptr<HttpConnection> con);
    void HandleLogin(std::shared_ptr<HttpConnection> con);
    void HandleUploadFile(std::shared_ptr<HttpConnection> con);
    bool ParseJsonRequest(std::shared_ptr<HttpConnection> con, Json::Value& root);
    
private:
    LogicSystem();
    std::map<std::string, HttpHandler> _post_handlers;
    std::map<std::string, HttpHandler> _get_handlers;
    // 密码加密工具函数
    std::string HashPassword(const std::string& password);
    static int runFFmpegCommand(const std::string& command);
    std::string generateUniqueTimestamp();
};
#endif
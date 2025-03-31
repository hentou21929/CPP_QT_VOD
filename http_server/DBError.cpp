#include "DBError.h"
#include <unordered_map>
#include "httpconnection.h"
#include "LogicSystem.h" 
namespace {
    const std::unordered_map<DBCode, std::string> kErrorMessages = {
        {DBCode::Success,        "Success"},
        {DBCode::ConnectionFailed, "Database connection failed"},
        {DBCode::QueryFailed,    "Query execution failed"},
        {DBCode::InvalidData,    "Invalid data format"}
    };
}

std::string DBError::GetMessage(DBCode code) {
    auto it = kErrorMessages.find(code);
    return it != kErrorMessages.end() ? 
           it->second : "Unknown database error";
}

void DBError::SendResponse(std::shared_ptr<HttpConnection> con,
                          DBCode code, const std::string& details) {
    Json::Value root;
    root["code"] = static_cast<int>(code);
    root["error"] = GetMessage(code);
    if (!details.empty()) {
         root["details"] = details;
    }
                            
    // 使用公共方法获取响应对象
    auto& res = con->GetResponse(); // 正确访问
    res.result(http::status::internal_server_error);
    res.set(http::field::content_type, "application/json");
    beast::ostream(res.body()) << root.toStyledString();
    
    // 调用公共方法发送响应
    con->SendResponse(); // 正确调用
}
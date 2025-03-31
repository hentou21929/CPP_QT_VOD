#pragma once
#include <memory>
#include "httpconnection.h"  
#include "Exceptions.h"      

class ErrorHandler {
public:
    // 处理数据库相关错误
    static void HandleDatabaseError(
        std::shared_ptr<HttpConnection> con,
        const DBException& e
    ) {
        SendErrorResponse(con, 500, "Database Error: " + std::string(e.what()));
    }

    // 处理系统级错误（如JSON序列化失败）
    static void HandleSystemError(
        std::shared_ptr<HttpConnection> con,
        const std::string& message
    ) {
        SendErrorResponse(con, 500, "System Error: " + message);
    }

    // 处理未知异常
    static void HandleUnexpectedError(std::shared_ptr<HttpConnection> con) {
        SendErrorResponse(con, 500, "Unexpected Internal Error");
    }

private:
    // 假设SendErrorResponse是已实现的工具函数
    static void SendErrorResponse(
        std::shared_ptr<HttpConnection> con,
        int code,
        const std::string& message
    ) {
        // 实际实现应生成JSON格式的错误响应
        Json::Value root;
        root["code"] = code;
        root["message"] = message;
        con->SendResponse(root.toStyledString());
    }
};
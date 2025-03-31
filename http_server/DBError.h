#pragma once
#include "httpconnection.h"
#include <json/json.h>

enum class DBCode {
    Success = 0,
    ConnectionFailed = 1001,
    QueryFailed = 1002,
    InvalidData = 1003
};

namespace DBError {
    void SendResponse(std::shared_ptr<HttpConnection> con, 
                     DBCode code, const std::string& details = "");
    
    std::string GetMessage(DBCode code);
}
#pragma once
#include <string>

class DBConfig {
public:
    static DBConfig& GetInstance();

    std::string host = "localhost";
    std::string user = "root";
    std::string password = "";
    std::string database = "chat_database";

private:
    DBConfig() = default;
};
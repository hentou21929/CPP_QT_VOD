#pragma once
#include <mysql/mysql.h>
#include <stdexcept>
#include <memory>
#include "QueryResult.h" 
class MySQLException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class QueryResult;

class MySQLWrapper {
public:
    MySQLWrapper(const char* host, const char* user, 
                const char* pass, const char* db);
    ~MySQLWrapper();
    
    QueryResult ExecuteQuery(const std::string& query);
    std::string EscapeString(const std::string& input);
    void ExecuteUpdate(const std::string& query);
    
private:
    MYSQL* conn_ = nullptr;
};
#include "MySQLWrapper.h"
#include "QueryResult.h"

MySQLWrapper::MySQLWrapper(const char* host, const char* user,
                         const char* pass, const char* db) {
    conn_ = mysql_init(nullptr);
    if (!conn_) {
        throw MySQLException("MySQL initialization failed");
    }
    
    if (!mysql_real_connect(conn_, host, user, pass, db, 0, NULL, 0)) {
        std::string err = mysql_error(conn_);
        mysql_close(conn_);
        throw MySQLException("Connection failed: " + err);
    }
    
    if (mysql_set_character_set(conn_, "utf8mb4") != 0) {
        std::string err = mysql_error(conn_);
        mysql_close(conn_);
        throw MySQLException("Set charset failed: " + err);
    }
}

MySQLWrapper::~MySQLWrapper() {
    if (conn_) {
        mysql_close(conn_);
        conn_ = nullptr;
    }
}

QueryResult MySQLWrapper::ExecuteQuery(const std::string& query) {
    if (mysql_query(conn_, query.c_str()) != 0) {
        throw MySQLException(mysql_error(conn_));
    }
    
    MYSQL_RES* res = mysql_store_result(conn_);
    if (!res && mysql_field_count(conn_) != 0) {
        throw MySQLException(mysql_error(conn_));
    }
    
    return QueryResult(res);
}
std::string MySQLWrapper::EscapeString(const std::string& input) {
    if (!conn_) {
        throw MySQLException("Connection is not open");
    }

    char* escaped = new char[input.size() * 2 + 1];
    unsigned long length = mysql_real_escape_string(
        conn_, escaped, input.c_str(), input.size()
    );

    std::string result(escaped, length);
    delete[] escaped;
    return result;
}
void MySQLWrapper::ExecuteUpdate(const std::string& query) {
    if (mysql_query(conn_, query.c_str()) != 0) {
        throw MySQLException(mysql_error(conn_));
    }
}
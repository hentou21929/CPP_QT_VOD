// QueryResult.h
#pragma once
#include <mysql/mysql.h>
#include <vector>
#include <string>

class QueryResult {
public:
    explicit QueryResult(MYSQL_RES* res);
    ~QueryResult();
    bool empty() const { return num_rows_ == 0; }
    class Iterator {
    public:
        Iterator(MYSQL_RES* res, unsigned long row_num);
        Iterator& operator++();    // 前置++
        bool operator!=(const Iterator& other) const;
        MYSQL_ROW operator*() const; // 返回当前行数据

    private:
        MYSQL_RES* res_ = nullptr;
        unsigned long row_num_;     // 当前行号
        MYSQL_ROW row_ = nullptr;   // 当前行数据
    };
    
    Iterator begin() const;
    Iterator end() const;

private:
    MYSQL_RES* res_ = nullptr;
    std::vector<std::string> fields_;
    unsigned long num_rows_ = 0;    // 总行数（新增）
};
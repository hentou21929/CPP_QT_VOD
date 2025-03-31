// QueryResult.cpp
#include "QueryResult.h"

QueryResult::QueryResult(MYSQL_RES* res) : res_(res) {
    if (res_) {
        num_rows_ = mysql_num_rows(res_); // 预存总行数
        MYSQL_FIELD* fields = mysql_fetch_fields(res_);
        int num_fields = mysql_num_fields(res_);
        for (int i = 0; i < num_fields; ++i) {
            fields_.emplace_back(fields[i].name);
        }
    }
}

QueryResult::~QueryResult() {
    if (res_) mysql_free_result(res_);
}

// 迭代器构造函数
QueryResult::Iterator::Iterator(MYSQL_RES* res, unsigned long row_num)
    : res_(res), row_num_(row_num) {
    if (res_ && row_num_ < mysql_num_rows(res_)) {
        mysql_data_seek(res_, row_num_); // 跳转到指定行
        row_ = mysql_fetch_row(res_);
    } else {
        row_ = nullptr;
    }
}

// 前置++
QueryResult::Iterator& QueryResult::Iterator::operator++() {
    ++row_num_;
    if (row_num_ < mysql_num_rows(res_)) {
        mysql_data_seek(res_, row_num_);
        row_ = mysql_fetch_row(res_);
    } else {
        row_ = nullptr;
    }
    return *this;
}

// 不等比较
bool QueryResult::Iterator::operator!=(const Iterator& other) const {
    return row_num_ != other.row_num_;
}

// 解引用
MYSQL_ROW QueryResult::Iterator::operator*() const {
    return row_;
}

// begin/end
QueryResult::Iterator QueryResult::begin() const {
    return Iterator(res_, 0);
}

QueryResult::Iterator QueryResult::end() const {
    return Iterator(res_, num_rows_);
}
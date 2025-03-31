#pragma once
#include <mysql/mysql.h>
#include <stdexcept>
#include <memory>
#include <string>
#include <functional>

class SafeResultSet {
public:
    // 行数据包装类
    class Row {
    private:
        MYSQL_ROW row_;
        unsigned long* lengths_;
        unsigned int num_fields_;

    public:
        Row(MYSQL_ROW row, unsigned long* lengths, unsigned int num_fields)
            : row_(row), lengths_(lengths), num_fields_(num_fields) {}

        // 获取字符串类型字段（自动处理空指针）
        std::string GetString(size_t index) const {
            ValidateIndex(index);
            return row_[index] ? std::string(row_[index], lengths_[index]) : "";
        }

        // 获取整数类型字段（安全转换）
        int GetInt(size_t index) const {
            ValidateIndex(index);
            if (!row_[index]) return 0;
            return SafeStrToNum<int>(row_[index]);
        }

        // 获取64位整数类型
        int64_t GetInt64(size_t index) const {
            ValidateIndex(index);
            if (!row_[index]) return 0;
            return SafeStrToNum<int64_t>(row_[index]);
        }

        // 获取日期时间字段（转换为ISO8601格式）
        std::string GetDateTime(size_t index) const {
            ValidateIndex(index);
            if (!row_[index]) return "";

            MYSQL_TIME ts;
            if (mysql_fetch_field_direct(GetRawResult(), index)->type != MYSQL_TYPE_DATETIME) {
                throw std::runtime_error("Field is not a datetime type");
            }

            // 假设字段直接映射到MYSQL_TIME结构（需根据实际结果集处理）
            // 此处需要根据实际查询结果解析，可能需要使用mysql_fetch_lengths等
            // 简化的示例：
            char buf[64];
            snprintf(buf, sizeof(buf), "%04d-%02d-%02dT%02d:%02d:%02d", 
            ts.year, ts.month, ts.day, ts.hour, ts.minute, ts.second);
            return std::string(buf);
        }

    private:
        template<typename T>
        static T SafeStrToNum(const char* str) {
            char* end;
            errno = 0;
            T value = static_cast<T>(std::strtoll(str, &end, 10));
            if (end == str || *end != '\0' || errno == ERANGE) {
                throw std::runtime_error("Invalid numeric conversion");
            }
            return value;
        }

        void ValidateIndex(size_t index) const {
            if (index >= num_fields_) {
                throw std::out_of_range("Column index out of range");
            }
        }

        MYSQL_RES* GetRawResult() const; // 需要外部结果集指针
    };

    // 构造函数（接管MYSQL_RES资源）
    explicit SafeResultSet(MYSQL_RES* res) : res_(res) {
        if (!res_) throw std::invalid_argument("Null result set");
    }

    // 禁止拷贝
    SafeResultSet(const SafeResultSet&) = delete;
    SafeResultSet& operator=(const SafeResultSet&) = delete;

    // 移动语义支持
    SafeResultSet(SafeResultSet&& other) noexcept : res_(other.res_) {
        other.res_ = nullptr;
    }

    ~SafeResultSet() {
        if (res_) mysql_free_result(res_);
    }

    // 遍历每一行
    void ForEachRow(std::function<void(const Row&)> callback) {
        MYSQL_ROW row;
        unsigned int num_fields = mysql_num_fields(res_);
        unsigned long* lengths = mysql_fetch_lengths(res_);

        while ((row = mysql_fetch_row(res_))) {
            callback(Row(row, lengths, num_fields));
        }
    }

private:
    MYSQL_RES* res_;
};
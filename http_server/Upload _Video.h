#ifndef UPLOAD_VIDEO_h
#define UPLOAD_VIDEO_h

#include <string>
#include <chrono>
#include <curl/curl.h>
#include <openssl/hmac.h>

// 生成腾讯云 COS 签名
std::string generate_signature(
    const std::string& secretId,
    const std::string& secretKey,
    const std::string& method,
    const std::string& path,
    const std::string& timestamp
);

// 获取当前时间戳（格式：开始时间;结束时间，例如 "1680000000;1680003600"）
std::string get_cos_timestamp();

// 获取文件大小
long get_file_size(const std::string& file_path);

// Base64 编码函数
std::string base64_encode(const unsigned char* data, size_t length);

#endif // COS_UTILS_HPP
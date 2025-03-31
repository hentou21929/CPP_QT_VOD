#pragma once
#include <sstream>
#include <string>
#include <type_traits>
#include <cstdint>

// 算术类型版本（自动推导返回类型）
template <typename T>
typename std::enable_if_t<std::is_arithmetic_v<T>, T>
SafeConvert(const char* str, T def = T{}) {
    if (!str || *str == '\0') return def;
    
    std::stringstream ss(str);
    T val;
    return (ss >> val) ? val : def;
}

// 字符串版本（无模板参数，自动处理类型推导）
inline std::string SafeConvert(const char* str, std::string def = {}) {
    return str ? str : def;
}

// 直接支持 char* 的版本
inline std::string SafeConvert(char* str, std::string def = {}) {
    return str ? str : def;
}
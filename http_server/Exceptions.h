#pragma once
#include <stdexcept>

class DBException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class JsonException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};
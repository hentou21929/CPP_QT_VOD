#pragma once
#include <json/json.h>

class JsonBuilder {
    Json::Value root;

public:
    JsonBuilder& StartArray(const char* key) {
        root[key] = Json::arrayValue;
        return *this;
    }

    JsonBuilder& StartObject() {
        current = Json::objectValue;
        return *this;
    }

    template <typename T>
    JsonBuilder& Add(const char* key, T value) {
        current[key] = value;
        return *this;
    }

    // 添加 EndObject 方法
    JsonBuilder& EndObject() {
        root[currentKey] = current;
        return *this;
    }

    Json::Value Build() const { return root; }

private:
    Json::Value current;
};
# 编译器设置
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

# 链接库标志（新增内容）
LDFLAGS := -ljsoncpp -lmysqlclient -lssl -lcrypto

# 目标可执行文件名称
TARGET := http_server

# 源文件和头文件
SRCS := main.cpp cserver.cpp httpconnection.cpp LogicSystem.cpp MySQLWrapper.cpp QueryResult.cpp DBError.cpp
OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)

# 包含头文件路径（如果有需要可以添加）
INC_FLAGS := -I. -I/usr/include/mysql

# 默认目标
all: $(TARGET)

# 生成可执行文件（修改链接命令）
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)  # 添加 $(LDFLAGS)

# 模式规则：生成.o和.d文件
%.o: %..cpp
	$(CXX) $(CXXFLAGS) -MMD -MP $(INC_FLAGS) -c $< -o $@

# 包含自动生成的依赖关系
-include $(DEPS)

# 清理编译产物
clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

.PHONY: all clean
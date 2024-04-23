# 可执行文件名称
TARGET = game.exe

# 编译器
CC = g++

# 编译器标志
CFLAGS = -Icode/h -Wall -O2

# 源文件目录
SRC_DIR = code/cpp

# 对象文件目录
OBJ_DIR = obj

# 找到所有的 .cpp 文件
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# 将 .cpp 文件的列表转换为 .o 文件的列表
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# 默认目标
all: $(TARGET)

# 链接目标
$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@

# 从 .cpp 生成 .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"
	$(CC) $(CFLAGS) -c $< -o $@

# 清理目标
clean:
	del /Q $(OBJ_DIR)\*.o
	del /Q $(TARGET)

.PHONY: all clean

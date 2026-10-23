cmake_minimum_required(VERSION 3.20)
project(c_list)

# 设置C++标准，支持模板、就地初始化等现代语法
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 解决Windows控制台中文乱码：源文件UTF-8，输出编码GBK适配控制台
add_compile_options(-finput-charset=UTF-8 -fexec-charset=GBK)

# 生成可执行程序，目标名保持为 c_，仅包含你要运行的 list_self.cpp
add_executable(c_
        1-text/list_self.cpp
)

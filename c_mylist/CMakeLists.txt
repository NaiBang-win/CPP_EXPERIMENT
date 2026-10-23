cmake_minimum_required(VERSION 4.3)
project(c_mylist)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-finput-charset=UTF-8 -fexec-charset=GBK)

add_executable(c_mylist
        1-text/list_self.cpp)

cmake_minimum_required(VERSION 3.30)
project(OOP_01L)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOP_01L main.cpp
        struct_money.h
        struct_money.cpp
        check_output.cpp
        check_output.h)

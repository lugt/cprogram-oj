cmake_minimum_required(VERSION 3.9)
project(test20180402)

set(CMAKE_CXX_STANDARD 98)

add_executable(test20180402
        main.cpp)

add_executable(ptr
        cls_ptr.h cls_ptr.cpp)

add_executable(acc
        accounts.cpp)
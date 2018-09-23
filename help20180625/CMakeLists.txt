cmake_minimum_required(VERSION 3.10)
project(help20180625)

set(CMAKE_CXX_STANDARD 11)

add_executable(help20180625 main.cpp)

add_executable(mm mm.cpp)

add_executable(stackbracket brackets.cpp)
add_executable(trains trains.cpp)
cmake_minimum_required(VERSION 3.12)
project(20181009)

set(CMAKE_CXX_STANDARD 14)

add_executable(20181009 main.cpp match-repeat.cpp)
add_executable(kmp kmp.cpp)
add_executable(qa qa.cpp)
add_executable(matchpre-suffix matchpre-suffix.cpp)
add_executable(match-repeat match-repeat.cpp)
add_executable(faster faster.cpp)
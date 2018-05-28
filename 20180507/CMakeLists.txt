cmake_minimum_required(VERSION 3.10)
project(20180507)

set(CMAKE_CXX_STANDARD 17)

add_executable(20180507 main.cpp)

add_executable(cmplex complex.cpp)
add_executable(fraction CFraction.cpp)
add_executable(four four.cpp)
add_executable(CMatrix CMatrix.cpp)
cmake_minimum_required(VERSION 3.12)
project(huffman)

set(CMAKE_CXX_STANDARD 98)

add_executable(huffman huffman_encode.cpp)
add_executable(path_integrate path_intergrate.cpp)
add_executable(bitree bitree.cpp)
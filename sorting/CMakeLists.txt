cmake_minimum_required(VERSION 2.3)
project(sorting)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 98)

add_executable(HeapSort HeapSort.cpp)
add_executable(TrieTree TrieTree.cpp)
add_executable(main main.cpp)
add_executable(Web Web.cxx)
add_executable(SealSort SealSort.cpp)
add_executable(Quick QuickSort.cpp)
add_executable(InsertSort InsertSort.cpp)
add_executable(MergeSort MergeSort.cpp)

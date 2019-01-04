cmake_minimum_required(VERSION 3.9)
project(test20180312)

set(CMAKE_CXX_STANDARD 11)

add_executable(test20180312
        main.cpp)
add_executable(dynamic_array        dynamic_array.cpp)
add_executable(some some_what_array_choosing.cpp)
add_executable(snake snake.cpp)
add_executable(stl_list stl_list.cpp)
add_executable(fraction fraction.cpp)
add_executable(CAccount CAccount.cpp)
add_executable(circle circl_and_points_in_classes.cpp)
add_executable(string_similar string_similarity_detect.cpp)
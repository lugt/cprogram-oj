cmake_minimum_required(VERSION 3.9)
project(test20180312)

set(CMAKE_CXX_STANDARD 11)

add_executable(test20180312
        main.cpp
        dynamic_array.cpp
        some_what_array_choosing.cpp
        snake.cpp stl_list.cpp stl_list.h
        fraction.cpp fraction.h
        CAccount.cpp CAccount.h
        circl_and_points_in_classes.cpp
        string_similarity_detect.cpp)
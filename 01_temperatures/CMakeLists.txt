cmake_minimum_required(VERSION 2.8)

project(temperatures)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra")

add_executable(temp_a temp_a.cpp)
add_executable(temp_b temp_b.cpp)

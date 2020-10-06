cmake_minimum_required(VERSION 2.8)

project(Set)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_library(Set set.cpp)
add_executable(set_client set_client.cpp)
target_link_libraries(set_client Set)

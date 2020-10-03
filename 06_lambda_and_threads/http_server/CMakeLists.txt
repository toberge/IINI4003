cmake_minimum_required(VERSION 2.8)

project(http_server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -Wall -Wextra")

find_package(Boost 1.54.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(server server.cpp)
target_link_libraries(server ${Boost_LIBRARIES})

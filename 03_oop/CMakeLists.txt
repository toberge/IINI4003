cmake_minimum_required(VERSION 2.8)

project(03_oop)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

# ------ Oppgave 1 ------
add_library(circle circle.cpp)

# ------ Oppgave 2 ------
add_executable(circle_client circle_client.cpp)
target_link_libraries(circle_client circle)

# ------ Oppgave 3 ------
add_library(commodity commodity.cpp)
add_executable(commodity_client commodity_client.cpp)
target_link_libraries(commodity_client commodity)

# ------ Oppgave 2 ------
add_executable(string_things string_things.cpp)

cmake_minimum_required(VERSION 2.8)

# Dette er oppgave 1, altså
project(vector_demo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(vector_demo vector_demo.cpp)

cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0048 NEW)

# versjonsnummer er strengt tatt ikke nødvendig :)
project(02_pointers VERSION 2.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

# ------ Oppgavene: ------

add_executable(1a_address_printer 1a_address_printer.cpp)
add_executable(1b_modifying_pointers 1b_modifying_pointers.cpp)

add_executable(2_strcpy 2_strcpy.cpp)

add_executable(3_something_wrong 3_something_wrong.cpp)

add_executable(4_syntax 4_syntax.cpp)
add_executable(4_syntax_alt 4_syntax_alt.cpp)

add_executable(5_references 5_references.cpp)

add_executable(6_sums 6_sums.cpp)

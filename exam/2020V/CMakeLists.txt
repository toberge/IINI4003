cmake_minimum_required(VERSION 2.8)

project(2020v)

# Oppgave 1
add_executable(escape_alt escape_alt.cpp)
add_executable(escape_attempt escape_attempt.cpp)

# Oppgave 2
add_executable(animals animals.cpp)

# Oppgave 3
add_executable(threads threads.cpp)
add_executable(threads_fixed threads_fixed.cpp)
target_compile_options(threads_fixed PUBLIC "-std=c++17")

# Oppgave 4
add_executable(currency currency.cpp)

# Oppgave 5
add_executable(stl stl.cpp)

# pthread...
find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
  target_compile_options(threads PUBLIC "-pthread")
  target_compile_options(threads_fixed PUBLIC "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  target_link_libraries(threads "${CMAKE_THREAD_LIBS_INIT}")
  target_link_libraries(threads_fixed "${CMAKE_THREAD_LIBS_INIT}")
endif()

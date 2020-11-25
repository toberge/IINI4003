cmake_minimum_required(VERSION 2.8)

project(2018h)

# Oppgave 1
add_executable(output output.cpp)

# Oppgave 2
add_executable(file file.cpp)

# Oppgave 3
add_executable(threads threads.cpp)

# Oppgave 4
add_executable(one_two one_two.cpp)

# Oppgave 5
add_executable(stl stl.cpp)

# pthread...
find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
  target_compile_options(threads PUBLIC "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  target_link_libraries(threads "${CMAKE_THREAD_LIBS_INIT}")
endif()


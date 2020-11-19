cmake_minimum_required(VERSION 2.8)

project(2019h)

# Oppgave 1
add_executable(swap swap.cpp)

# Oppgave 2
add_executable(degrees degrees.cpp)

# Oppgave 3
add_executable(threads threads.cpp)
add_executable(threads_fixed threads_fixed.cpp)

# Oppgave 4
add_executable(car car.cpp)

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


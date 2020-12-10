cmake_minimum_required(VERSION 2.8)

project(exam)

# Oppgave 1
add_executable(spaces spaces.cpp)

# Oppgave 2
add_executable(butikk butikk.cpp)

# Oppgave 3
add_executable(threads threads.cpp)

# Oppgave 4
add_executable(rgb rgb.cpp)

# Oppgave 5
add_executable(pipes pipes.cpp)

# pthread...
find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
  target_compile_options(threads PUBLIC "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  target_link_libraries(threads "${CMAKE_THREAD_LIBS_INIT}")
endif()


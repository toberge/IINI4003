# aww shucks, let's just use teacher's cmake file

cmake_minimum_required(VERSION 2.8)

project(name_concatenator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra -Wno-unused-parameter")

INCLUDE(FindPkgConfig)

if(APPLE)
  set(ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:/usr/local/lib/pkgconfig:/opt/X11/lib/pkgconfig:/usr/local/Cellar/libffi/3.2.1/lib/pkgconfig:/usr/local/Cellar/libsigc++@2/2.10.2/lib/pkgconfig")
endif()

pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(name_concatenator main.cpp)
target_link_libraries(name_concatenator ${GTKMM_LIBRARIES})

cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 20)
project(pv_cost)

set(SOURCE_EXE main.cpp)

include_directories(library)
add_executable(pv_cost ${SOURCE_EXE})
add_subdirectory(library)

find_library(pv_library ./library)

target_link_libraries(pv_cost pv_library)

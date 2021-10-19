cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)

set(SRC_FILES simple_interest.cpp input_manager.cpp compound_interest.cpp)

add_library(pv_library ${SRC_FILES})

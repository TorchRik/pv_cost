cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)

set(SRC_FILES calc_pv_value.cpp calc_ytm.cpp input_manager.cpp interests.h)

add_library(pv_library ${SRC_FILES})

find_library(pv_library ../library)

add_executable(tests tests.cpp)
target_link_libraries(tests pv_library)
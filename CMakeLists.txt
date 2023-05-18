# project
cmake_minimum_required(VERSION 3.13.0)
project(hybrid_programming)
set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

# C++/Python extensions part
add_subdirectory(src/hybrid_example)

# code testing part
if(BUILD_TEST)
    add_subdirectory(test)
endif()
# project
cmake_minimum_required(VERSION 3.13.0)
project(hybrid_programming_test)
set(CMAKE_CXX_STANDARD 17)

# add package: pybind11
find_package (Python3 COMPONENTS Interpreter Development)
execute_process(
    COMMAND "${Python3_EXECUTABLE}" -c
            "import pybind11; print(pybind11.get_cmake_dir())"
    OUTPUT_VARIABLE pybind11_dir
    OUTPUT_STRIP_TRAILING_WHITESPACE COMMAND_ECHO STDOUT)
find_package(pybind11 CONFIG REQUIRED PATHS ${pybind11_dir})

# add package: Catch2
add_subdirectory(lib/Catch2)

# target
add_executable(test test.cpp)

if(NOT SKBUILD)
    find_package (Python3 COMPONENTS Interpreter Development)
endif()

# add package: pybind11
execute_process(
        COMMAND "${Python3_EXECUTABLE}" -c
        "import pybind11; print(pybind11.get_cmake_dir())"
        OUTPUT_VARIABLE pybind11_dir
        OUTPUT_STRIP_TRAILING_WHITESPACE COMMAND_ECHO STDOUT)
find_package(pybind11 CONFIG REQUIRED PATHS ${pybind11_dir})

# target
pybind11_add_module(example_cpp_lib example_export.cpp)

install(TARGETS example_cpp_lib DESTINATION .)
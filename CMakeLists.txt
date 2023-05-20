# project
cmake_minimum_required(VERSION 3.13.0)
project(hybrid_programming LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include_directories(${CMAKE_SOURCE_DIR}/include)

# C++/Python extensions part
add_subdirectory(src/hybrid_example)

# code testing part
option(BUILD_TEST "Builds the testing executable." OFF)
option(CODE_COVERAGE "Collect coverage." OFF)
if(BUILD_TEST)
    if(CODE_COVERAGE)
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 --coverage" )
        SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage" )
        include(CodeCoverage)
        append_coverage_compiler_flags()
    endif()

    add_subdirectory(test)

    if(CODE_COVERAGE)
        setup_target_for_coverage_gcovr_xml(
                NAME coverage
                EXECUTABLE ./bin/test
        )
    endif()

    add_test(NAME project-tests COMMAND ./bin/test)
endif()
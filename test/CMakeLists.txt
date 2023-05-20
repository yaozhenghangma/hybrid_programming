set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# add package: Catch2
add_subdirectory(lib/Catch2)

# target
add_executable(test test.cpp)
target_link_libraries(test PRIVATE Catch2::Catch2WithMain)
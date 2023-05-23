# Set Up Programming Environment in VSCode and CLion

## CLion
### IntelliSense
Setting up an intellisense environment is straightforward in CLion. Normally, a correct `CMakeLists.txt` is sufficient.
However, in the [example `CMakeLists.txt`](https://github.com/yaozhenghangma/hybrid_programming/blob/main/CMakeLists.txt), the project is divided into
two parts, the main program and the code testing part. The testing part is compiled only when an option named
`BUILD_TEST` is enabled, as demonstrated in the following:
```cmake
if(BUILD_TEST)
    add_subdirectory(test)
endif()
```
In this condition, the option `BUILD_TEST` need to be switched on in CLion's CMake profile.
According to [official documents](https://www.jetbrains.com/help/clion/cmake-profile.html),
we can achieve this by adding `-DBUILD_TEST=ON` to CMake options in CLion's CMake setting panel. This ensures
that intellisense for codes of testing part works correctly.

## VSCode
To efficiently configure the programming environment in VSCode, we recommend installing the following three extensions:
- `C/C++ Extension Pack`
- `C/C++ TestMate`
- `Python`

### IntelliSense
In VSCode, we can configure the C++ project similar to CLion by leveraging CMake. In additional to use the same `CMakeLists.txt` file as in CLion, we also need configure the CMake args in VSCode settings. Similarly, we can include `-DBUILD_TEST=ON` option in `CMake: Configure Args` panel within VSCode settings. After that, the CMake tools will try to build the project to `build` directory after each modification made to `CMakeLists.txt`, which will be used to enable intellisense. And we can build the project manually using build command provided by `CMake Tools`.

### Test and Debug
Since we use Catch2 framework to test our C++ code, the extension `C/C++ TestMate` can help us to detect and run testing, and the executable files will be shown in VSCode's `test` panel automatically. The debug process can be triggered in this panel.
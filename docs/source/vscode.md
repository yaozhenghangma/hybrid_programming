# Set Up Programming Environment in VSCode

## IntelliSense

The IntelliSense of C++ and Python is supported through C/C++ extension and Python extension provided by Microsoft. After installing these extensions, custom include paths need to be configured in the C/C++ extension to ensure the correct identification of header files. An example of settings file can be found at [.vscode/c_cpp_properties.json](https://github.com/yaozhenghangma/hybrid_programming/tree/main/.vscode/c_cpp_properties.json), where the header files provided by Python and pybind11 should be specified:
```json
"includePath": [
    "${workspaceFolder}/**",
    "/usr/local/Cellar/python@3.11/3.11.3/Frameworks/Python.framework/Versions/3.11/include/python3.11/",
    "/usr/local/lib/python3.11/site-packages/pybind11/include/"
]
```
This example is specific to Python v3.11 installed via [HomeBrew](https://brew.sh) on a Macintosh system. The second path in the example represents the location of header files provided by Python, e.g. `Python.h`. The third path corresponds to the location of header files provided by pybind11, e.g. `pybind11/pybind11.h`.
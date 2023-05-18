# Compilation with Scikit-Build
Scikit-Build is building system generator based on Python's setpuptools system and C++'s Cmake system. With Scikit-Build toolkit, we can compile C++/Python hybrid libraries automatically. The minimum requirements of Scikit-Build include three files: `setup.py`, `pyproject.toml` and `CMakeLists.txt`.

## `setup.py`
`setup.py` is config file used by Python's setuptools. It consists of basic information about the project. To activate Sckikit-Build tools, the `setup` function must be overloaded by function provided by Scikit-Build in `setup.py`:
```python
from skbuild import setup
```
An example of `setup.py` can be found [here](https://github.com/yaozhenghangma/hybrid_programming/blob/main/setup.py). The additional options in `setup.py` are listed on [Scikit-Build's website](https://scikit-build.readthedocs.io/en/latest/usage.html#setup-options) and [Python's document](https://docs.python.org/3/distutils/setupscript.html).

## `pyproject.toml`
`pyproject.toml` is the specified file format of [PEP 518](https://peps.python.org/pep-0518/), which contains the dependencies of the project. A detailed description of `pyproject.toml` can be found in [pip's document](https://pip.pypa.io/en/stable/reference/build-system/pyproject-toml/). Here, we only utilize a simplified yet practical version that is suitable for most scenarios:
```toml
[build-system]
requires = [
    "setuptools>=42",
    "cmake>=3.13",
    "scikit-build>=0.14.1",
    "pybind11>=2.9.2",
]

build-backend = "setuptools.build_meta"
```

## `CMakeLists.txt`
`CMakeLists.txt` file contains building options of CMake. To correctly build a pybind11 project, the location of pybind11 must be provided to CMake:
```txt
# add package: pybind11
execute_process(
    COMMAND "${Python3_EXECUTABLE}" -c
            "import pybind11; print(pybind11.get_cmake_dir())"
    OUTPUT_VARIABLE pybind11_dir
    OUTPUT_STRIP_TRAILING_WHITESPACE COMMAND_ECHO STDOUT)
find_package(pybind11 CONFIG REQUIRED PATHS ${pybind11_dir})
```
To compile a C++ source code into a shared library, we can use the following commands:
```txt
pybind11_add_module(example_cpp_lib src/example_lib/example.cpp)

install(TARGETS example_cpp_lib DESTINATION .)
```
The `pybind11_add_module` command will compile `example.cpp` file into shared library named `example_cpp_lib`. And when the project is packaged by Python, `install` command will place the library in the root directory of the project.
This example `CMakeLists.txt` can be found [here](https://github.com/yaozhenghangma/hybrid_programming/blob/main/CMakeLists.txt).

## Building
Once these three things are prepared correctly. In root directory of the project, we can utilize commands provided by setuptools to build the package.
```bash
python3 setup.py build
python3 setup.py install
```
The command `build` will build and package the project into a directory named `_skbuild`, and `install` command will copy the packaged project to site-packages directory of Python.
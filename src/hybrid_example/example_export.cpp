#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "example.hpp"

namespace py = pybind11;

PYBIND11_MODULE(example_cpp_lib, m) {
    py::class_<my_vector>(m, "c_vector")
        .def_readwrite("vector", &my_vector::vector)
        .def(py::init<double, double>())
        .def("function", &my_vector::function);
}

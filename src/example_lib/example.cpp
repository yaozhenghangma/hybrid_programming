#ifndef EXAMPLE
#define EXAMPLE

#include <vector>
#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

class PYBIND11_EXPORT embedded_vector {
    public:
    std::vector<double> vector;
    double function(){
        for(int i=0; i<size(this->vector); i++) {
            std::cout << this->vector[i] << std::endl;
        }
        return 1.0;
    }
};

PYBIND11_MODULE(example_cpp_lib, m) {
    py::class_<embedded_vector>(m, "c_vector")
        .def_readwrite("vector", &embedded_vector::vector)
        .def(py::init<>())
        .def("function", &embedded_vector::function);
}

#endif
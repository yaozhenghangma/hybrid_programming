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

    embedded_vector(double element1, double element2) {
        this->vector.push_back(element1);
        this->vector.push_back(element2);
    }

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
        .def(py::init<double, double>())
        .def("function", &embedded_vector::function);
}

#endif
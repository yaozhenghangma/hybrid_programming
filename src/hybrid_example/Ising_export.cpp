#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "Ising.hpp"

namespace py = pybind11;

PYBIND11_MODULE(Ising_lib, m) {
    py::class_<MonteCarlo>(m, "MonteCarlo")
        .def_readwrite("num_flip", &MonteCarlo::num_flip)
        .def_readwrite("num_relax", &MonteCarlo::num_relax)
        .def_readwrite("num_count", &MonteCarlo::num_count)
        .def_readwrite("energy", &MonteCarlo::energy)
        .def_readwrite("Cv", &MonteCarlo::Cv)
        .def_property("J", &MonteCarlo::GetJ, &MonteCarlo::SetJ)
        .def_property("T", &MonteCarlo::GetT, &MonteCarlo::SetT)
        .def(py::init<double, int, int>())
        .def("Run", &MonteCarlo::Run);
}
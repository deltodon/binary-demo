#include <pybind11/pybind11.h>
#include <pybind11/stl.h>  // For std::vector conversions
#include "binary-demo.h"   // Include the binary-demo header

int add(int i, int j) {
  return i + j;
}

std::string hello_from_bin() { return "Hello from binary-demo!"; }

namespace py = pybind11;

PYBIND11_MODULE(_core, m) {
  m.doc() = R"pbdoc(
      Pybind11 example plugin
      -----------------------

      .. currentmodule:: binary_demo

      .. autosummary::
        :toctree: _generate

        hello_from_bin
        add
        subtract
  )pbdoc";

  m.def("hello_from_bin", &hello_from_bin, R"pbdoc(
      A function that returns a Hello string.
  )pbdoc");

  m.def("add", &add, R"pbdoc(
      Add two numbers

      Some other explanation about the add function.
  )pbdoc");

  m.def("subtract", [](int i, int j) { return i - j; }, R"pbdoc(
      Subtract two numbers

      Some other explanation about the subtract function.
  )pbdoc");
  
  // Add bindings for binary-demo functions
  m.def("binary_demo_hello", &binary_demo_hello, R"pbdoc(
      Prints information about the build environment.
  )pbdoc");
  
  m.def("binary_demo_print_vector", &binary_demo_print_vector, R"pbdoc(
      Prints each string in the provided vector.
      
      Args:
          strings: A list of strings to print
  )pbdoc");
}

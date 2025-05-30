#include <pybind11/pybind11.h>

int add(int i, int j) {
  return i + j;
}

std::string hello_from_bin() { return "Hello from binary-demo!"; }

namespace py = pybind11;

PYBIND11_MODULE(_core, m) {
  m.doc() = R"pbdoc(
      Pybind11 example plugin
      -----------------------

      .. currentmodule:: scikit_build_example

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

}

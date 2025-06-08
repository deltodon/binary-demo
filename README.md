# Binary Demo

A C++ library with Python bindings using pybind11 and Conan.

## Project Overview

This project demonstrates how to create a C++ library that:
- Can be built and consumed as a standalone static C++ library using Conan
- Can be built as a Python extension module using pybind11
- Uses scikit-build-core-conan as the build backend for Python packaging

### Setup

install conan dependencies

```bash
make .venv profile
```

Conan will try to detect the configuration of your development machine and save it in

```
./.conan2/profiles/default
```

If you make changes to your machine, i.e. install new compiler, and you would like to re-create the existing profile, you can run

```basg
make profile
```

### Build

build locally Relase package

```basg
make build
```

Create and test the C++ project

```bash
make create
```

## Installation

- clone this repository
- `pip install ./binary_demo`

## CI Examples

There are examples for CI in `.github/workflows`. A simple way to produces
binary "wheels" for all platforms is illustrated in the "wheels.yml" file, using
[`cibuildwheel`][].

## Test call

```python
import binary_demo

binary_demo.add(1, 2)
```

[`cibuildwheel`]: https://cibuildwheel.readthedocs.io


## Features

- C++ library with basic functionality
- Python bindings via pybind11
- Conan package management
- scikit-build-core-conan for seamless Python/C++ integration

## Requirements

- CMake 3.15+
- C++ compiler with C++11 support
- Python 3.12+
- Conan 2.17.0+

## Building as a C++ Library with Conan

```bash
# Install dependencies and generate build files
conan install . --build=missing

# Build the library
conan build .
```

## Building as a Python Package

```bash
# Install the package in development mode
pip install -e .

# Or build a wheel
pip wheel .
```

## Usage

### C++ Usage

```cpp
#include "binary-demo.h"
#include <vector>
#include <string>

int main() {
    // Use the library
    binary_demo();
    
    std::vector<std::string> messages = {"Hello", "World"};
    binary_demo_print_vector(messages);
    
    return 0;
}
```

### Python Usage

```python
import binary_demo

# Use the Python bindings
result = binary_demo.hello_from_bin()
print(result)  # Outputs: "Hello from binary-demo!"
```

## Project Structure

- `include/` - C++ header files
- `src/` - C++ source files and Python module code
- `test_package/` - Conan test package
- `CMakeLists.txt` - CMake build configuration
- `conanfile.py` - Conan package recipe
- `pyproject.toml` - Python package configuration

## License

[Add your license information here]

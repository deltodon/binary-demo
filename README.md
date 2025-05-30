# Binary Demo

An example project built with [pybind11](https://github.com/pybind/pybind11) and
scikit-build-core. Python 3.8+ (see older commits for older versions of Python).



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

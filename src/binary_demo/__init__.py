import importlib.metadata

from binary_demo._core import (
    __doc__,
    hello_from_bin,
    add,
    subtract
)

# Retrieve the version from package metadata (pyproject.toml)
try:
    __version__ = importlib.metadata.version("binary-demo")
except importlib.metadata.PackageNotFoundError:
    __version__ = "unknown"

__all__ = [
    "__doc__",
    "__version__",
    "add",
    "subtract"
]


def hello() -> str:
    return hello_from_bin()

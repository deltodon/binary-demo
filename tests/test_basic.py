from __future__ import annotations

import binary_demo as m


def test_version():
    assert m.__version__ == "0.1.0"


def test_add():
    assert m.add(1, 2) == 3


def test_sub():
    assert m.subtract(1, 2) == -1

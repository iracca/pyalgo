
import pyalgos
import pytest


def test_countDict_works():
    dic = pyalgos.countDict([1,1,1,2,2,3,2,1,2,3,4])
    assert dic == {1:4, 2:4, 3:2, 4:1}


def test_counter_works():
    dic = pyalgos.counter(["s", "s", "s", "a", "a", "b", "a"])
    assert dic == {"s": 3, "a": 3, "b": 1}


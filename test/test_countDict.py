
import pyalgos
import pytest


def test_countintdict_works():
    dic = pyalgos.countintdict([1,1,1,2,2,3,2,1,2,3,4])
    assert dic == {1:4, 2:4, 3:2, 4:1}


def test_countstrdict_works():
    dic = pyalgos.countstrdict(["a", "b", "c", "abc", "abc", "b", "c", "abc"])
    assert dic == {"a": 1, "b": 2, "c": 2, "abc": 3}

def test_counter_works():
    dic = pyalgos.counter(["s", "s", "s", "a", "a", "b", "a"])
    assert dic == {"s": 3, "a": 3, "b": 1}


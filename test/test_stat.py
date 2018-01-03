import pytest
import pyalgos


def test_pyalgos_stddev_works():
    lis = [10, 30, 40, 50, 20]
    assert pyalgos.stddev(lis) == pytest.approx(14.1, 0.01)


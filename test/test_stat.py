import pytest
import pyalgos


@pytest.fixture
def dummy_lis():
    return [10, 30, 40, 50, 20]


def test_pyalgos_stddev_works(dummy_lis):
    assert pyalgos.stddev(dummy_lis) == pytest.approx(14.1, 0.01)


def test_pyalgos_variance_works(dummy_lis):
    assert pyalgos.variance(dummy_lis) == pytest.approx(200.0, 0.01)


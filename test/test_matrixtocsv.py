import pyalgos
import pytest


def test_matrix_to_csv():
    lis = [[1,2,3], ("2", "3", "4")]
    header = ["first", "second", "third"]
    _csv = pyalgos.matrixtocsv(lis, header=header, quotechar="'")
    assert _csv == "'first','second','third'\n'1','2','3'\n'2','3','4'"


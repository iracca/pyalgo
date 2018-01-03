import pyalgos
from collections import Counter
import random
import math


def generate_list():
    return [random.randint(1, 1000) for i in range(1000)]


def generate_matrix():
    return [generate_list() for i in range(1000)]


def generate_header():
    return [str(i) for i in range(1000)]


def test_default_methods_to_csv(matrix, header):
    head = '"' + '","'.join(header) + '"'
    csv = "\n".join(['"' + '","'.join(str(i) for i in row) + '"' for row in matrix])
    return head + '\n' + csv


def test_matrixtocsv_cpp(matrix, header):
    return pyalgos.matrixtocsv(matrix, header=header)


def test_default_dict(lis):
    dic = {}
    for item in lis:
        dic[item] = dic.get(item, 0) + 1
    return dic


def test_ordinary_method(lis):
    dic = {}
    for item in lis:
        if item in dic:
            dic[item] += 1
        else:
            dic[item] = 1
    return dic


def test_countintdict_cpp(lis):
    return pyalgos.countintdict(lis)


def test_counter_cpp(lis):
    return pyalgos.counter(lis)


def test_Counter(lis):
    return Counter(lis)


def __py_stddev(lis):
    _sum = sum(lis)
    size = float(len(lis))
    mean = _sum / size
    variance = sum(math.pow(abs(i - mean),  2) for i in lis) / size
    return math.sqrt(variance)


def test_stddev_function(lis):
    return __py_stddev(lis)


def test_stddev_cpp(lis):
    return pyalgos.stddev(lis)


if __name__ == "__main__":
    import timeit
    # print "test_default_dict:\t", timeit.timeit("test_default_dict(lis)", setup="from __main__ import generate_list, test_default_dict; lis = generate_list()", number=1000)
    # print "test_ordinary_method:\t", timeit.timeit("test_ordinary_method(lis)", setup="from __main__ import generate_list, test_ordinary_method; lis = generate_list()", number=1000)
    print "test_countintdict_cpp:\t", timeit.timeit("test_countintdict_cpp(lis)", setup="from __main__ import generate_list, test_countintdict_cpp; lis = generate_list()", number=1000)
    # print "test_counter_cpp:\t", timeit.timeit("test_counter_cpp(lis)", setup="from __main__ import generate_list, test_counter_cpp; lis = generate_list()", number=1000)
    # print "test_Counter:\t", timeit.timeit("test_Counter(lis)", setup="from __main__ import generate_list, test_Counter; lis = generate_list()", number=1000)
    # print "test_default_methods_to_csv:\t", timeit.timeit("test_default_methods_to_csv(matrix, header)", setup="from __main__ import generate_matrix, generate_header, test_default_methods_to_csv; matrix = generate_matrix(); header=generate_header()", number=100)
    # print "test_matrixtocsv_cpp:\t", timeit.timeit("test_matrixtocsv_cpp(matrix, header)", setup="from __main__ import generate_matrix, generate_header, test_matrixtocsv_cpp; matrix = generate_matrix(); header=generate_header()", number=100)
    print "test_stddev_function:\t", timeit.timeit("test_stddev_function(lis)", setup="from __main__ import generate_list, test_stddev_function; lis = generate_list()", number=1000)
    print "test_stddev_cpp:\t", timeit.timeit("test_stddev_cpp(lis)", setup="from __main__ import generate_list, test_stddev_cpp; lis = generate_list()", number=1000)


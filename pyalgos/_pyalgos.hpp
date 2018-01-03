#ifndef PYALGOS_H
#define PYALGOS_H

#include <Python.h>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include <string>
#include <cstring>
#include <cmath>
#include <numeric>

void _append_header(const std::string& csv, PyObject * header, char * quotechar, char * delimiter);

double _variance(const std::vector<long>& arr);

template<class T>
std::unordered_map<T, int> countdict(const std::vector<T>& arr);

void countUp(std::unordered_map<PyObject *, int>&dic, PyObject * value);

std::vector<long> getVectorFromIntList(PyObject * self, PyObject * args);

PyObject * pyalgos_buildcsv(PyObject * self, PyObject * args, PyObject * kw);

PyObject * pyalgos_countintdict(PyObject* self, PyObject* args);

PyObject * pyalgos_countstrdict(PyObject * self, PyObject * args);

PyObject * pyalgos_counter(PyObject* self, PyObject * args);

PyObject * pyalgos_stddev(PyObject * self, PyObject * args);

PyObject * pyalgos_variance(PyObject * self, PyObject * args);

#endif

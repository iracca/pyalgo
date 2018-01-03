#ifndef PYALGOS_H
#define PYALGOS_H

#include <Python.h>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include <string>
#include <cstring>

void _append_header(const std::string& csv, PyObject * header, char * quotechar, char * delimiter);

PyObject * pyalgos_buildcsv(PyObject * self, PyObject * args, PyObject * kw);

PyObject* pyalgos_countDict(PyObject* self, PyObject* args);

PyObject * pyalgos_counter(PyObject* self, PyObject * args);

#endif

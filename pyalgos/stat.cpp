#include "_pyalgos.hpp"


double _variance(const std::vector<long>& arr) {
    long sum = std::accumulate(arr.begin(), arr.end(), 0);
    double arrsize = static_cast<double>(arr.size());
    double mean = sum / arrsize;
    double up = 0.0;
    for (int i = 0; i < arr.size(); ++i) {
        up += std::pow(std::abs(static_cast<double>(arr[i]) - mean), 2);
    }
    return up / arrsize;
}


std::vector<long> getVectorFromIntList(PyObject * self, PyObject * args) {
    std::vector<long> arr;
    PyObject * arr_obj;

    if (!PyArg_ParseTuple(args, "O", &arr_obj)) {
        throw std::logic_error("couldn't parse the function argument");
    }

    if (PyTuple_Check(arr_obj)) {
        for (Py_ssize_t i = 0; i < PyTuple_Size(arr_obj); ++i) {
            PyObject * value = PyTuple_GetItem(arr_obj, i);
            arr.push_back(PyLong_AsLong(value));
        }
    } else if (PyList_Check(arr_obj)) {
        for (Py_ssize_t i = 0; i < PyList_Size(arr_obj); ++i) {
            PyObject * value = PyList_GetItem(arr_obj, i);
            arr.push_back(PyLong_AsLong(value));
        }
    }
    return arr;
}


PyObject * pyalgos_variance(PyObject * self, PyObject * args) {
    double vari = _variance(getVectorFromIntList(self, args));

    PyObject * ret;
    ret = PyFloat_FromDouble(vari);
    return ret;
}


PyObject * pyalgos_stddev(PyObject * self, PyObject * args) {
    double stdv = std::sqrt(_variance(getVectorFromIntList(self, args)));

    PyObject * ret;
    ret = PyFloat_FromDouble(stdv);
    return ret;
}



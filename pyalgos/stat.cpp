#include "_pyalgos.hpp"


double _stddev(const std::vector<long>& arr) {
    long sum = std::accumulate(arr.begin(), arr.end(), 0);
    double arrsize = static_cast<double>(arr.size());
    double mean = sum / arrsize;
    double up = 0.0;
    for (int i = 0; i < arr.size(); ++i) {
        up += std::pow(std::abs(static_cast<double>(arr[i]) - mean), 2);
    }
    return std::sqrt(up / arrsize);
}


PyObject * pyalgos_stddev(PyObject * self, PyObject * args) {
    std::vector<long> arr;
    PyObject * arr_obj;

    if (!PyArg_ParseTuple(args, "O", &arr_obj)) return NULL;

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

    double stdv = _stddev(arr);

    PyObject * ret;
    ret = PyFloat_FromDouble(stdv);
    return ret;
}


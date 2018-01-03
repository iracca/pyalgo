#include "_pyalgos.hpp"

template<class T>
std::unordered_map<T, int> countdict(const std::vector<T>& arr) {
    std::unordered_map<T, int> dic;
    for (auto itr = arr.begin(); itr != arr.end(); ++itr) {
        auto dicitr = dic.find(*itr);
        if (dicitr == dic.end()) {
            dic[*itr] = 1;
        } else {
            dicitr->second++;
        }
    }
    return dic;
}


// std::unordered_map<int, int> countDict(const std::vector<int>& arr) {
//     std::unordered_map<int, int> dic;
//     for (std::vector<int>::const_iterator itr = arr.begin(); itr != arr.end(); ++itr) {
//         std::unordered_map<int, int>::iterator dicitr = dic.find(*itr);
//         if (dicitr == dic.end()) {
//             dic[*itr] = 1;
//         } else {
//             dicitr->second++;
//         }
//     }
//     return dic;
// }


PyObject* pyalgos_countintdict(PyObject* self, PyObject* args) {
    std::vector<int> arr;
    PyObject *arr_obj;

    if (!PyArg_ParseTuple(args, "O", &arr_obj)) return NULL;

    if(PyTuple_Check(arr_obj)) {
        for (Py_ssize_t i = 0; i < PyTuple_Size(arr_obj); ++i) {
            PyObject *value = PyTuple_GetItem(arr_obj, i);
            arr.push_back(PyLong_AsLong(value));
        }
    } else if (PyList_Check(arr_obj)) {
        for (Py_ssize_t i = 0; i < PyList_Size(arr_obj); ++i) {
            PyObject *value = PyList_GetItem(arr_obj, i);
            arr.push_back(PyLong_AsLong(value));
        }
    } else {
        throw std::logic_error("Passed PyObject pointer was not a list or tuple!");
    }

    std::unordered_map<int, int> dic = countdict(arr);

    PyObject *d = PyDict_New();
    for (auto itr = dic.begin(); itr != dic.end(); ++itr) {
        PyObject* key;
        PyObject* value;
        key = PyInt_FromLong(itr->first);
        value = PyInt_FromLong(itr->second);
        PyDict_SetItem(d, key, value);
    }

    return d;
}


PyObject * pyalgos_countstrdict(PyObject * self, PyObject * args) {
    std::vector<std::string> arr;
    PyObject * arr_obj;

    if (!PyArg_ParseTuple(args, "O", &arr_obj)) return NULL;

    if (PyTuple_Check(arr_obj)) {
        for (Py_ssize_t i = 0; i < PyTuple_Size(arr_obj); ++i) {
            PyObject * value = PyTuple_GetItem(arr_obj, i);
            arr.push_back(PyString_AsString(value));
        }
    } else if (PyList_Check(arr_obj)) {
        for (Py_ssize_t i = 0; i < PyList_Size(arr_obj); ++i) {
            PyObject * value = PyList_GetItem(arr_obj, i);
            arr.push_back(PyString_AsString(value));
        }
    } else {
        throw std::logic_error("Passed PyObject pointer was not a list or tuple");
    }
    std::unordered_map<std::string, int> dic = countdict(arr);
    PyObject * d = PyDict_New();
    for (auto itr = dic.begin(); itr != dic.end(); ++itr) {
        PyObject * key;
        PyObject * value;
        key = PyString_FromString(itr->first.c_str());
        value = PyInt_FromLong(itr->second);
        PyDict_SetItem(d, key, value);
    }

    return d;
}


namespace std {
template<>
struct hash<PyObject*> {
    std::size_t operator() (PyObject * key) const {
        return PyObject_Hash(key);
    }
};
}


void countUp(std::unordered_map<PyObject*, int>& dic, PyObject * value) {
    auto itr = dic.find(value);
    if (itr == dic.end()) {
        dic[value] = 1;
    } else {
        itr->second++;
    }
}


PyObject * pyalgos_counter(PyObject* self, PyObject * args) {
    std::vector<int> arr;
    PyObject *arr_obj;

    if (!PyArg_ParseTuple(args, "O", &arr_obj)) return NULL;

    std::unordered_map<PyObject*, int> dic;
    if(PyTuple_Check(arr_obj)) {
        for (Py_ssize_t i = 0; i < PyTuple_Size(arr_obj); ++i) {
            PyObject *value = PyTuple_GetItem(arr_obj, i);
            countUp(dic, value);
        }
    } else if (PyList_Check(arr_obj)) {
        for (Py_ssize_t i = 0; i < PyList_Size(arr_obj); ++i) {
            PyObject *value = PyList_GetItem(arr_obj, i);
            countUp(dic, value);
        }
    } else {
        throw std::logic_error("Passed PyObject pointer was not a list or tuple!");
    }

    PyObject * d = PyDict_New();
    for (auto itr = dic.begin(); itr != dic.end(); ++itr) {
        PyObject * value = PyInt_FromLong(itr->second);
        PyDict_SetItem(d, itr->first, value);
    }

    return d;
}

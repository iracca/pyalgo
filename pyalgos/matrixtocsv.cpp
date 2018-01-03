#include "_pyalgos.hpp"


void _append_header(std::string& csv, PyObject * header, const char * quotechar, const char * delimiter) {
    bool isTup;
    if (PyTuple_Check(header)) {
        isTup = true;
    } else if (PyList_Check(header)) {
        isTup = false;
    } else {
        throw std::logic_error("header has to be of type tuple or list");
    }

    Py_ssize_t itersize = isTup ? PyTuple_Size(header) : PyList_Size(header);

    for (Py_ssize_t i = 0; i < itersize; ++i) {
        PyObject * value = isTup ? PyTuple_GetItem(header, i) : PyList_GetItem(header, i);
        char * s;
        if (PyString_Check(value)) {
            s = PyString_AsString(value);
        } else {
            PyObject * objRepr = PyObject_Repr(value);
            s = PyString_AsString(objRepr);
        }
        csv.append(quotechar);
        csv.append(s);
        csv.append(quotechar);
        if (i != itersize - 1) {
            csv.append(delimiter);
        }
    }
    csv.append("\n");
}


PyObject * pyalgos_buildcsv(PyObject * self, PyObject * args, PyObject * kw) {
    std::string csv;

    PyObject * pyobj;
    PyObject * header = NULL;
    PyObject * quotestr = NULL;
    PyObject * delimiterstr = NULL;
    const char * quotechar = "";
    const char * delimiter = ",";

    static char * kwlist[] = { "matrix", "header", "quotechar", "delimiter" };

    if (!PyArg_ParseTupleAndKeywords(args, kw, "O|OSS", kwlist, &pyobj, &header, &quotestr, &delimiterstr)) {
        return NULL;
    }

    if (quotestr != NULL) {
        quotechar = PyString_AsString(quotestr);
    }
    if (delimiterstr != NULL) {
        delimiter = PyString_AsString(delimiterstr);
    }
    // if (quotestr.length() != 1 || delimiterstr.length() != 1) {
    //     throw std::logic_error("quotechar or delimiter has to be of length 1");
    // } else {
    //     quotechar = quotestr[0];
    //     delimiter = delimiterstr[0];
    // }

    bool isMatrixTup;
    if (PyTuple_Check(pyobj)) { isMatrixTup = true; } 
    else if (PyList_Check(pyobj)) { isMatrixTup = false; } 
    else { std::logic_error("matrix has to be of type tuple or list"); }

    if (header != NULL) {
        _append_header(csv, header, quotechar, delimiter);
    }


    Py_ssize_t rownum = isMatrixTup ? PyTuple_Size(pyobj) : PyList_Size(pyobj);

    for (Py_ssize_t i = 0; i < rownum; ++i) {
        PyObject * lis = isMatrixTup ? PyTuple_GetItem(pyobj, i) : PyList_GetItem(pyobj, i);

        bool isRowTup;
        if (PyTuple_Check(lis)) { isRowTup = true; } 
        else if (PyList_Check(lis)) { isRowTup = false; } 
        else { std::logic_error("row has to be of type tuple or list"); }

        Py_ssize_t colsize = isRowTup ? PyTuple_Size(lis) : PyList_Size(lis);

        for (Py_ssize_t j = 0; j < colsize; ++j) {
            csv.append(quotechar);
            PyObject * item = isRowTup ? PyTuple_GetItem(lis, j) : PyList_GetItem(lis, j);
            char * s;
            if (PyString_Check(item)) {
                s = PyString_AsString(item);
            } else {
                PyObject * objRepr = PyObject_Repr(item);
                s = PyString_AsString(objRepr);
            }
            csv.append(s);
            csv.append(quotechar);
            if (j != colsize - 1) {
                csv.append(delimiter);
            }
        }
        if (i != rownum - 1) {
            csv.append("\n");
        }
    }
    PyObject * ret = Py_BuildValue("s", csv.c_str());
    return ret;
}


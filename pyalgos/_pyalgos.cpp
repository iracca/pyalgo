#include "_pyalgos.hpp"

static char module_docstring[] =
    "module to speed up common task for my job";

static char countintdict_docstring[] =
    "int dict count function";

static char countstrdict_docstring[] =
    "str dict count function";

static char counter_docstring[] =
    "counter for generic hashable object";

static char matrixtocsv_docstring[] =
    "matrix to csv string";

static char stddev_docstring[] =
    "standard deviation function, which only accepts list or tuple of integers";

static PyMethodDef module_methods[] = {
    {"countintdict", (PyCFunction)pyalgos_countintdict, METH_VARARGS, countintdict_docstring},
    {"countstrdict", (PyCFunction)pyalgos_countstrdict, METH_VARARGS, countstrdict_docstring},
    {"matrixtocsv", (PyCFunction)pyalgos_buildcsv, METH_VARARGS | METH_KEYWORDS, matrixtocsv_docstring},
    {"counter", (PyCFunction)pyalgos_counter, METH_VARARGS, counter_docstring},
    {"stddev", (PyCFunction)pyalgos_stddev, METH_VARARGS, stddev_docstring},
    {NULL, NULL, 0, NULL},
};

PyMODINIT_FUNC initpyalgos(void) {
    PyObject *m = Py_InitModule3("pyalgos", module_methods, module_docstring);
    if (m == NULL) return;
}


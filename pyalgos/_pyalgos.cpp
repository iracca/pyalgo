#include "_pyalgos.hpp"

static char module_docstring[] =
    "module to speed up common task for my job";

static char countdict_docstring[] =
    "int dict count function";

static char counter_docstring[] =
    "counter for generic hashable object";

static char matrixtocsv_docstring[] =
    "matrix to csv string";

static PyMethodDef module_methods[] = {
    {"countDict", (PyCFunction)pyalgos_countDict, METH_VARARGS, countdict_docstring},
    {"matrixtocsv", (PyCFunction)pyalgos_buildcsv, METH_VARARGS | METH_KEYWORDS, matrixtocsv_docstring},
    {"counter", (PyCFunction)pyalgos_counter, METH_VARARGS, counter_docstring},
    {NULL, NULL, 0, NULL},
};

PyMODINIT_FUNC initpyalgos(void) {
    PyObject *m = Py_InitModule3("pyalgos", module_methods, module_docstring);
    if (m == NULL) return;
}


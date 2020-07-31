#include <Python.h>

static PyObject *method_run() {
	printf("VforVendetta is a proper ****\n");
	return PyLong_FromLong(1);
}

static PyMethodDef vanajMethods[] = {
    {"run", method_run, METH_VARARGS, "Python interface for Nikki Vanaj"},
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef vanajmodule = {
    PyModuleDef_HEAD_INIT,
    "vanaj",
    "Python interface for vanaj",
    -1,
    vanajMethods
};

PyMODINIT_FUNC PyInit_vanaj(void) {
	return PyModule_Create(&vanajmodule);
}
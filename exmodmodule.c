#define PY_SSIZE_T_CLEAN
#include <Python.h>

// Reference
// https://www.youtube.com/watch?v=s6cvSkbWG3s

static PyObject *exmodError = NULL;

static PyObject* exmod_say_hello(PyObject* self, PyObject *args){
	const char* msg;
	int sts = 0;

	// We expect at least 1 string argument to this function
	// This will move an "s" string from "args" into "msg"
	if (!PyArg_ParseTuple(args, "s", &msg)) {
		/*
		Formats:
		s (const char *)
		b (unsigned char)
		h (short int)
		i (int)
		l (long)
		d (double)
		O (PyObject *)
		*/
		
		// Returning NULL raises an exception
		return NULL;
	}

	// Example error, check if input string is a certain value
	if (strcmp(msg, "this_is_an_error") == 0) 
	{
		PyErr_SetString(exmodError, "This is a test exception after typing an expected invalid response");
		return NULL;
	} 
	else 
	{
		printf("This is C world\nYour message is: %s \n", msg);
		sts = 21;
	}


	// Return value just in case, if nothing is returned, it may crash
	// the python interpreter
	return Py_BuildValue("i", sts);
}

static PyObject *exmod_add(PyObject *self, PyObject *args) {
	double a, b;
	double sts = 0;

	if (!PyArg_ParseTuple(args, "dd", &a, &b)) {
		return NULL; // Return error if required arguments aren't passed
	}

	sts = a + b;
	printf("This is C world\n Addition of %f + %f = %f", a, b, sts);
	return Py_BuildValue("d", sts);
}

static PyMethodDef exmod_methods[] = {
	//Python Name  C Function Name  Argument presentation  description
	{"say_hello", exmod_say_hello, METH_VARARGS, "Say hello from C and print message"},
	{"add"      , exmod_add      , METH_VARARGS, "Add two number in C"},
	{NULL, NULL, 0, NULL} /*Tell interpreter that this is the end of the definition*/ 
};

static struct PyModuleDef exmodmodule = {
    PyModuleDef_HEAD_INIT,
    "exmod",
    "Python interface for testing some commands",
    -1,
    exmod_methods
};

// Initialization function, will be run when building & Importing
PyMODINIT_FUNC PyInit_exmod(void) {
	// Initialize reference fputsmodule
	PyObject *module = PyModule_Create(&exmodmodule);

	// Create an error for this module
	exmodError = PyErr_NewException("exmod.error", NULL, NULL); // "exmod.error" python error object
	
	// Register error object
	PyModule_AddObject(module, "error", exmodError);
	return module;
}


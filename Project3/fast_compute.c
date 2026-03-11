#define PY_SSIZE_T_CLEAN
#include <Python.h>

// The C function that does the heavy lifting
static PyObject* sum_of_squares(PyObject* self, PyObject* args) {
    PyObject* list_obj;
    
    // Parse the incoming Python argument as an Object (O)
    if (!PyArg_ParseTuple(args, "O", &list_obj)) {
        return NULL; // Return error if parsing fails
    }
    
    long long sum = 0;
    Py_ssize_t size = PyList_Size(list_obj);
    
    // Loop through the list using C's native speed
    for (Py_ssize_t i = 0; i < size; i++) {
        PyObject* item = PyList_GetItem(list_obj, i);
        long long val = PyLong_AsLongLong(item);
        sum += val * val;
    }
    
    // Convert the C long long back into a Python integer object
    return PyLong_FromLongLong(sum);
}

// Define the methods this module will expose to Python
static PyMethodDef FastMethods[] = {
    {"sum_of_squares", sum_of_squares, METH_VARARGS, "Calculate the sum of squares of a list."},
    {NULL, NULL, 0, NULL}
};

// Define the module structure
static struct PyModuleDef fastmodule = {
    PyModuleDef_HEAD_INIT,
    "fast_compute",   // Name of the module
    "A C extension for fast math.", // Module documentation
    -1,
    FastMethods
};

// Initialization function called when Python imports the module
PyMODINIT_FUNC PyInit_fast_compute(void) {
    return PyModule_Create(&fastmodule);
}

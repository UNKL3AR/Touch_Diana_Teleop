// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from sri_interface:msg/SixAxisFTS.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "sri_interface/msg/detail/six_axis_fts__struct.h"
#include "sri_interface/msg/detail/six_axis_fts__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool sri_interface__msg__six_axis_fts__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[43];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("sri_interface.msg._six_axis_fts.SixAxisFTS", full_classname_dest, 42) == 0);
  }
  sri_interface__msg__SixAxisFTS * ros_message = _ros_message;
  {  // x_force
    PyObject * field = PyObject_GetAttrString(_pymsg, "x_force");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x_force = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y_force
    PyObject * field = PyObject_GetAttrString(_pymsg, "y_force");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y_force = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // z_force
    PyObject * field = PyObject_GetAttrString(_pymsg, "z_force");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->z_force = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // x_torque
    PyObject * field = PyObject_GetAttrString(_pymsg, "x_torque");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x_torque = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y_torque
    PyObject * field = PyObject_GetAttrString(_pymsg, "y_torque");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y_torque = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // z_torque
    PyObject * field = PyObject_GetAttrString(_pymsg, "z_torque");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->z_torque = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // frame_number
    PyObject * field = PyObject_GetAttrString(_pymsg, "frame_number");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->frame_number = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // sampling_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "sampling_time");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->sampling_time = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * sri_interface__msg__six_axis_fts__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SixAxisFTS */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("sri_interface.msg._six_axis_fts");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SixAxisFTS");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  sri_interface__msg__SixAxisFTS * ros_message = (sri_interface__msg__SixAxisFTS *)raw_ros_message;
  {  // x_force
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x_force);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x_force", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y_force
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y_force);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y_force", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // z_force
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->z_force);
    {
      int rc = PyObject_SetAttrString(_pymessage, "z_force", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // x_torque
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x_torque);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x_torque", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y_torque
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y_torque);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y_torque", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // z_torque
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->z_torque);
    {
      int rc = PyObject_SetAttrString(_pymessage, "z_torque", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // frame_number
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->frame_number);
    {
      int rc = PyObject_SetAttrString(_pymessage, "frame_number", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sampling_time
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->sampling_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sampling_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

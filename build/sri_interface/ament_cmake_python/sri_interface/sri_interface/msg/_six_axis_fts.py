# generated from rosidl_generator_py/resource/_idl.py.em
# with input from sri_interface:msg/SixAxisFTS.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SixAxisFTS(type):
    """Metaclass of message 'SixAxisFTS'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('sri_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'sri_interface.msg.SixAxisFTS')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__six_axis_fts
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__six_axis_fts
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__six_axis_fts
            cls._TYPE_SUPPORT = module.type_support_msg__msg__six_axis_fts
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__six_axis_fts

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SixAxisFTS(metaclass=Metaclass_SixAxisFTS):
    """Message class 'SixAxisFTS'."""

    __slots__ = [
        '_x_force',
        '_y_force',
        '_z_force',
        '_x_torque',
        '_y_torque',
        '_z_torque',
        '_frame_number',
        '_sampling_time',
    ]

    _fields_and_field_types = {
        'x_force': 'float',
        'y_force': 'float',
        'z_force': 'float',
        'x_torque': 'float',
        'y_torque': 'float',
        'z_torque': 'float',
        'frame_number': 'uint16',
        'sampling_time': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.x_force = kwargs.get('x_force', float())
        self.y_force = kwargs.get('y_force', float())
        self.z_force = kwargs.get('z_force', float())
        self.x_torque = kwargs.get('x_torque', float())
        self.y_torque = kwargs.get('y_torque', float())
        self.z_torque = kwargs.get('z_torque', float())
        self.frame_number = kwargs.get('frame_number', int())
        self.sampling_time = kwargs.get('sampling_time', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.x_force != other.x_force:
            return False
        if self.y_force != other.y_force:
            return False
        if self.z_force != other.z_force:
            return False
        if self.x_torque != other.x_torque:
            return False
        if self.y_torque != other.y_torque:
            return False
        if self.z_torque != other.z_torque:
            return False
        if self.frame_number != other.frame_number:
            return False
        if self.sampling_time != other.sampling_time:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def x_force(self):
        """Message field 'x_force'."""
        return self._x_force

    @x_force.setter
    def x_force(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x_force' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'x_force' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._x_force = value

    @builtins.property
    def y_force(self):
        """Message field 'y_force'."""
        return self._y_force

    @y_force.setter
    def y_force(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y_force' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'y_force' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._y_force = value

    @builtins.property
    def z_force(self):
        """Message field 'z_force'."""
        return self._z_force

    @z_force.setter
    def z_force(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'z_force' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'z_force' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._z_force = value

    @builtins.property
    def x_torque(self):
        """Message field 'x_torque'."""
        return self._x_torque

    @x_torque.setter
    def x_torque(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x_torque' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'x_torque' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._x_torque = value

    @builtins.property
    def y_torque(self):
        """Message field 'y_torque'."""
        return self._y_torque

    @y_torque.setter
    def y_torque(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y_torque' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'y_torque' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._y_torque = value

    @builtins.property
    def z_torque(self):
        """Message field 'z_torque'."""
        return self._z_torque

    @z_torque.setter
    def z_torque(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'z_torque' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'z_torque' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._z_torque = value

    @builtins.property
    def frame_number(self):
        """Message field 'frame_number'."""
        return self._frame_number

    @frame_number.setter
    def frame_number(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'frame_number' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'frame_number' field must be an unsigned integer in [0, 65535]"
        self._frame_number = value

    @builtins.property
    def sampling_time(self):
        """Message field 'sampling_time'."""
        return self._sampling_time

    @sampling_time.setter
    def sampling_time(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'sampling_time' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'sampling_time' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._sampling_time = value

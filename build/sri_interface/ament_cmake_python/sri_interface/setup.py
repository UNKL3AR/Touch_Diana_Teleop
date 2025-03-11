from setuptools import find_packages
from setuptools import setup

setup(
    name='sri_interface',
    version='0.0.0',
    packages=find_packages(
        include=('sri_interface', 'sri_interface.*')),
)

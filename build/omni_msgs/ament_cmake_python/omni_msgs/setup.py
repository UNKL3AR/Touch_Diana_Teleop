from setuptools import find_packages
from setuptools import setup

setup(
    name='omni_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('omni_msgs', 'omni_msgs.*')),
)

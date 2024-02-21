
# from math import sin, cos, tan  # standard libs
import sys
import math

import numpy  # 3rd party libs
import scipy
import scipy.integrate

# local libs

print(dir(math))
# print(help(math.tan))

# print(help(numpy))

print("Below follows the methods of numpy \n ", dir(numpy))
# print(help(numpy.polydiv))


print("Below follows the methods of scipy \n ", dir(scipy))
# print(help(scipy))
print(help(scipy.integrate.quad))

func = lambda x: x**2 + x + 2
geek = scipy.integrate.quad(func, 0, 10)
print(geek)

print(sys.path)  # Shows where python searches for packages

print(numpy.__file__)  # shows where python finds numpy

sys.path.append(r'C:/Users/tomca/PycharmProjects/pythonProject2/')
from function import a_function  # imports "a_function" from a project "pythonProject2". \
# Normally you keep them in the same project, this is just a bad example.
print(a_function())

print(sys.path)  # Shows where python searches for packages

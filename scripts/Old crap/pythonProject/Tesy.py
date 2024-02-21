import time

import numpy as np
import matplotlib.pyplot as plt

numbers = [0]
def counter():
    numbers.append(numbers[-1] + 1)
    print(numbers)


def weirdo():
    if numbers[-1] % 10 == 0:
        print("{} reached".format(numbers[-1]))

while True:
    counter()
    weirdo()
    time.sleep(1)

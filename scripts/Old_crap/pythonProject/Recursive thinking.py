import numpy as np
import matplotlib.pyplot as plt

houses = ["Eric's house", "Yo mamas house", "Kodo's house", "Luigi's house"]


def deliver_presents_iteratively():
    for x in houses:
        # if x == "Yo mamas house":
        # continue
        print("deliver presents to", x)


print(deliver_presents_iteratively())


# Let Santas helpers deliver the presents in his stead.

# Each function call represents an elf doing his work
def deliver_presents_recursively(houses):
    # Worker elf doing his work
    if len(houses) == 1:
        house = houses[0]
        print("Delivering presents to", house)
    # Manager elf doing his work
    # the floor division // rounds the result down to the nearest whole number
    else:
        mid = len(houses) // 2
        first_half = houses[:mid]
        second_half = houses[mid:]
        # Divides his work among two elves
        deliver_presents_recursively(first_half)
        deliver_presents_recursively(second_half)


print(deliver_presents_recursively(houses))


################################################

def factorial_recursive(n):
    if n == 1:
        return 1
    else:
        return n * factorial_recursive(n - 1)  # here it becomes like a loop that starts over until its n=1
    # leading to if n = 5 ----> 5*4*3*2*1 = 120


print(factorial_recursive(1))
print(factorial_recursive(2))
print(factorial_recursive(3))
print(factorial_recursive(4))
print(factorial_recursive(5))


def plus_one(n):
    if n > 10:
        return 0
    else:
        return n + plus_one(n + 1)


print(plus_one(1))
print(plus_one(2))  # 2+3+
print(plus_one(3))
print(plus_one(7))
print(plus_one(9))


def a_function(z):
    if z >= 12:
        return 12
    elif 8 >= z >= 3:
        return z + a_function(z + 1)
    else:
        return 0


print(a_function(20))
print(a_function(6))


def mathematica_formula(c):
    if 5 >= c >= 2:
        return (2 * c**2 + c + 5) + mathematica_formula(c - 1)
    else:
        return 0


print(mathematica_formula(1))
print(mathematica_formula(2))
print(mathematica_formula(3))
print(mathematica_formula(4))

#plt.hist(mathematica_formula(3))
#plt.show()

x = np.linspace(-np.pi, np.pi, 100)
y = np.sin(x)
z = np.cos(x)

fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)
ax.spines['left'].set_position('center')
ax.spines['bottom'].set_position('center')
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')
ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')

plt.plot(x, y, 'b', label='y=sin(x)')
plt.plot(x, 2 * y, 'c', label='y=2sin(x)')
plt.plot(x, 3 * y, 'r', label='y=3sin(x)')
plt.plot(x, z, 'g', label='y=cos(x)')

plt.legend(loc='upper left')
plt.show()

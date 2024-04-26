
for letter in ['c', 'a', 't']:
    print(letter)

print(letter)

for some_numbers in range(0, 8):
    print(some_numbers)

animals = ["cat", "dog", "bird"]
for index in range(len(animals)):
    print(index, animals[index])

for index, value in enumerate(animals):
    print(index, value)

numbers = [3, 5, 9, -1, 3, 1]
result = 1
for item in numbers:
    if item < 0:
        break
    result += item
print(result)

numbers_1 = [3, 5, 9, -1, 3, 1]
result_1 = 0
for numba in numbers_1:
    if numba < 0:
        continue
    result_1 = result_1 + numba
print(result_1)

print("bird" in animals)
print(animals.index("bird"))

names = ["ringo", "john", "paul", "george"]
print(names)
names_to_remove = []
for name in names:
    if name not in ["john", "paul"]:
        names_to_remove.append(name)
print(names)

for name in names_to_remove:
    names.remove(name)

print(names)

a_string = "hi, i have a big ass"
print("ass" in a_string)
print(a_string)

n = 3
while n > 0:
    print(n)
    n = n - 1

# info = dict(first='pete', last='best')
info = {'first': 'Pete', 'last': 'Best'}
print(info)

info['age'] = 20
info['occupation'] = 'Drummer'

print(info)
print(info['age'])
print('band' in info)
print('occupation' in info)

data = {'adam': 2, 'Zeek': 5, 'fred': 3}
for name in data:
    print(name)

for value in data.values():
    print(value)

for key, value in data.items():
    print(key, value)

for name in sorted(data.keys()):
    print(name)

for name in sorted(data.keys(), reverse=True):
    print(name)

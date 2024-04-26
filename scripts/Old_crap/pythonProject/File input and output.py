#  import numpy
#  print(help(numpy))
#  print(help(open))

created_in_python = open(r'C:\Users\tomca\PycharmProjects\pythonProject\created_from_python', 'w')
#  r is used to prevent py to make a 'tab' from \t   (\tomca)

created_in_python_3 = open(r'C:\Users\tomca\PycharmProjects\pythonProject\created_in_python_3.text', 'w')

open_in_python = open(r'C:\Users\tomca\PycharmProjects\pythonProject\created_in_windows.txt', 'r')
print(open_in_python.readline())
print(open_in_python.readline(20))
print(open_in_python.readline(5))
print(open_in_python.readline())
print(open_in_python.readline())
print(open_in_python.readline(6))
open_in_python.close()

open_in_python = open(r'C:\Users\tomca\PycharmProjects\pythonProject\created_in_windows.txt', 'r')
print(open_in_python.read())
#  open_in_python = open(r'C:\Users\tomca\PycharmProjects\pythonProject\created_in_windows.txt', 'rb')
print(open_in_python.read())  # needs to be loaded again before this works
print(open_in_python.close())

passwd_file = open(r'C:\Users\tomca\PycharmProjects\pythonProject\passwd', 'rb')
print(passwd_file.read())
print(passwd_file.close())

open_in_python = open(r'C:\Users\tomca\PycharmProjects\pythonProject\created_in_windows.txt', 'r')
for b in open_in_python.readline():
    print("yepp")
print(open_in_python.close())

open_in_python = open(r'C:\Users\tomca\PycharmProjects\pythonProject\created_in_windows.txt', 'r')
for b in open_in_python:
    print("yokidoki")
print(open_in_python.close())

# Skip open and close steps
with open(r'C:\Users\tomca\PycharmProjects\pythonProject\created_in_windows.txt', 'r') as open_in_python:
    print(open_in_python.readline(3))


def add_numbers():
    results = []
    with open(r'C:\Users\tomca\PycharmProjects\pythonProject\created_in_windows.txt', 'r') as fin:
        for num, line in enumerate(fin):
            results.append('{0}-{1}'.format(num, line))
    return results


# A better less messy solution

def add_numbers_2():
    with open(r'C:\Users\tomca\PycharmProjects\pythonProject\created_in_windows.txt', 'r') as fin_2:
        return add_nums_to_seq(fin_2)


def add_nums_to_seq(seq):
    results = []
    for num, line in enumerate(seq):
        results.append('{0}-{1}'.format(num, line))
    return results


print(add_numbers_2())

print(add_numbers())

print(input('did it work?'))

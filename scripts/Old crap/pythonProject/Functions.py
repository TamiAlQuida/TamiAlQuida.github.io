
def add_2(num):
    '''
    return 2 more than num
    '''
    result = num + 2
    return result

print(help(add_2))

print(add_2(5))

x = 2
def scope_demo():
    y =4
    print("Local: {}".format(y))
    print("Global: {}".format(x))
    print("Built-in: {}".format(dir))

scope_demo()

# print(y) will not work

def __dir__(x):
    print("Dir called")

print(__dir__(''))

def foo():
    x = 1
    return locals()

print(foo())

def add_n(num, n = 3):
    return num + n
print(add_n(2))
print(add_n(2, 2))

def to_list(value, default = []):
    default.append(value)
    return default

print(to_list(5))
print(to_list("baby"))

def to_list_2(value, default = None):
    if default is None:
        default = []
    default.append(value)
    return default

print(to_list_2(3))
print(to_list_2("howdy"))

def is_odd(value):
    if value % 2 == 0:
        return False
    else:
        return True

print(is_odd(6))

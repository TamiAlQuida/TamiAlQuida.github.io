
def divide():
    """below is a way to go around the error you'd get if you would divide by 0"""
    input_1 = int(input('give me something to divide'))
    input_2 = int(input('how many times do you want to divide it?'))
    if input_2 != 0:
        result = input_1 / input_2
    else:
        result = "Not allowed to divide by zero!"
    return print(result)

def division():
    """below is an other way to go around the error you'd get if you would divide by 0"""
    input_3 = int(input('give me something else to divide'))
    input_4 = int(input('how many times again?'))
    try:
        result = input_3 / input_4
    except ZeroDivisionError as e:  # as e is optional, only needed to access the instance of it.
        result = None
    return print(result)


while True:
    divide()
    division()


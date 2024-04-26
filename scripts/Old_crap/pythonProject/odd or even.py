numba = int(input("tell me a number"))
if numba % 2 == 0:
    print("Yepp that's even")
else:
    print("nope that's odd")

names = ["Matt", "Olle", "Pauline", "Svante"]
print(names[2])
names[2] = "Pallan"
print(names[2])
names.append("Palle")
print(names[4])
names.append("923")
names.append("654")
names_sorted = sorted(names)
print(names_sorted)
print(names)
nums = range(2, 10, 2)
print(list(nums))
print(nums)

lite_namn = [1, 1, 2, 3, 3, 5, 6, 7]
print(lite_namn)
lite_namn_index = len(lite_namn)
lite_namn_summa = sum(lite_namn)
lite_namn_set = set(lite_namn)
lite_namn_avg = lite_namn_summa / lite_namn_index
print(type(lite_namn_avg))
print(lite_namn_index)
print(lite_namn_summa)
print(lite_namn_set)
print(lite_namn_avg)

print(7 in lite_namn_set)
print(5 in lite_namn_set)
print(10 in lite_namn_set)

digit_set = set(range(0, 10))
print(digit_set)
odd = {1, 3, 5, 7, 9}

print(3 in digit_set)

even = digit_set - odd
print(even)

prime = {2, 3, 5, 7}

prime_even = prime & even
print(prime_even)

numbers = odd | even
print(numbers)

print(numbers == digit_set)
print(numbers is digit_set)

in_one = prime ^ even # ^ = Xor which means exists only in one of them
in_one2 = prime ^ odd
print(in_one)
print(in_one2)



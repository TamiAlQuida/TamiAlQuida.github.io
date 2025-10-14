my_pets = ["dog", "cat", "bird", "horse", "donkey"]  # a list

print(my_pets[-1])  # index backwards
print(my_pets[0:2])  # pulls out the two first items
print(my_pets[1:4])  # Slicing
print(my_pets[-3:-1])  # Slicing
print(my_pets[0:4])  # Slicing
print(my_pets)  # Slicing
print(my_pets[:])  # Slicing
zero_three_six = [0, 1, 2, 3, 4, 5, 6][::3]  # slicing with strides
print(zero_three_six)
negative_strides = [0, 1, 2, 3, 4, 5, 6][5:0:-2]  # slicing with strides
print(negative_strides)
print(my_pets[0:5:2])  # Slicing
print("esreveR"[::-1])  # reverse
print("esreveR"[4::-1])  # reverse

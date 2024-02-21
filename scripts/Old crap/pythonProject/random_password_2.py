
import random

alpha = "qwertyuiopåasdfghjklöäzxcvbnmQWERTYUIOPÅASDFGHJKLÖÄZXCVBNM"
num = "1234567890"
special = '''!"#¤%&/()=?`'''
all = alpha + num + special
print(all)

alpha_len = 6
num_len = 3
special_len = 3
password_len = alpha_len + num_len + special_len

print("Attempt 1")

password = "".join(random.sample(alpha, alpha_len) + random.sample(num, num_len) + random.sample(special, special_len))

print(password)

print("Attempt 2")

password_2 = [1, 2]

print(password_2)

for letters in range(0, 12):
    if len(password_2) < 12:
        password_2.append(random.sample(all, 1))

print(password_2)

print("Attempt 3")

def function_random_3():
    print(random.sample(all, 12))

print(function_random_3())

print("Attempt 4")

print(random.sample(all, 12))

print("Attempt 5")

# random_password_5 = ''.join(random.sample(all, 12)) ---> print(random_password_5)
random_password_5 = random.sample(all, 12)
random_password_5_joint = ''.join(random_password_5)
# random_password_5 = ''.join(random.sample(all, 12)) ---> print(random_password_5)
print(random_password_5)
print(random_password_5_joint)


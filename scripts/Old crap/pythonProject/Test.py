import time
import numpy as np
import matplotlib.pyplot as plt


class SkiChair:
    """Attempt at making a ski chair"""
    max_occupants = 3

    def __init__(self, id):
        self.id = id
        self.count = 0

    def load(self, number):
        self.count += number

    def unload(self, number):
        self.count -= number


ids_of_all_chairs = []
for i in range(1, 21):
    ids_of_all_chairs.append(i)

list_of_class_chairs = []
for i in ids_of_all_chairs:
    list_of_class_chairs.append(SkiChair(i))

print(ids_of_all_chairs)

def movement_of_all_chairs():
    list_of_class_chairs[0].load(np.random.randint(0, SkiChair.max_occupants + 1))
    list_of_class_chairs[10].unload(list_of_class_chairs[10].count)
    list_of_class_chairs.append(list_of_class_chairs.pop(0))
    print(list_of_class_chairs[-1].__dict__)


def summation_of_all_passengers():
    print("total amount of people in the chairs:", sum(i.count for i in list_of_class_chairs[0:-1]))


while_count = 0
total_ammount_of_passengers = []
while True:

    while_count += 1
    print(while_count)
    movement_of_all_chairs()
    summation_of_all_passengers()
    total_ammount_of_passengers.append(sum(i.count for i in list_of_class_chairs[0:-1]))
    if while_count == 1000:
        break

x_data = []
for i in range(1, len(total_ammount_of_passengers) + 1):
    x_data.append(i)

plt.plot(x_data, total_ammount_of_passengers)
plt.show()

average_amount_of_people = np.average(total_ammount_of_passengers)
standard_deviation = np.std(total_ammount_of_passengers)
print("avg:", average_amount_of_people, "std:", standard_deviation)

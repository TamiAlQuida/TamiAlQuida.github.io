import random
import time


class Chair:
    """ A Chair on a chairlift """
    max_occupants = 4

    def __init__(self, id):  # The constructor a method(function) in classes, creates attributes
        self.id = id
        self.count = 0

    def load(self, number):
        self.count += number

    def unload(self, number):
        self.count -= number


print(Chair)
print(dir(Chair))
print(Chair.max_occupants)
print(Chair.__class__)
print(Chair.max_occupants.__class__)
print(Chair.__init__.__class__)
print(Chair.load.__class__)
print(Chair.unload.__class__)
print(help(Chair))

chair = Chair(21)  # chair number 21
print(chair)
print(chair.count)
print(chair.id)
print(chair.max_occupants)  # Under the covers Python is doing this: chair.__class__.max_occupants

chair.load(3)  # def load(self, number) the function will use whatever is in front of the dot, \
# in this case chair,  as self and in will insert whatever is in the (), in this case 3, as number. \
# This is what happens under the covers, Chair.load(chair, 3)
print(chair.count)

print(dir(chair))

print(chair.__dict__)  # Dictionary a way to look up attributes. {'id': 21, 'count': 3}

print(chair.__class__)

print(chair.__module__)

print(chair.__doc__)


class CorrectChair:
    """A chair on a chair lift"""  # 3 " for a comment that can be called with CorrectChair.__doc__
    max_occupants = 4

    def __init__(self, id):
        self.id = id
        self.count = 0

    def load(self, number):
        new_val = self._check(self.count + number)  # ._check the underscore is there to signal that \
        # you should not call publicly
        self.count = new_val

    def unload(self, number):
        new_val = self._check(self.count - number)
        self.count = new_val

    def _check(self, number):
        if number < 0 or number > self.max_occupants:
            raise ValueError('invalid count:{}'.format(number))
        return number


NUM_CHAIRS = 100
chairs = []
# for i in range(1, NUM_CHAIRS +1):
# chairs.append(i)
# print(chairs)
# chairs.clear()
# print(chairs)
for i in range(1, NUM_CHAIRS + 1):
    chairs.append(CorrectChair(i))


print(chairs[3].__dict__)  # {'id': 4, 'count': 0}
print(chairs[4].id)
print(chairs[4].count)


def avg(chairs):
    total = 0
    for c in chairs:
        total += c.count
    return total / len(chairs)


in_use = []
transported = 0
while True:  # Kind of a loop forever
    # loading
    loading = chairs.pop(0)  # pops out item 1 in list chairs
    in_use.append(loading)
    in_use[-1].load(random.randint(0, CorrectChair.max_occupants))

    # unloading
    if len(in_use) > NUM_CHAIRS / 2:
        unloading = in_use.pop(0)
        transported += unloading.count
        unloading.unload(unloading.count)
        chairs.append(unloading)
    print('Loading Chair {} Count:{} Avg:{:.2} Total:{}'.format(loading.id, loading.count,
                                                                avg(in_use), transported))
    time.sleep(1)

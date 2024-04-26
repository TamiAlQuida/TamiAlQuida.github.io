
import random

def ten_percent(number, chair):
    """return True 10% of time"""
    return random.random() < .1

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


chairs = []
chair = CorrectChair(1)
chair.load(3)
print(chair.__dict__)
# chair2 = CorrectChair(2)
# chair2.load(5)
# print(chair2.__dict__)

class Chair6(CorrectChair):
    max_occupants = 6  # subclass, that overrides the max occupants


chair2 = Chair6(2)
chair2.load(5)
print(chair2.__dict__)
print(Chair6.__bases__)

class StallChair(CorrectChair):
    def __init__(self, id, is_stalled):
        super().__init__(id)
        self.is_stalled = is_stalled
        self.stalls = 0

    def load(self, number):
        if self.is_stalled(number, self):
            self.stalls += 1
        super().load(number)  # super refers bak up to the load function in CorrectChair


stall_42 = StallChair(42, ten_percent)
print(stall_42.__dict__)

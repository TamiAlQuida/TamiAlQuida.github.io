
class cars():
    """a class that stores model, year and color."""
    def __init__(self, model, year, color):
        self.model = model
        self.year = year
        self.color = color

    def show(self):
        print(self.__dict__)
    
tesla = cars("s", 2020, "yellow")
tesla.show()

print(tesla.__doc__)
print(tesla.color)

num = tesla.year + 1
print(num)

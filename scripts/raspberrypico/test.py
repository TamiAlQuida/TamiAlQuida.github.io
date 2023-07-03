
#dict_cars = {'model':[], 'year':[], 'color':[]}
list_cars = []

class cars():
    """A class that stores model, year and color."""
    def __init__(self, model, year, color):
        self.model = model
        self.year = year
        self.color = color
    
    def add_to_dict(self):
        list_cars.append(self.__dict__)
        #dict_cars['model'].append(self.model)
        #dict_cars['year'].append(self.year)
        #dict_cars['color'].append(self.color)

    def show(self):
        print(list_cars)
        #print(self.__dict__)
    

#Appending
tesla = cars('model s', 2020, 'yellow')
tesla.add_to_dict()
bmw = cars('bmw', 2009, 'yellow')
bmw.add_to_dict()
audi = cars('audi', 2009, 'yellow')
audi.add_to_dict()
toyota = cars('supra', 2009, 'gold')
toyota.add_to_dict()
toyota.show()

#print(list_cars[-1])

#filtering
res = []
for value in list_cars:
    if value['year'] == 2009:
        res.append(value['model'])


print(f'Models that are made in 2009: \n{res}')

res_3 = []
for x in list_cars:
    if x['year'] == 2009 and x['color'] == 'yellow':
        res_3.append(x)

print(f'Complete dictionaries of the cars that contain 2009 and yellow: \n{res_3}')


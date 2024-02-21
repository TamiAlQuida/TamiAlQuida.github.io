import pandas
from sklearn import linear_model

df = pandas.read_csv("cars.csv")

X = df[['Weight', 'Volume']]
y = df['CO2']

regr = linear_model.LinearRegression()
regr.fit(X, y)

# predict the CO2 emission of a car where the weight is 2300kg, and the volume is 1300cm3:
predictedCO2 = regr.predict([[2300, 1300]])

print(predictedCO2)

print("below is the coefficient for weight, volume(how much it affect the CO2 value)")
print(regr.coef_)

print("Below is a car that weigh 3,3ton 1,3 litres")

predictedCO2 = regr.predict([[3300, 1300]])

print(predictedCO2)

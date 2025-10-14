import pandas
from sklearn import linear_model
from sklearn.preprocessing import StandardScaler
scale = StandardScaler()

#  The standardization method uses this formula:
#
# z = (x - u) / s
#
# Where z is the new value, x is the original value, u is the mean and s is the standard deviation.
#
# https://www.w3schools.com/python/python_ml_scale.asp


df = pandas.read_csv("scripts/Old_crap/pythonProject/cars2.csv")
X = df[['Weight', 'Volume']]
y = df['CO2']

scaledX = scale.fit_transform(X)

print(scaledX)

regr = linear_model.LinearRegression()
regr.fit(scaledX, y)

scaled = scale.transform([[2300, 1.3]])

predicted_CO2 = regr.predict([scaled[0]])
print(predicted_CO2)

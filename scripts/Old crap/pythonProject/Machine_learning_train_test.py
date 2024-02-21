
import numpy as np
from sklearn.metrics import r2_score
import matplotlib.pyplot as plt
np.random.seed(2)

x = np.random.normal(3, 1, 100)
y = np.random.normal(150, 40, 100) / x

plt.scatter(x, y)
plt.show()

x_sorted = np.sort(x)
y_sorted = np.sort(y)

plt.hist(x_sorted, 100)
plt.show()
plt.hist(y_sorted, 100)
plt.show()

train_x = x[:80]
train_y = y[:80]

test_x = x[80:]
test_y = y[80:]

plt.scatter(train_x, train_y)
plt.show()

plt.scatter(test_x, test_y)
plt.show()

my_model = np.poly1d(np.polyfit(train_x, train_y, 4))

my_line = np.linspace(0, 6, 100)

plt.scatter(train_x, train_y)
plt.plot(my_line, my_model(my_line))
plt.show()

#  Better newer way to solve it below \

#  Still not sure why it has to be my_model"(my_myline)". But think it has something to do with getting \
#  the same first value, as if it reorders the values in my_model or something.

my_model_2 = np.polynomial.Polynomial.fit(train_x, train_y, 4)
plt.plot(my_line, my_model_2(my_line))
plt.show()

#  R2 score a way to measure how much the curve relates to the dots. 1 = completely 0 = mot at all

r2 = r2_score(train_y, my_model(train_x))

print(r2)

r2_2 = r2_score(train_y, my_model_2(train_x))

print(r2_2)

# Test the model with the values from the testing set

r2_test = r2_score(test_y, my_model_2(test_x))
print(r2_test)

#  predict how much they will spend after 1,2,3,5,6 minutes

values_used_for_prediction = [1, 2, 3, 5, 6]
predicted_values = []

for i in values_used_for_prediction:
    predicted_values.append(my_model_2(i))


print(predicted_values)

plt.plot(my_line, my_model_2(my_line))
plt.scatter(values_used_for_prediction, predicted_values)
plt.show()

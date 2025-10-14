import numpy as np
from scipy import stats
import matplotlib.pyplot as plt
from sklearn.metrics import r2_score

speeds = [99, 86, 87, 88, 111, 86, 103, 87, 94, 78, 77, 85, 86]

avg_speed = np.mean(speeds)
print("average speed is:".capitalize(), avg_speed)

speeds_sorted = sorted(speeds)
print(speeds_sorted)
median_speed = np.median(speeds_sorted)
print("median value is:".capitalize(), median_speed)

most_common_speed = stats.mode(speeds)
print(most_common_speed)

standard_deviation_speed = np.std(speeds)
print("standard deviation is:".capitalize(), standard_deviation_speed)

variance_speed = np.var(speeds)
print("variance speed is:".capitalize(), variance_speed)
# check if the square root of variance really is the same as standard deviation
check = variance_speed ** (1 / 2)
print(check, "it actually seem to work".capitalize())

percentile_speed_80 = np.percentile(speeds, 80)
print(percentile_speed_80, ", 80% drive this fast or slower")

# On to ages

ages = [5, 31, 43, 48, 50, 41, 7, 11, 15, 39, 80, 82, 32, 2, 8, 6, 25, 36, 27, 61, 31]
ages_75_percentile = np.percentile(ages, 75)
print(ages_75_percentile, ", 75% are this old or younger")

# Creating data sets and plotting with matplotlib

fake_data = np.random.uniform(10.0, 20.0, 1500)
# print(fake_data)
plt.hist(fake_data, 100)
plt.show()

# next_plot_of_normal_data_distribution

fake_ages = np.random.normal(45.0, 10.0, 2000)
plt.hist(fake_ages, 100)
plt.show()

# scatter plot

car_ages = [5, 7, 8, 7, 2, 17, 2, 9, 4, 11, 12, 9, 6]
plt.scatter(car_ages, speeds)
plt.show()

random_x = np.random.normal(45.0, 10.0, 1000)
random_y = np.random.normal(45.0, 20.0, 1000)
plt.scatter(random_x, random_y)
plt.show()

# håll i dig, linear regression uses a relationship between variable x and y to draw a straight line

slope, intercept, r, p, std_err = stats.linregress(car_ages, speeds)


def my_func(car_ages):
    return slope * car_ages + intercept


my_model = list(map(my_func, car_ages))
plt.scatter(car_ages, speeds)
plt.plot(car_ages, my_model)
plt.show()

# håll i dig, polynomial regression uses a relationship between variable x and y to draw a straight line

x = [1, 2, 3, 5, 6, 7, 8, 9, 10, 12, 13, 14, 15, 16, 18, 19, 21, 22]
y = [100, 90, 80, 60, 60, 55, 60, 65, 70, 70, 75, 76, 78, 79, 90, 99, 99, 100]

mymodel = np.poly1d(np.polyfit(x, y, 3))
myline = np.linspace(1, 22, 100)

plt.scatter(x, y)
plt.plot(myline, mymodel(myline))
plt.show()

#https://www.w3schools.com/python/python_ml_polynomial_regression.asp
# r_score is a metric that decides how well x and y compare to the mymodel line, it needs to be high \
# when predicting future

print("r2_score:",r2_score(y, mymodel(x)))

# predict future values.

speed = mymodel(17)
print("predicted speed at 17:", speed)

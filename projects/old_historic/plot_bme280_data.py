import pandas as pd
from matplotlib import pyplot as plt

try:
    bme280_plot_data = pd.read_csv('/home/pi/TamiAlQuida.github.io/projects/old_historic/bme280data.csv')         # Linux
except:
    bme280_plot_data = pd.read_csv(r'projects/old_historic/bme280data.csv')  # Windows

# print(bme280_plot_data),

print(bme280_plot_data['Date'])
# print(bme280_plot_data['Date'].loc[bme280_plot_data.index[0]])

# print(bme280_plot_data['Temperature C'])
# print(bme280_plot_data['Pressure hPa'])
# print(bme280_plot_data['Humidity %'].to_string(index=False))

plt.plot(bme280_plot_data['Date'], (bme280_plot_data['Temperature C']))
plt.ylabel('Temperature C')
plt.xlabel('Date')
plt.show()
plt.plot(bme280_plot_data['Date'], (bme280_plot_data['Pressure hPa']))
plt.ylabel('Pressure hPa')
plt.xlabel('Date')
plt.show()
plt.plot(bme280_plot_data['Date'], (bme280_plot_data['Humidity %']))
plt.ylabel('Humidity %')
plt.xlabel('Date')
plt.show()
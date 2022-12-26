import bme280
import smbus2
from time import sleep
import pandas as pd
import datetime

port = 1
address = 0x76 # Adafruit BME280 address. Other BME280s may be different
bus = smbus2.SMBus(port)

def measuring_atmosphere():
    bme280_data = bme280.sample(bus,address)
    ambient_temperature = bme280_data.temperature
    pressure  = bme280_data.pressure
    humidity  = bme280_data.humidity
    date = datetime.datetime.now()
    print(date, f'{ambient_temperature:.4} C, {pressure:.6} hPa, {humidity:.4} %')
    
    df = pd.DataFrame({'Date': [date], 'Temperature C': [ambient_temperature], 'Pressure hPa': [pressure], 'Humidity %': [humidity]})
    df.to_csv('/home/pi/TamiAlQuida.github.io/scripts/bme280data.csv', mode='a', index=False, header=False)


bme280.load_calibration_params(bus,address)

for i in range(0, 10):
    measuring_atmosphere()
    sleep(1)

import plot_bme280_data
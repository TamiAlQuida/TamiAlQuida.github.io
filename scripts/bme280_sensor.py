import bme280
import smbus2
from time import sleep
import pandas as pd
import datetime

port = 1
address = 0x76 # Adafruit BME280 address. Other BME280s may be different
bus = smbus2.SMBus(port)

bme280.load_calibration_params(bus,address)

while True:
    bme280_data = bme280.sample(bus,address)
    ambient_temperature = bme280_data.temperature
    pressure  = bme280_data.pressure
    humidity  = bme280_data.humidity
    print(datetime.datetime.now(), f'{ambient_temperature:.4} C, {pressure:.6} hPa, {humidity:.4} %')
    
    df = pd.DataFrame({'Temperature': [ambient_temperature], 'Pressure': [pressure], 'Humidity': [humidity]})
    df.to_csv('/home/pi/TamiAlQuida.github.io/scripts/bme280data.csv', mode='a', index=False, header=False)
    sleep(1)
import bme280
import smbus2
from time import sleep
import pandas as pd

port = 1
address = 0x76 # Adafruit BME280 address. Other BME280s may be different
bus = smbus2.SMBus(port)

bme280.load_calibration_params(bus,address)

while True:
    bme280_data = bme280.sample(bus,address)
    #bme280_data = bme280.uncompensated_readings()
    humidity  = bme280_data.humidity
    pressure  = bme280_data.pressure
    ambient_temperature = bme280_data.temperature
    print(f'{ambient_temperature:.4} C, {pressure:.6} hpa, {humidity:.4} %')
    
    sleep(1)

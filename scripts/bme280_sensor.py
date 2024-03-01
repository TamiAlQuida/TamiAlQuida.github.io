# There is a service created to autorun this script on start 
# /etc/systemd/system/bme280_sensor.service
# Enabled by command : sudo systemctl enable bme280_sensor.service

import smbus2
import bme280
from time import sleep
import datetime

port = 1
address = 0x76 # BME280 address. (sudo i2cdetect -y 1 to find out)
bus = smbus2.SMBus(port)
action_minute = 0 # execute every whole hour


def measuring_atmosphere():
    for i in range(10): # Check 10 times for acurate results
        bme280_data = bme280.sample(bus,address)
        ambient_temperature = bme280_data.temperature
        pressure  = bme280_data.pressure
        humidity  = bme280_data.humidity
        sleep(1)
    date = str(datetime.datetime.now())
    collected_data = f'{date:.16},{ambient_temperature:.4},{pressure:.6},{humidity:.4} \n'
    print(collected_data)
    with open('bme280data.csv', 'a') as f:
        f.write(collected_data)


calibration_params = bme280.load_calibration_params(bus, address)
measuring_atmosphere()

while True:
    current_minute = datetime.datetime.now().minute
    if current_minute == action_minute:
        measuring_atmosphere()
        sleep(58*60)
    sleep(5)

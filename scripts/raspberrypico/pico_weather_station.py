#import modules
import network
import socket
from time import sleep
from machine import Pin, I2C
import bme280
from datetime import datetime

#constants and variables
led = Pin("LED", Pin.OUT)
SSID = 'Pallans Special'
PASSWORD = '62g2cuhkw'
HOST_IP = '192.168.1.78'  # linuxmint '192.168.1.25'#pc
PORT = 5001

# Initialize BME280 sensor
i2c = I2C(0,sda=Pin(0), scl=Pin(1), freq=400000) #i2c = I2C(scl=Pin(5), sda=Pin(4))
bme = bme280.BME280(i2c=i2c)

action_times = {
    '01:00:00',
    '02:00:00',
    '03:00:00',
    '04:00:00',
    '05:00:00',
    '06:00:00',
    '07:00:00',
    '08:00:00',
    '09:00:00',
    '10:00:00',
    '11:00:00',
    '12:00:00',
    '13:00:00',
    '14:00:00',
    '15:00:00',
    '16:00:00',
    '17:00:00',
    '18:00:00',
    '19:00:00',
    '20:00:00',
    '21:00:00',
    '22:00:00',
    '23:00:00',
    '00:00:00',
}

def connect_wifi():
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.connect(SSID, PASSWORD)
    while not wlan.isconnected():
        print('connecting...')
        sleep(2)
    ip = wlan.ifconfig()[0]
    print(f'Connected to WiFi, on {ip}')
    led.on()
    return wlan

def connect_to_pico():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        s.bind((socket.gethostname(), 5001))  # windows
    except:
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)  # makes it so that you can bind same port in linux after crash
        s.bind(('192.168.1.78', 5001))  # linux mint

    s.listen(0)  # maybe makes it so only 1 can connect, not sure
    clientsocket, address = s.accept()
    print(f'Connection from {address}')
    return s, clientsocket

# Connect to Wi-Fi
wlan = connect_wifi()

while True:
    current_time = datetime.now().strftime("%H:%M:%S")
    if not wlan.isconnected(): #if not connection to wifi
        wlan = connect_wifi()
    
    s = None
    clientsocket = None

    if current_time in action_times:
        # Read BME280 sensor values
        temp = bme.temperature
        pressure = bme.pressure
        humidity = bme.humidity
        reading = 'Temperature: ' + str(temp) + '. Humidity: ' + str(humidity) + '. Pressure: ' + str(pressure)
        print(reading)
        # Append to CSV file
        with open('bme280_data_pico.csv', 'a') as f:
            f.write(datetime.now().strftime("%Y-%m-%d %H:%M:%S") + ',' + str(pressure) + ',' + str(temp) + ',' + str(humidity) + '\n')

    if not s:  # if not connection between pico and a pc
        try:
            s, clientsocket = connect_to_pico()
            # send csv file to host
            with open('bme280_data_pico.csv', 'r') as f:
                csv_data = f.read()
            clientsocket.sendall(csv_data.encode())
            print('CSV file sent to host.')
            # erase data locally.
            with open('bme280_data_pico.csv', 'w') as f:
                f.write('')
            print('Local data erased.')
        except:
            pass

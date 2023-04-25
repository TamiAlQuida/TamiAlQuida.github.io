from machine import Pin
import machine
import network
import socket
import uasyncio as asyncio
import ujson as json
from time import sleep

led = Pin("LED", Pin.OUT)
SSID = 'Pallans Special'
PASSWORD = '62g2cuhkw'
HOST_IP = '192.168.1.25'
PORT = 5001

parameters = []
speed = 0
direction = 0

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


async def handle_data_5001():
    global speed, direction, parameters
    #data1 = s.recv(32)
    data1 = s.recv(5)
    #data2 = json.loads(data1)
    data = data1.decode()
    parameters = data.split()
    #print(data)
    print(parameters)
    if parameters == []:
        quit()

connect_wifi()
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST_IP, PORT))

while True:
    try:
        while True:
            asyncio.run(handle_data_5001())
    
    finally:
        print('turning off')
        led.off()
        wlan = network.WLAN(network.STA_IF)
        wlan.active(True)
        wlan.disconnect()
        break


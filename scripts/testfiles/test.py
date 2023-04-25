#import mip ## new upip
#Import libraries
import network
import socket
from time import sleep
import machine

#constants and variables
ssid = 'Pallans Special'
password = '62g2cuhkw'

#Functions
def move_forward():
    print ("Forward")
    
def move_backward():
    print ("Backward")
    
def move_stop():
    print ("Stop")
    
def move_left():
    print ("Left")
    
def move_right():
    print ("Right")



def connect():
    #connect to WLAN
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.connect(ssid, password)
    while wlan.isconnected() == False:
        print(f'Waiting for connection...')
        sleep(1)
    ip = wlan.ifconfig()[0]
    print(f'Connected on {ip}')
    return ip

def open_socket(ip):
    # Open a socket
    address = (ip, 80)
    connection = socket.socket()
    connection.bind(address)
    connection.listen(1)
    return connection

def webpage():
    #Template HTML
    html = f"""
            <!DOCTYPE html>
            <html>
            <head>
            <title>Zumo Robot Control</title>
            </head>
            <center><b>
            <form action="./forward">
            <input type="submit" value="Forward" style="height:120px; width:120px" />
            </form>
            <table><tr>
            <td><form action="./left">
            <input type="submit" value="Left" style="height:120px; width:120px" />
            </form></td>
            <td><form action="./stop">
            <input type="submit" value="Stop" style="height:120px; width:120px" />
            </form></td>
            <td><form action="./right">
            <input type="submit" value="Right" style="height:120px; width:120px" />
            </form></td>
            </tr></table>
            <form action="./back">
            <input type="submit" value="Back" style="height:120px; width:120px" />
            </form>
            </body>
            </html>
            """
    return str(html)

def serve(connection):
    #Start web server
    while True:
        client = connection.accept()[0]
        request = client.recv(1024)
        request = str(request)
        try:
            request = request.split()[1]
        except IndexError:
            pass
        if request == '/forward?':
            move_forward()
        elif request =='/left?':
            move_left()
        elif request =='/stop?':
            move_stop()
        elif request =='/right?':
            move_right()
        elif request =='/back?':
            move_backward()
        html = webpage()
        client.send(html)
        client.close()

try:
    ip = connect()
    connection = open_socket(ip)
    serve(connection)
except KeyboardInterrupt:
    machine.reset()























#from machine import Pin
#led = Pin("LED", Pin.OUT)
#led.on()
import machine
import network
import usocket as socket
import ujson as json
import uasyncio as asyncio
#import uwebsocket as websocket


SSID = 'Pallans Special'
PASSWORD = '62g2cuhkw'
PORT = 5001

speed = 0
direction = 0


async def connect_wifi():
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.connect(SSID, PASSWORD)
    while not wlan.isconnected():
        print('connecting...')
        await asyncio.sleep_ms(1000)
    ip = wlan.ifconfig()[0]
    print(f'Connected to WiFi, on {ip}')

async def handleData5001(websocket):
    global speed, direction
    while True:
        data = await websocket.recv()
        if data is None:
            break
        data = json.loads(data)
        speed = data.get('speed', speed)
        direction = data.get('direction', direction)
        print(f'Speed: {speed}, Direction: {direction}')


try:
    asyncio.run(connect_wifi())
    asyncio.run(handleData5001(websocket))
except KeyboardInterrupt:
    machine.reset()





# THRE BELOW THIS WORKS!



import socket
import uasyncio as asyncio
import ujson as json

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('192.168.1.25', 5001))

#msg = s.recv(8)
#print(msg)
#print(msg.decode("utf-8"))

data1 = s.recv(8)
data = json.loads(data1)
print(data)











import network
from time import sleep

SSID = 'Pallans Special'
PASSWORD = '62g2cuhkw'
PORT = 5001

speed = 0
direction = 0


def connect_wifi():
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.connect(SSID, PASSWORD)
    while not wlan.isconnected():
        print('connecting...')
        sleep(3)
    ip = wlan.ifconfig()[0]
    print(f'Connected to WiFi, on {ip}')

while True:
    connect_wifi()
    sleep(10)









#from machine import Pin
#led = Pin("LED", Pin.OUT)
#led.on()
import machine
import network
import socket
import uasyncio as asyncio
import ujson as json

SSID = 'Pallans Special'
PASSWORD = '62g2cuhkw'
HOST_IP = '192.168.1.25'
PORT = 5001

speed = 0
direction = 0

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST_IP, PORT))

#msg = s.recv(8)
#print(msg)
#print(msg.decode("utf-8"))

data1 = s.recv(8)
data = json.loads(data1)
print(data)

async def connect_wifi():
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.connect(SSID, PASSWORD)
    while not wlan.isconnected():
        print('connecting...')
        await asyncio.sleep_ms(1000)
    ip = wlan.ifconfig()[0]
    print(f'Connected to WiFi, on {ip}')


async def handle_data_5001():
    global speed, direction
    while True:
        data1 = await s.recv(8)
        data = json.loads(data1)
        print(data)

try:
    asyncio.run(handle_data_5001())
    
except KeyboardInterrupt:
    machine.reset()

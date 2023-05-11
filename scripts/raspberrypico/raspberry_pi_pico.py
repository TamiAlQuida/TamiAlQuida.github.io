#import mip ## new upip
from machine import Pin, PWM
#import machine
import network
import socket
import uasyncio as asyncio
import ujson as json
from time import sleep

#constants and variables
led = Pin("LED", Pin.OUT)
SSID = 'Pallans Special'
PASSWORD = '62g2cuhkw'
HOST_IP = '192.168.1.25'
PORT = 5001

parameters = []
speed = 0
speed_translation = 0
direction = 0
direction_translation = 0

#motor setup
dc_motor_forward = Pin(1, Pin.OUT)#GP1=pin2
dc_motor_backward = Pin(2, Pin.OUT)#GP2=pin4
dc_motor_pwm = PWM(Pin(0)) #GP0=pin1, GND=pin3, VSYS(power)=pin39
dc_motor_pwm.freq(100)

#servo setup
servo_motor_pwm = PWM(Pin(28))
servo_motor_pwm.freq(50)

#functions
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

def connect_socket():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((HOST_IP, PORT))

async def handle_data_5001():
    global speed, direction, parameters, speed_translation
    data1 = s.recv(5)
    data = data1.decode()
    parameters = data.split()
    print(parameters)
    speed = int(parameters[0])
    direction = int(parameters[1])
    adjust_speed()
    adjust_direction()
    if parameters == []:
        quit()

def adjust_direction():
    global direction_translation, direction
    # .duty_16(#) takes values of 0 to 65535 for duty cycle of 0 to 100
    # SG90 has 2 per cent duty cycle for 0 degrees, 12 per cent for 180.
    # So a .duty_u16 value of c.1350 is zero degrees; 8200 is 180 degrees.
    if direction == 50:
        direction_translation = ((direction-10)*86)+1350
        print('Direction is 0')
        servo_motor_pwm.duty_u16(direction_translation)
    else:
        direction_translation = ((direction-10)*86)+1350
        print(direction_translation)
        servo_motor_pwm.duty_u16(direction_translation)

def adjust_speed():
    global speed_translation, speed  
    if speed > 50:
        dc_motor_backward.value(0)
        dc_motor_forward.value(1)
        speed_translation = (speed-50)*1638
        print(speed_translation)
        dc_motor_pwm.duty_u16(speed_translation)
    
    if speed < 50:
        dc_motor_forward.value(0)
        dc_motor_backward.value(1)
        speed_translation = (speed-50)*-1638
        print(speed_translation)
        dc_motor_pwm.duty_u16(speed_translation)
    
    if speed == 50:
        print('Speed is 0')
        dc_motor_backward.value(0)
        dc_motor_forward.value(0)
        dc_motor_pwm.duty_u16(0)


def turn_off():
    print('turning off')
    led.off()
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.disconnect()
    dc_motor_backward.value(0)
    dc_motor_forward.value(0)
    dc_motor_pwm.duty_u16(0)
    servo_motor_pwm.duty_u16(0)
    print('done')

#execution
#connect wifi and socket
connect_wifi()
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST_IP, PORT))
#motor setup
dc_motor_forward = Pin(1, Pin.OUT)#GP1=pin2
dc_motor_backward = Pin(2, Pin.OUT)#GP2=pin4
dc_motor_pwm = PWM(Pin(0)) #GP0=pin1, GND=pin3, VSYS(power)=pin39
dc_motor_pwm.freq(100)

while True:
    try:
        while True:
            asyncio.run(handle_data_5001())
    
    finally:
        turn_off()
        break

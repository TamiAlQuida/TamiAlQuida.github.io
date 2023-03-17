# function.py
import keyboard
from time import sleep

speed = 0
steering = 0

def key_pressed():

    """speed"""
    if speed == 0:  
        if keyboard.is_pressed("uppil"):
            speed += 10
            print(speed)
            sleep(0.1)
        if keyboard.is_pressed("nedpil"):
            speed -= 10
            print(speed)
            sleep(0.1)
    
    if speed > 0:
        if keyboard.is_pressed("uppil"):
            speed += 10
            print(speed)
            sleep(0.1)
        else:
            speed -= 10
            print(speed)
            sleep(0.1)
    
    if speed < 0:
        if keyboard.is_pressed("nedpil"):
            speed -= 10
            print(speed)
            sleep(0.1)
        else:
            speed += 10
            print(speed)
            sleep(0.1)
    
    
    """steering"""
    if steering == 0:
        if keyboard.is_pressed("högerpil"):
            steering += 10
            print(steering)
            sleep(0.1)
        if keyboard.is_pressed("vänsterpil"):
            steering -= 10
            print(steering)
            sleep(0.1)

    if steering > 0:
        if keyboard.is_pressed("högerpil"):
            steering += 10
            print(steering)
            sleep(0.1)
        else:
            steering -= 10
            print(steering)
            sleep(0.1)

    if steering < 0:
        if keyboard.is_pressed("vänsterpil"):
            steering -= 10
            print(steering)
            sleep(0.1)
        else:
            steering += 10
            print(steering)
            sleep(0.1)


if __name__ == '__main__':
    # code that should only run when function.py is run as the main module
    key_pressed()
import keyboard
from time import sleep
#import identify_key_function

print("This is a test for loading different scripts press 'a' for: ")

speed = 0
steering = 0


while True:
    #identify_key_function

    if keyboard.is_pressed("q"):
        break

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

# import curses and GPIO
import RPi.GPIO as GPIO
# import os #added so we can shut down OK
import time #import time module

#set GPIO numbering mode and define output pins
GPIO.setmode(GPIO.BOARD)
GPIO.setup(31,GPIO.OUT)

#setup PWM control
GPIO.setup(32,GPIO.OUT)
speedright = GPIO.PWM(32,100)
speedright.start(100)

for x in range(2):
        GPIO.output(31,True)
        time.sleep(1)
        GPIO.output(31,False)
        time.sleep(1)


speedright.ChangeDutyCycle(10)

for x in range(2):
        GPIO.output(31,True)
        time.sleep(1)
        GPIO.output(31,False)
        time.sleep(1)


speedright.ChangeDutyCycle(66)

for x in range(2):
        GPIO.output(31,True)
        time.sleep(1)
        GPIO.output(31,False)
        time.sleep(1)


#GPIO cleanup
GPIO.cleanup()
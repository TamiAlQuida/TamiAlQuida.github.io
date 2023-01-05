# if you don't need to be wireless, check out the library pydualsense

# first do this in terminal (see https://www.youtube.com/watch?v=pVKltuIJT70)
# 'cd /dev/input'
# 'll'
# identify correct  'event' to put in gamepad = InputDevice('/dev/input/MY_CONTROLLER_EVENT_NUMBER') se comment below
# cat /proc/bus/input/devices for more info

import RPi.GPIO as GPIO                     # controll outputs
import time
from evdev import InputDevice, categorize, ecodes                   # pip install evdev

# Set GPIO numbering mode
GPIO.setmode(GPIO.BOARD)

# Set pin 11 as an output, and define as servo1 as PWM pin
GPIO.setup(11,GPIO.OUT)
servo1 = GPIO.PWM(11,50) # pin 11 for servo1, pulse 50Hz

# Start PWM running, with value of 0 (pulse off)
servo1.start(0)

gamepad = InputDevice('/dev/input/event2')      # "cd /dev/input" then "ls -al" to see your connections

absolutes = {                               # ecodes.EV_ABS
    0: 'left joystick left/right',          # 0 = left, 255 = right
    1: 'left joystick up/down',             # 0 = up, 255 = down
    2: 'right joystick left/right',         # 0 = left, 255 = right
    3: 'L2 analog',                         # 0 = no press, 255 = full press
    4: 'R2 analog',                         # 0 = no press, 255 = full press
    5: 'right joystick up/down',            # 0 = up, 255 = down
    16: 'leftpad left/right',               # -1 = left, 0 = stop pressing, 1 = right
    17: 'leftpad up/down',                  # -1 = up, 0 = stop pressing, 1 = down
}

CENTER = 128
BLIND = 6                                   # there's a lot of drift at 128, so don't report changes within (128 - this value)
MAX_EMERGENCY_DELAY = 1000                  # max number of milliseconds between taps to qualify as an emergency double-tap

new_center = CENTER - 38

emergency_tap_time = 0                      # track when the last time the emergency button (touchpad) was pressed
left_joystick, right_joystick = [new_center, new_center], [CENTER, CENTER]


def update_left_joystick_position(event):
    global left_joystick
    if event.code == 0:                     # left joystick, x-axis (left/right)
        left_joystick[0] = int(value * 180 / 255)
    #elif event.code == 1:                   # left joystick, y-axis (up/down)
    #    left_joystick[1] = int(value * 180 / 255)



if __name__ == '__main__': # this condition makes the code below run only if this script file is running. If you were to import it, then the file that all gets imported to, would only import what's above this line. So you'd have to call the function below manually from that file.
    # print(gamepad)

    for event in gamepad.read_loop():
        # print(categorize(event))
        # print(event)

        if event.type == ecodes.EV_ABS and event.code in absolutes:                     # leftpad, joystick motion, or L2/R2 triggers
            action, value = absolutes[event.code], event.value
            
            if event.code in [0, 1]:                                              # joystick motion
                if event.code in [0, 1]:                                                # left joystick moving
                    update_left_joystick_position(event)

                if event.value > (CENTER - BLIND) and event.value < (CENTER + BLIND):   # skip printing the jittery center for the joysticks
                    continue
                        
                print(f'{left_joystick}')
                angle = left_joystick[0]
                print(angle)
                servo1.ChangeDutyCycle(2+(angle/18))
                #time.sleep(0.1)
                #servo1.ChangeDutyCycle(0)
                continue

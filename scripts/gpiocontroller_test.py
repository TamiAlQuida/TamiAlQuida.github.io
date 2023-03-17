# if you don't need to be wireless, check out the library pydualsense

# first do this in terminal (see https://www.youtube.com/watch?v=pVKltuIJT70)
# 'cd /dev/input'
# 'll'
# identify correct  'event' to put in gamepad = InputDevice('/dev/input/MY_CONTROLLER_EVENT_NUMBER') se comment below
# cat /proc/bus/input/devices for more info

import RPi.GPIO as GPIO                     # controll outputs
from time import sleep
from evdev import InputDevice, categorize, ecodes                   # pip install evdev

# Set GPIO numbering mode
GPIO.setmode(GPIO.BOARD)

# Setting up pins
GPIO.setup(11,GPIO.OUT) # Set pin 11 as an output, and define as servo1 as PWM pin
servo1 = GPIO.PWM(11,50) # pin 11 for servo1, pulse 50Hz
servo1.start(0) # Start PWM running, with value of 0 (pulse off)

GPIO.setup(31,GPIO.OUT)
GPIO.setup(32,GPIO.OUT)
dc_motor_1 = GPIO.PWM(32,100)
dc_motor_1.start(0)


gamepad = InputDevice('/dev/input/event2')      # "cd /dev/input" then "ls -al" to see your connections

button_presses = {                          # ecodes.EV_KEY
    304: 'square',
    305: 'x',
    313: 'pause',
    306: 'circle',
    307: 'triangle',
}

button_values = {                           # ecodes.EV_KEY button press values
    0: 'up',
    1: 'down'
}

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
BLIND = 10                                  # there's a lot of drift at 128, so don't report changes within (128 - this value)
initial_center = CENTER - 38



# give initial_center a new value by pressing circle so that the jitter stops, or come up with how to turn on/off the servo by pressing 'circle'




left_joystick, right_joystick = [initial_center, initial_center], [initial_center, initial_center]
r2 = [0]

def update_left_joystick_position(event):
    global left_joystick
    if event.code == 0:                     # left joystick, x-axis (left/right)
        left_joystick[0] = int(value * 180 / 255)
    elif event.code == 1:                   # left joystick, y-axis (up/down)
        left_joystick[1] = int(value * 180 / 255)

 
def update_right_joystick_position(event):
    global right_joystick
    if event.code == 2:                     # right joystick, x-axis (left/right)
        right_joystick[0] = int(value * 180 / 255)
    elif event.code == 5:                   # right joystick, y-axis (up/down)
        right_joystick[1] = int(value * 180 / 255)


def move_servo():
    angle = left_joystick[0]
    servo1.ChangeDutyCycle(2+(angle/18))


def turn_off():
    servo1.stop()
    GPIO.cleanup()
    print("Goodbye!")


def dc_motor():
    global r2
    if event.code == 4:                     # left joystick, x-axis (left/right)
        r2[0] = int(value / 2.55)
        dc_motor_1.ChangeDutyCycle(r2[0])
        

if __name__ == '__main__': # this condition makes the code below run only if this script file is running. If you were to import it, then the file that all gets imported to, would only import what's above this line. So you'd have to call the function below manually from that file.
    # print(gamepad)

    for event in gamepad.read_loop():
        # print(categorize(event))
        # print(event)

        if event.type == ecodes.EV_KEY and event.code in button_presses:                # any button press other than leftpad
            button, direction = button_presses[event.code], button_values[event.value]
            print(f'{button} {direction}')

            if event.code in [313]: # start/pause
                break

            if event.code in [305]: # x
                import camera_test
            
            if event.code in [304]: # square
                import bme280_sensor_data_plot
            
            if event.code in [306]: # circle
                servo1.ChangeDutyCycle(0)     # update with moving center instead
            

        if event.type == ecodes.EV_ABS and event.code in absolutes:                     # leftpad, joystick motion, or L2/R2 triggers
            action, value = absolutes[event.code], event.value
            
            if event.code in [0, 1, 2, 5]:                                              # joystick motion
                if event.code in [0, 1]:                                                # left joystick moving
                    update_left_joystick_position(event)
                elif event.code in [2, 5]:                                              # right joystick moving
                    update_right_joystick_position(event)

                if event.value > (CENTER - BLIND) and event.value < (CENTER + BLIND):   # skip printing the jittery center for the joysticks
                    continue
                        
                print(f'{left_joystick}, {right_joystick}')
                move_servo()
                continue

            if event.code in [4]:                                                    # L2/R2 triggers
                GPIO.output(31,True)
                dc_motor()
                print(f'{r2}') 
            
turn_off()
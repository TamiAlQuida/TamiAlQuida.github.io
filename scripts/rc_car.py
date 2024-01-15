import RPi.GPIO as GPIO                     # controll outputs
import time
from evdev import InputDevice, categorize, ecodes                   # pip install evdev

# Set GPIO numbering mode
GPIO.setmode(GPIO.BOARD)

# Setting up pins
GPIO.setup(8,GPIO.OUT) # Set pin 11 as an output, and define as servo1 as PWM pin
servo1 = GPIO.PWM(8,50) # pin 11 for servo1, pulse 50Hz
servo1.start(0) # Start PWM running, with value of 0 (pulse off)

GPIO.setup(33,GPIO.OUT) # backward (L2)
GPIO.setup(35,GPIO.OUT) # forward (R2)
GPIO.setup(37,GPIO.OUT) # value
dc_motor_1 = GPIO.PWM(37,100)
dc_motor_1.start(0)

#gamepad = InputDevice('/dev/input/event2')      # "cd /dev/input" then "ls -al" to see your connections
for i in range(0, 20):
    try:
        input1 = '/dev/input/event' + str(i)
        gamepad = InputDevice(input1)
    except:
        continue

button_presses = {                          # ecodes.EV_KEYy
    304: 'square',
    305: 'x',
    315: 'pause',
    306: 'circle',
    307: 'triangle',
}

button_values = {                           # ecodes.EV_KEY button press values
    0: 'up',
    1: 'down'
}

absolutes = {                               # ecodes.EV_ABS
    0: 'left joystick, left/right',          # 0 = left, 255 = right
    2: 'L2 analog',                         # 0 = no press, 255 = full press
    5: 'R2 analog',                         # 0 = no press, 255 = full press
}

CENTER = 128
BLIND = 6                                   # there's a lot of drift at 128, so don't report changes within (128 - this value)
new_center = CENTER - 38

left_joystick = [new_center, new_center]
l2, r2 = 0, 0



#update values#########################################
def update_left_joystick_position(event):
    global left_joystick
    if event.code == 0:                     # left joystick, x-axis (left/right)
        left_joystick[0] = int(value * 180 / 255)
        print(left_joystick[0])


def update_l2(value):
    global l2
    l2 = int(value / 2.55)
    print(l2)


def update_r2(value):
    global r2
    r2 = int(value / 2.55)
    print(r2)
#######################################################


#actions###############################################
def move_servo():
    global left_joystick
    angle = left_joystick[0]
    servo1.ChangeDutyCycle(2+(angle/18))


def dc_motor_backward():
    global l2
    GPIO.output(35,False)
    GPIO.output(33,True)
    dc_motor_1.ChangeDutyCycle(l2)


def dc_motor_forward():
    global r2
    GPIO.output(33,False)
    GPIO.output(35,True)
    dc_motor_1.ChangeDutyCycle(r2)


def turn_off():
    servo1.stop()
    GPIO.cleanup()
    print("Goodbye!")
#####################################################


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

        if event.type == ecodes.EV_ABS and event.code in absolutes:                     # leftpad, joystick motion, or L2/R2 triggers
            action, value = absolutes[event.code], event.value
            
            if event.code in [0]:                                              # joystick motion
                if event.code in [0]:                                                # left joystick moving
                    update_left_joystick_position(event)

                    if event.value > (new_center - BLIND) and event.value < (new_center + BLIND):   # skip printing the jittery center for the joysticks
                        continue
                        
                print(f'{left_joystick}')
                move_servo()

            if event.code in [2]: # L2
                update_l2(value)
                dc_motor_backward()
                
            if event.code in [5]: # R2
                update_r2(value)
                dc_motor_forward()
    
    turn_off()
    

import socket
from time import sleep
from evdev import InputDevice, categorize, ecodes                   # pip install evdev

gamepad = InputDevice('/dev/input/event12')      # "cd /dev/input" then "ls -al" to see your connections

button_presses = {                          # ecodes.EV_KEY
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
    0: 'left joystick left/right',          # 0 = left, 255 = right
    2: 'L2 analog',                         # 0 = no press, 255 = full press
    5: 'R2 analog',                         # 0 = no press, 255 = full press
}

CENTER = 128
BLIND = 4                                 # there's a lot of drift at 128, so don't report changes within (128 - this value)
initial_center = CENTER - 78

speed, direction = [0], [initial_center]


def update_left_joystick_position(event):
    global direction
    direction[0] = int(value * 80 / 255) + 10


def update_r2(event):
    global speed
    speed[0] = int(value * 40 / 255) + 50


def update_l2(event):
    global speed
    speed[0] = int(-value * 40 / 255) + 50


def handleData5001():
    #clientsocket.send((f'{speed} {direction}').encode())
    print(f'{direction} {speed}')


if __name__ == '__main__': # this condition makes the code below run only if this script file is running. If you were to import it, then the file that all gets imported to, would only import what's above this line. So you'd have to call the function below manually from that file.
    print(gamepad)

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((socket.gethostname(), 5001))
    s.listen(0) # maybe makes it so only 1 can connect, not sure
    clientsocket, address = s.accept()
    print(f'Connection from {address}')
    

    for event in gamepad.read_loop():
        #print(categorize(event))
        #print(event)

        if event.type == ecodes.EV_KEY and event.code in button_presses:                # any button press other than leftpad
            button, direction = button_presses[event.code], button_values[event.value]
            print(f'{button} {direction}')

            if event.code in [315]: # start/pause
                break            

        if event.type == ecodes.EV_ABS and event.code in absolutes:                     # leftpad, joystick motion, or L2/R2 triggers
            action, value = absolutes[event.code], event.value
            
            if event.code in [0]:                                              # joystick motion
                if event.code in [0]:                                                # left joystick moving
                    update_left_joystick_position(event)

                if event.value > (CENTER - BLIND) and event.value < (CENTER + BLIND):   # skip printing the jittery center for the joysticks
                    continue
                        
                handleData5001()
                continue

            if event.code in [5]:                                                    # L2/R2 triggers
                #GPIO.output(31,True)
                #dc_motor()
                #print(f'{r2}') 
                update_r2(event)
                handleData5001()
                continue

            if event.code in [2]:                                                    # L2/R2 triggers
                #GPIO.output(31,True)
                #dc_motor()
                #print(f'{r2}') 
                update_l2(event)
                handleData5001()
                continue

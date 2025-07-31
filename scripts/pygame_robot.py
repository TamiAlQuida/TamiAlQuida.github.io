
import pygame
from time import sleep
from evdev import InputDevice, categorize, ecodes 

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
    313: 'start',
}

button_values = {                           # ecodes.EV_KEY button press values
    0: 'up',
    1: 'down'
}

absolutes = {                               # ecodes.EV_ABS
    0: 'left joystick, left/right',          # 0 = left, 255 = right
    1: 'left joystick, up/down',             # 0 = up, 255 = down
    2: 'L2 analog',                         # 0 = no press, 255 = full press
    5: 'R2 analog',                         # 0 = no press, 255 = full press
}

CENTER = 128
BLIND = 6                                   # there's a lot of drift at 128, so don't report changes within (128 - this value)

left_joystick = [CENTER, CENTER]
l2, r2 = 0, 0


#We must open a Pygame window to allow it to detect user events
screen = pygame.display.set_mode([1600, 1200])
pygame.display.set_caption('Pygame Robot')
pygame.display.set_icon(pygame.Surface((32, 32)))  # Dummy icon
pygame.init()
pygame.font.init()

line_start = [800, 600]
line_end = [800, 400]


def draw_base_line():
	pygame.draw.line(screen, (255, 0, 0), (line_start[0], line_start[1]), (line_end[0], line_end[1]), 7)
	pygame.display.flip()


def clear_screen():
	screen.fill((0, 0, 0))
	pygame.display.flip()

# update values #######################################
def update_left_joystick_position(event):
    global left_joystick
    if event.code == 0:                     # left joystick, x-axis (left/right)
        left_joystick[0] = value
        line_end[0] = line_start[0] + (left_joystick[0] -128) * 4
    elif event.code == 1:                   # left joystick, y-axis (up/down)
        left_joystick[1] = value
        line_end[1] = line_start[1] + (left_joystick[1] -128) * 4


pygame.draw.line(screen, (255, 0, 0), (line_start[0], line_start[1]), (line_end[0], line_end[1]), 7)
pygame.display.flip()
#draw text
font = pygame.font.Font(None, 36)
text = font.render('Press arrow keys to move', True, (255, 255, 255))
screen.blit(text, (10, 10))
pygame.display.flip()
#draw rectangle

draw_base_line()

if __name__ == '__main__': # this condition makes the code below run only if this script file is running. If you were to import it, then the file that all gets imported to, would only import what's above this line. So you'd have to call the function below manually from that file.
    # print(gamepad)

    for event in gamepad.read_loop():
        # print(categorize(event))
        #print(event)

        if event.type == ecodes.EV_KEY and event.code in button_presses:                # any button press other than leftpad
            button, direction = button_presses[event.code], button_values[event.value]
            print(f'{button} {direction}')

            if event.code in [315]: # start/pause
                break

        if event.type == ecodes.EV_ABS and event.code in absolutes:                     # leftpad, joystick motion, or L2/R2 triggers
            action, value = absolutes[event.code], event.value
            
            if event.code in [0, 1]:   # joystick motion
                if event.code in [0, 1]:                                                # left joystick moving
                    update_left_joystick_position(event)
                    clear_screen()
                    draw_base_line()
                    if event.value > (CENTER - BLIND) and event.value < (CENTER + BLIND):   # skip printing the jittery center for the joysticks
                        continue
                        
                print(f'{left_joystick}')
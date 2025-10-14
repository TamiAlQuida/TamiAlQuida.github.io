# Identifies what key has been pressed

import keyboard

def on_key_event(event):
    print(f'Key {event.name}')

keyboard.on_press(on_key_event)

if __name__ == '__main__':
    # code that should only run when function.py is run as the main module
    keyboard.wait() # waits for any key event to occur
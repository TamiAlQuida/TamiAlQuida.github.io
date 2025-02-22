import serial
import pygame
import math

# Initialize Pygame
pygame.init()
screen = pygame.display.set_mode((400, 400))
clock = pygame.time.Clock()

# Open serial port (adjust port name as needed)
ser = serial.Serial('/dev/ttyACM0', 115200)

def draw_airplane(surface, center, pitch, roll):
    # Convert angles to radians
    roll_rad = math.radians(roll)
    pitch_rad = math.radians(pitch)
    
    # Define airplane shape
    length = 40
    wing_width = 60
    
    # Calculate points with pitch and roll
    # Nose position - affected by both pitch and roll
    nose = (
        center[0] + length * math.cos(roll_rad) * math.cos(pitch_rad),
        center[1] + length * math.sin(roll_rad) - length * math.sin(pitch_rad)
    )
    
    # Wings positions - affected mainly by roll
    left_wing = (
        center[0] - wing_width/2 * math.cos(roll_rad + math.pi/2),
        center[1] - wing_width/2 * math.sin(roll_rad + math.pi/2)
    )
    right_wing = (
        center[0] + wing_width/2 * math.cos(roll_rad + math.pi/2),
        center[1] + wing_width/2 * math.sin(roll_rad + math.pi/2)
    )
    
    # Draw airplane
    pygame.draw.line(surface, (255, 255, 255), left_wing, right_wing, 2)
    pygame.draw.line(surface, (255, 255, 255), center, nose, 2)

# Draw a test circle to verify display is working
screen.fill((0, 0, 0))
pygame.draw.circle(screen, (255, 0, 0), (200, 200), 30)
pygame.display.flip()

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Read serial data
    if ser.in_waiting:
        line = ser.readline().decode('utf-8').strip()
        try:
            # Parse pitch and roll from your serial output
            # Extract just the numbers from "Pitch: X.XX° | Roll: Y.YY°" format
            pitch_str, roll_str = line.split('|')
            pitch = float(pitch_str.replace('Pitch:', '').replace('°', '').strip())
            roll = float(roll_str.replace('Roll:', '').replace('°', '').strip())
            
            # Add debug print
            print(f"Parsed: pitch={pitch}, roll={roll}")
            
            # Clear screen
            screen.fill((0, 0, 0))
            
            # Draw airplane
            draw_airplane(screen, (200, 200), pitch, roll)
            
            pygame.display.flip()
            
        except Exception as e:
            print(f"Error processing data: {e}")
            print(f"Raw line: {line}")

    clock.tick(60)

pygame.quit()
ser.close()
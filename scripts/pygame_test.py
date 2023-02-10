import pygame

#We must open a Pygame window to allow it to detect user events
screen = pygame.display.set_mode([240, 160])

while True:
	for event in pygame.event.get():
		if event.type == pygame.KEYDOWN:
			if event.key == pygame.K_RIGHT:
				print('Right')
			if event.key == pygame.K_LEFT:
				print('Left')
			if event.key == pygame.K_UP:
				print('Up')
			if event.key == pygame.K_DOWN:
				print('Down')
			if event.key == pygame.K_q:
				pygame.quit()
		elif event.type == pygame.KEYUP:
			print('No key pressed')

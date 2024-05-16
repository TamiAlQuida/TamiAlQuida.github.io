#import tensorflow as tf
import cv2
import numpy as np

# Initialize the webcam
cap = cv2.VideoCapture(0) # might be 0,1 or 2 etc. depending on devices availible

# Check if the webcam is opened correctly
if not cap.isOpened():
    print("Error: Could not open webcam.")
    exit()

# Create a named window
cv2.namedWindow('Webcam', cv2.WINDOW_NORMAL)

# Resize the window
cv2.resizeWindow('Webcam', 3840, 2160) # 2560, 1440)  # Width, Height


while True:
    # Capture frame-by-frame
    ret, frame = cap.read()

    # If frame is read correctly, ret is True
    if not ret:
        print("Error: Can't receive frame (stream end?). Exiting ...")
        break

    # Sharpen filter
    #kernel = np.array([[0, -1, 0], [-1, 5,-1], [0, -1, 0]])
    #sharpened = cv2.filter2D(frame, -1, kernel)

    # Display the resulting frame
    cv2.imshow('Webcam', frame)

    # Exit the loop when 'q' key is pressed
    if cv2.waitKey(1) == ord('q'):
        break

# When everything is done, release the capture and close the window
cap.release()
cv2.destroyAllWindows()

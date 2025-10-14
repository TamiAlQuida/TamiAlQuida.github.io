import cv2

def main():
    cap = cv2.VideoCapture(0)

    if not cap.isOpened():
        print("Error: Could not open camera.")
        return

    while True:
        ret, frame = cap.read()

        if not ret:
            print("Error: Failed to capture frame.")
            break

        cv2.imshow('Frame', frame)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
######import cv2
######
######def main():
######    cap = cv2.VideoCapture(0)
######
######    if not cap.isOpened():
######        print("Error: Could not open camera.")
######        return
######
######    while True:
######        ret, frame = cap.read()
######
######        if not ret:
######            print("Error: Failed to capture frame.")
######            break
######
######        cv2.imshow('Frame', frame)
######
######        if cv2.waitKey(1) & 0xFF == ord('q'):
######            break
######
######    cap.release()
######    cv2.destroyAllWindows()
######
######if __name__ == "__main__":
######    try:
######        main()
######    except Exception as e:
######        print(f"An error occurred: {e}")
###
###import asyncio
###from libcamera import CameraManager, ControlId, FrameBuffer, FrameSize, PixelFormat
###
###async def main():
###    # Create a CameraManager instance
###    camera_manager = CameraManager()
###
###    # Wait for the camera to be ready
###    await camera_manager.start()
###
###    # Get the first camera available (assuming only one camera connected)
###    camera = camera_manager.cameras[0]
###
###    # Configure camera properties
###    await camera.configure([{
###        ControlId.ExposureValue: 0.0,
###        ControlId.IsoValue: 100
###    }])
###
###    # Create a FrameBuffer for capturing an image
###    buffer = FrameBuffer.create((1920, 1080), 'RG10')
###
###    # Capture an image
###    await camera.capture(buffer)
###
###    # Save the captured image
###    buffer.save('captured_image.jpg')
###
###    print("Image captured successfully!")
###
###    # Clean up camera resources
###    await camera.release()
###
###    # Stop the camera manager
###    await camera_manager.stop()
###
###if __name__ == "__main__":
###    asyncio.run(main())
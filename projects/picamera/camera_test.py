from picamera2 import Picamera2
from picamera2.encoders import JpegEncoder
from picamera2.outputs import FileOutput
from time import sleep
from datetime import datetime

camera = Picamera2()
# Set the camera configuration
camera.configure(camera.create_still_configuration())
camera.encoder = JpegEncoder()
camera.output = FileOutput('foo1.jpg')
# Start the camera preview
#camera.start_preview(Preview.QTGL)
# Set the resolution and start the camera
#camera.resolution = (640, 480)  # Set resolution to 640x480
print("preview \n")
#camera.start_preview()
# Set the resolution and start the camera
#camera.resolution = (3280, 2464)    # max resolution 3280 x 2464
#camera.start_preview()
# Camera warm-up time
sleep(2)
camera.start()
sleep(2)
for i in range(5):
    datetime_1 = datetime.now()
    datetime_1_str = datetime_1.strftime("%Y-%m-%d_%H_%M_%S_%f") #convert datetime to string
    print("Taking picture...\n")
    
    camera.capture_file(f'foo{datetime_1_str}.jpg')
    
    print("sucecss\n")
    



camera.stop()
camera.close()
#camera.capture(f'foo{datetime_1}.jpg')





#seems to be more zoomed in.

#from io import BytesIO
#from time import sleep
#from picamera import PiCamera
#from PIL import Image
#
## Create the in-memory stream
#stream = BytesIO()
#camera = PiCamera()
#camera.start_preview()
#sleep(2)
#camera.capture(stream, format='jpeg')
## "Rewind" the stream to the beginning so we can read its content
#stream.seek(0)
#image = Image.open(stream)



#from picamera import PiCamera
#from time import sleep
#from fractions import Fraction
#
## Force sensor mode 3 (the long exposure mode), set
## the framerate to 1/6fps, the shutter speed to 6s,
## and ISO to 800 (for maximum gain)
#camera = PiCamera(resolution=(3280, 2464))
#camera.shutter_speed = 6000000
#camera.iso = 800
## Give the camera a good long time to set gains and
## measure AWB (you may wish to use fixed AWB instead)
#sleep(30)
#camera.exposure_mode = 'off'
## Finally, capture an image with a 6s exposure. Due
## to mode switching on the still port, this will take
## longer than 6 seconds
#camera.capture('dark.jpg')
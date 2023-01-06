from picamera import PiCamera
from time import sleep
from datetime import datetime

camera = PiCamera()
camera.resolution = (3280, 2464)    # max resolution 3280 x 2464
camera.start_preview()
# Camera warm-up time
datetime_1 = datetime.now()
sleep(2)
camera.capture(f'foo{datetime_1}.jpg')





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
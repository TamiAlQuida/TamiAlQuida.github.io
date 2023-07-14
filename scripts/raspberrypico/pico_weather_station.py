import network
import usocket as socket
from time import sleep
from machine import Pin, I2C
import bme280
import ntptime
import utime

# Constants and variables
led = Pin("LED", Pin.OUT)
SSID = 'Pallans Special'
PASSWORD = '62g2cuhkw'
HOST_IP = '192.168.1.78'  # Linux Mint IP address
PORT = 5002

# Initialize BME280 sensor
i2c = I2C(0, sda=Pin(0), scl=Pin(1), freq=400000)
bme = bme280.BME280(i2c=i2c)

action_times = {
    '01:00',
    '02:00',
    '03:00',
    '04:00',
    '05:00',
    '06:00',
    '07:00',
    '08:00',
    '09:00',
    '10:00',
    '11:00',
    '12:00',
    '13:00',
    '14:00',
    '15:00',
    '16:00',
    '17:00',
    '18:00',
    '19:00',
    '20:00',
    '21:00',
    '22:00',
    '23:00',
    '00:00',
}

def connect_wifi():
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.connect(SSID, PASSWORD)
    while not wlan.isconnected():
        print('connecting...')
        sleep(2)
    ip = wlan.ifconfig()[0]
    print(f'Connected to WiFi, on {ip}')
    ntptime.settime()
    led.on()
    return wlan

def connect_to_pico():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        s.connect((HOST_IP, PORT))
        return s, s  # Assign s to both s and clientsocket
    except OSError:
        return s, None

def format_time():
    t = utime.localtime()
    formatted_time = "{:02d}:{:02d}".format(t[3], t[4])
    return formatted_time

def format_date_time():
    t = utime.localtime()
    formatted_time = '{:02d}-{:02d}-{:02d},{:02d}:{:02d}'.format(t[0], t[1], t[2], t[3], t[4])
    return formatted_time

# Connect to Wi-Fi
wlan = connect_wifi()

while True:    
    if not wlan.isconnected():
        wlan = connect_wifi()
    
    current_time = format_time()
    current_date_time = format_date_time()

    s = None
    clientsocket = None

    if current_time in action_times:
        # Read BME280 sensor values
        for i in range(10):
            temperature, pressure, humidity = bme.values
            sleep(1)
        print(f"Temperature: {temperature}, Pressure: {pressure}, Humidity: {humidity}")
        # Append to CSV file
        with open('bme280_data_pico.csv', 'a') as f:
            f.write(current_date_time + ',' + str(pressure) + ',' + str(temperature) + ',' + str(humidity) + ',')
        sleep(24)

    try:
        if not s:
            s, clientsocket = connect_to_pico()
            # Send CSV file to host
            #print('Reading CSV file...')
            with open('bme280_data_pico.csv', 'r') as f:
                csv_data = f.read()
            #print('Sending CSV data to host...')
            try:
                while csv_data:
                    sent_bytes = clientsocket.send(csv_data.encode())                  
                    csv_data = csv_data[sent_bytes:]
                    print('CSV file sent to host.')
                    # Erase data locally
                    with open('bme280_data_pico.csv', 'w') as f:
                        f.write('')
                    print('Local data erased.')
            except Exception as e:
                #print(f"Error sending CSV data: {e}")
                pass
    except Exception as e:
        #print(f"Connection error: {e}")
        pass

    sleep(25)







import network
import usocket as socket
from time import sleep
from machine import Pin, I2C
import bme280
import ntptime
import utime

# Constants and variables
led = Pin("LED", Pin.OUT)
SSID = 'Pallans Special'
PASSWORD = '62g2cuhkw'
HOST_IP = '192.168.1.78'  # Linux Mint IP address
PORT = 5002

# Initialize BME280 sensor
i2c = I2C(0, sda=Pin(0), scl=Pin(1), freq=400000)
bme = bme280.BME280(i2c=i2c)

action_times = {
    '01:00',
    '02:00',
    '03:00',
    '04:00',
    '05:00',
    '06:00',
    '07:00',
    '08:00',
    '09:00',
    '10:00',
    '11:00',
    '12:00',
    '13:00',
    '14:00',
    '15:00',
    '16:00',
    '17:00',
    '18:00',
    '19:00',
    '20:00',
    '21:00',
    '22:00',
    '23:00',
    '00:00',
}

# Time zone adjustment for Swedish summer time (Central European Summer Time, UTC+2)
def adjust_time_for_dst():
    year, month, _, hour, _, _, _, _ = utime.localtime()
    last_sunday_march = find_last_sunday(year, 3)
    last_sunday_october = find_last_sunday(year, 10)

    if month < 3 or month > 10:
        return 1  # Apply the time adjustment
    elif month == 3 and (month, hour) >= last_sunday_march:
        return 2
    elif month == 10 and (month, hour) < last_sunday_october:
        return 2
    else:
        return 2  # Apply the time adjustment


def find_last_sunday(year, month):
    last_day = 31
    while True:
        try:
            weekday = utime.localtime(utime.mktime((year, month, last_day, 0, 0, 0, 0, 0)))[6]
            if weekday == 6:  # Sunday
                return (month, last_day)
            last_day -= 1
        except:
            last_day -= 1

def connect_wifi():
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.connect(SSID, PASSWORD)
    while not wlan.isconnected():
        print('Connecting to WiFi...')
        sleep(2)
    ip = wlan.ifconfig()[0]
    print(f'Connected to WiFi, on {ip}')
    ntptime.settime()
    led.on()
    return wlan

def connect_to_pico():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        s.connect((HOST_IP, PORT))
        return s, s  # Assign s to both s and clientsocket
    except OSError:
        return s, None

def format_time():
    adjusted_hour = (utime.localtime()[3] + adjust_time_for_dst()) % 24
    formatted_time = "{:02d}:{:02d}".format(adjusted_hour, utime.localtime()[4])
    return formatted_time

def format_date_time():
    t = utime.localtime()
    adjusted_hour = (t[3] + adjust_time_for_dst()) % 24
    formatted_time = '{:02d}-{:02d}-{:02d},{:02d}:{:02d}'.format(t[0], t[1], t[2], adjusted_hour, t[4])
    return formatted_time

# Connect to Wi-Fi
wlan = connect_wifi()

while True:
    if not wlan.isconnected() and format_time() not in action_times:
        wlan = connect_wifi()
        
    current_time = format_time()
    current_date_time = format_date_time()
    
    s = None
    clientsocket = None

    if current_time in action_times:
        # Read BME280 sensor values
        for i in range(10):
            temperature, pressure, humidity = bme.values
            sleep(1)
        print(f"Temperature: {temperature}, Pressure: {pressure}, Humidity: {humidity}")

        # Append to CSV file
        with open('bme280_data_pico.csv', 'a') as f:
            f.write(current_date_time + ',' + str(pressure) + ',' + str(temperature) + ',' + str(humidity) + ',')
        sleep(40)

    try:
        if not s:
            s, clientsocket = connect_to_pico()
            # Send CSV file to host
            #print('Reading CSV file...')
            with open('bme280_data_pico.csv', 'r') as f:
                csv_data = f.read()
            #print('Sending CSV data to host...')
            try:
                while csv_data:
                    sent_bytes = clientsocket.send(csv_data.encode())                  
                    csv_data = csv_data[sent_bytes:]
                    print('CSV file sent to host.')
                    # Erase data locally
                    with open('bme280_data_pico.csv', 'w') as f:
                        f.write('')
                    print('Local data erased.')
            except Exception as e:
                #print(f"Error sending CSV data: {e}")
                pass
    except Exception as e:
        #print(f"Connection error: {e}")
        pass

    sleep(15)
    
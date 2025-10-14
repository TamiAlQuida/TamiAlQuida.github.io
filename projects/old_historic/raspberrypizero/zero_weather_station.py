from time import sleep
import RPi.GPIO as GPIO                     # controll outputs
import bme280
import smbus2

# Set GPIO numbering mode
GPIO.setmode(GPIO.BOARD)

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


def read_bme280_data():
    for i in range(10):
        temperature, pressure, humidity = bme.values
        sleep(1)
    #print(bme.values)
    temperature = temperature[:-1]
    pressure = pressure[:-3]
    humidity = humidity[:-1]
    formatted_pressure, formatted_temperature, formatted_humidity = f"{pressure:07}", f"{temperature:05}", f"{humidity:05}"
    print(formatted_pressure, formatted_temperature, formatted_humidity)

    # Append to CSV file
    with open('bme280_data_pico.csv', 'a') as f:
        f.write(current_date_time + ',' + formatted_pressure + ',' + formatted_temperature + ',' + formatted_humidity + ',')

# Connect to Wi-Fi
wlan = connect_wifi()
current_time = format_time()
current_date_time = format_date_time()
read_bme280_data()

while True:
    if not wlan.isconnected() and current_time not in action_times:
        wlan = connect_wifi()
        
    current_time = format_time()
    current_date_time = format_date_time()
    
    s = None
    clientsocket = None

    if current_time in action_times:
        # Read BME280 sensor values
        read_bme280_data()
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
    

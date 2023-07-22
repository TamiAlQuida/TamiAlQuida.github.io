import socket
import pandas as pd

try:
    bme280_plot_data = pd.read_csv('scripts/raspberrypico/bme280_data_pico.csv')  # Linux
except:
    bme280_plot_data = pd.read_csv(r'scripts/raspberrypico\bme280_data_pico.csv')  # Windows

data_dictionary_list = []

def connect_to_pico():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    s.bind(('192.168.1.78', 5002))  # Linux Mint IP address and different port
    #s.bind(('192.168.1.96', 5002))  # Linux Ubuntu IP address and different port
    s.listen(0)
    clientsocket, address = s.accept()
    print(f'Connection from {address}')

    while True:
        try:
            data = clientsocket.recv(BUFFER_SIZE)
            if data:
                data_decoded = data.decode()
                data_list = data_decoded.split(',')
                
                while len(data_list) >= 5:
                    data_dict = {
                        'Date': data_list.pop(0),
                        'Time': data_list.pop(0),
                        'Pressure hPa': data_list.pop(0),
                        'Temperature C': data_list.pop(0),
                        'Humidity %': data_list.pop(0),
                    }
                    data_dictionary_list.append(data_dict)

                df = pd.DataFrame(data_dictionary_list)
                print(df)
                df.to_csv(
                    'scripts/raspberrypico/bme280_data_pico.csv',
                    mode='a',
                    index=False,
                    header=False,
                )
                break
            else:
                print("Connection closed by the Raspberry Pi Pico")
                break
        except Exception as e:
            print(f"Error receiving data: {e}")
            break

    clientsocket.close()

if __name__ == '__main__':
    BUFFER_SIZE = 262144  # Size of the buffer on the Host PC side
    connect_to_pico()

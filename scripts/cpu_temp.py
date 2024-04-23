import psutil
import datetime
from time import sleep

while True:
    time = datetime.datetime.now()
    t = psutil.sensors_temperatures()
    conclusion = f'{time} \n {t} \n'

    print(conclusion)
    
    with open('cpu_temp.csv', 'a') as f:
        f.write(f'first line {conclusion}')
        
    sleep(1200)

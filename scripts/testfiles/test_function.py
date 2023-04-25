import socket
import asyncio
import json
from time import sleep

speed = 1
direction = 0


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((socket.gethostname(), 5001))
s.listen(0) # maybe makes it so only 1 can connect, not sure
clientsocket, address = s.accept()
print(f'Connection from {address}')

while True:
    #clientsocket.send(bytes(f"d= {direction}, s= {speed}", "utf8"))
    clientsocket.send(json.dumps({'speed': speed, 'direction': direction}).encode())
    print('sent')
    sleep(3)

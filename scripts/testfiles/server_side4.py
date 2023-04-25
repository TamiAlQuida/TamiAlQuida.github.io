import asyncio
import json
import socket


speed = 1
direction = 0

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((socket.gethostname(), 5001))
s.listen(0) # maybe makes it so only 1 can connect, not sure
clientsocket, address = s.accept()
print(f'Connection from {address}')

async def handleData5001():
    print('Hello') 
    global speed, direction
    while True:
            clientsocket.send(json.dumps({'speed': speed, 'direction': direction}).encode())
            print('world')
            #speed += 100
            await asyncio.sleep(3)

#async def main():
#    async with websockets.serve(handleData5001, 'localhost', 5001):
#        print("Server started")
#        await asyncio.Future()  # run forever

#asyncio.run(main())
asyncio.run(handleData5001())

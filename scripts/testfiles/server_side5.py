import asyncio
import json
import websockets
import socket

speed = 50
direction = 50


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((socket.gethostname(), 5001))
s.listen(0) # maybe makes it so only 1 can connect, not sure
clientsocket, address = s.accept()
print(f'Connection from {address}')

async def handleData5000(websocket):
    global speed, direction
    async for message in websocket:
        data = json.loads(message)
        if data['type'] == 'pressed':
            if (data['key'] == 'ArrowUp' or data['key'] == 'w') and speed < 90:
                speed += 5
            elif (data['key'] == 'ArrowDown' or data['key'] == 's') and speed > 10:
                speed -= 5
            elif (data['key'] == 'ArrowRight' or data['key'] == 'd') and direction < 90:
                direction += 5
            elif (data['key'] == 'ArrowLeft' or data['key'] == 'a') and direction > 10:
                direction -= 5
        elif data['type'] == 'released':
            if data['key'] == 'ArrowRight' or data['key'] == 'ArrowLeft' or data['key'] == 'a' or data['key'] == 'd':
                while direction > 50 and data['type'] != 'pressed':
                    direction -= 5
                    print(f'Speed: {speed}, Direction: {direction}')
                    await websocket.send(json.dumps({'speed': speed, 'direction': direction}))
                    await asyncio.sleep(0.07)
                while direction < 50 and data['type'] != 'pressed':
                    direction += 5
                    print(f'Speed: {speed}, Direction: {direction}')
                    await websocket.send(json.dumps({'speed': speed, 'direction': direction}))
                    await asyncio.sleep(0.07)
        print(f'Speed: {speed}, Direction: {direction}')
        #handleData5001()
        clientsocket.send((f'{speed} {direction}').encode())
        await websocket.send(json.dumps({'speed': speed, 'direction': direction}))

#def handleData5001():
    #print('Hello') 
    #global speed, direction
    #clientsocket.send((f'{speed} {direction}').encode())
    #print(f'Speed: {speed}, Direction: {direction}')


async def main():
    async with websockets.serve(handleData5000, 'localhost', 5000):
        print("Server started")
        await asyncio.Future()  # run forever

asyncio.run(main())

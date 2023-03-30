import asyncio
import json
import websockets
from time import sleep

speed = 0
direction = 0

async def handleData(websocket):
    global speed, direction
    async for message in websocket:
        data = json.loads(message)
        if data['type'] == 'pressed':
            if (data['key'] == 'ArrowUp' or data['key'] == 'w') and speed < 10:
                speed += 1
            elif (data['key'] == 'ArrowDown' or data['key'] == 's') and speed > -10:
                speed -= 1
            elif (data['key'] == 'ArrowRight' or data['key'] == 'd') and direction < 10:
                direction += 1
            elif (data['key'] == 'ArrowLeft' or data['key'] == 'a') and direction > -10:
                direction -= 1
        elif data['type'] == 'released':
            if data['key'] == 'ArrowRight' or data['key'] == 'ArrowLeft' or data['key'] == 'a' or data['key'] == 'd':
                while direction > 0 and data['type'] != 'pressed':
                    direction -= 1
                    print(f'Speed: {speed}, Direction: {direction}')
                    await websocket.send(json.dumps({'speed': speed, 'direction': direction}))
                    sleep(0.07)
                while direction < 0 and data['type'] != 'pressed':
                    direction += 1
                    print(f'Speed: {speed}, Direction: {direction}')
                    await websocket.send(json.dumps({'speed': speed, 'direction': direction}))
                    sleep(0.07)
        print(f'Speed: {speed}, Direction: {direction}')
        await websocket.send(json.dumps({'speed': speed, 'direction': direction}))

async def main():
    async with websockets.serve(handleData, 'localhost', 5000):
        print("Server started")
        await asyncio.Future()  # run forever

asyncio.run(main())

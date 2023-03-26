import asyncio
import json
import logging
import websockets

logging.basicConfig()

speed = 0
direction = 0

async def handleData(websocket, path):
    global speed, direction
    async for message in websocket:
        data = json.loads(message)
        if data['type'] == 'pressed':
            if data['key'] == 'ArrowUp' and speed < 10:
                speed += 1
            elif data['key'] == 'ArrowDown' and speed > -10:
                speed -= 1
            elif data['key'] == 'ArrowRight' and direction < 10:
                direction += 1
            elif data['key'] == 'ArrowLeft' and direction > -10:
                direction -= 1
        elif data['type'] == 'released':
            if data['key'] == 'ArrowRight' or data['key'] == 'ArrowLeft':
                direction = 0
            #elif data['key'] == 'ArrowUp' or data['key'] == 'ArrowDown':
            #    speed = 0
        print(f'Speed: {speed}, Direction: {direction}')
        await websocket.send(json.dumps({'speed': speed, 'direction': direction}))

async def main():
    async with websockets.serve(handleData, 'localhost', 5000):
        print("Server started")
        await asyncio.Future()  # run forever

asyncio.run(main())

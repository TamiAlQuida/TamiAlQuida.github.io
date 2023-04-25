import asyncio
import json
import websockets

speed = 0
direction = 0

async def handleData5000(websocket):
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
                    await asyncio.sleep(0.07)
                while direction < 0 and data['type'] != 'pressed':
                    direction += 1
                    print(f'Speed: {speed}, Direction: {direction}')
                    await websocket.send(json.dumps({'speed': speed, 'direction': direction}))
                    await asyncio.sleep(0.07)
        print(f'Speed: {speed}, Direction: {direction}')
        await websocket.send(json.dumps({'speed': speed, 'direction': direction}))

#async def handleData5001():
#    global speed, direction
#    while True:
#        try:
#            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#            sock.connect(('192.168.1.40', 5001))
#            while True:
#                sock.send(json.dumps({'speed': speed, 'direction': direction}).encode())
#                await asyncio.sleep(0.07)
#        except Exception as e:
#            print(f"Error: {e}")
#            await asyncio.sleep(1)

async def main():
    async with websockets.serve(handleData5000, 'localhost', 5000):
        print("Server started")
        await asyncio.Future()  # run forever

asyncio.run(main())

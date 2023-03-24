"""Python code using Flask to handle the HTTP POST request"""
from flask import Flask, request, jsonify
from flask_cors import CORS
from time import sleep

"""Flask variables"""
app = Flask(__name__)
cors = CORS(app)

""""Keystroke variables"""
speed = 0
direction = 0

@app.route('/data', methods=['POST']) # first function after this will be called! (handle_data in this case)
def handle_data():
    req_data = request.get_json()
    name = req_data['name']
    age = req_data['age']
    print(f'Received data: name={name}, age={age}')
    return jsonify({'message': f'Hello {name}, you are {age} years old.'})


@app.route('/keystroke', methods=['POST'])
def handle_keystroke():
    global speed
    global direction
    data = request.json
    key = data['key']
    key_type = data['type']
    print(key, key_type)
    # ArrowUp
    if key == 'ArrowUp' and key_type == 'pressed' and speed < 100:
        speed += 10
        print(f'speed: {speed}, direction: {direction}')
    if key == 'ArrowDown' and key_type == 'pressed' and speed > -100:
        speed -= 10
        print(f'speed: {speed}, direction: {direction}')
    if key == 'ArrowLeft' and key_type == 'pressed' and direction > -100:
        direction -= 10
        print(f'speed: {speed}, direction: {direction}')
    if key == 'ArrowRight' and key_type == 'pressed' and direction < 100:
        direction += 10
        print(f'speed: {speed}, direction: {direction}')

    while direction > 0 and key == 'ArrowRight' and key_type == 'released':
        direction -= 10
        print(f'speed: {speed}, direction: {direction}')
        sleep(0.1)
    while direction < 0 and key == 'ArrowLeft' and key_type == 'released':
        direction += 10
        print(f'speed: {speed}, direction: {direction}')
        sleep(0.1)
    return {"speed": speed, "direction": direction}


if __name__ == '__main__':
    app.run()
    
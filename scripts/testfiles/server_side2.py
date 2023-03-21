"""Python code using Flask to handle the HTTP POST request"""
from flask import Flask, request, jsonify
from flask_cors import CORS
from time import sleep

"""Flask variables"""
app = Flask(__name__)
cors = CORS(app)

""""Keystroke variables"""
speed = 0
arrow_up_status = 0


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
    global arrow_up_status
    data = request.json
    key = data['key']
    print(key)
    if key == 'ArrowUp pressed':
        arrow_up_status += 1
        print(arrow_up_status)
    if key == 'ArrowUp released':
        arrow_up_status -= 1
        print(arrow_up_status)
    while arrow_up_status == 1 and speed >= 0:
        speed += 10
        print(speed)
        sleep(0.1)
    while arrow_up_status == 0 and speed > 0:
        speed -= 10
        print(speed)
        sleep(0.2)

    return {'status': 'success'}


if __name__ == '__main__':
    app.run()
    
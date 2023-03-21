# Python code using Flask to handle the HTTP POST request
from flask import Flask, request, jsonify
from flask_cors import CORS
from time import sleep

app = Flask(__name__)
cors = CORS(app)

@app.route('/data', methods=['POST']) # first function after this will be called! (handle_data in this case)
def handle_data():
    req_data = request.get_json()
    name = req_data['name']
    age = req_data['age']
    print(f'Received data: name={name}, age={age}')
    return jsonify({'message': f'Hello {name}, you are {age} years old.'})


@app.route('/keystroke', methods=['POST'])
def handle_keystroke():
    data = request.json
    key = data['key']
    # Add your code to handle the keypress here
    print(key)
    return {'status': 'success'}


if __name__ == '__main__':
    app.run()
    
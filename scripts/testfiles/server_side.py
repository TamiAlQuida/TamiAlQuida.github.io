# Python code using Flask to handle the HTTP POST request
from flask import Flask, request, jsonify
from flask_cors import CORS

app = Flask(__name__)
cors = CORS(app)

@app.route('/data', methods=['POST'])
def handle_data():
    req_data = request.get_json()
    name = req_data['name']
    age = req_data['age']
    print(f'Received data: name={name}, age={age}')
    return jsonify({'message': f'Hello {name}, you are {age} years old.'})

if __name__ == '__main__':
    app.run()
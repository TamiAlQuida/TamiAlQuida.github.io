// client-side JavaScript code using WebSocket API
let socket = new WebSocket('ws://localhost:5000');

socket.addEventListener('open', (event) => {
  console.log('WebSocket connection established');
});

socket.addEventListener('message', (event) => {
  let data = JSON.parse(event.data);
  updateValue(data);
});

function updateValue(data) {
  const speed = data.speed;
  const direction = data.direction;
  document.getElementById('value').innerText = `Speed: ${speed}, Direction: ${direction}`;
  console.log(speed, direction)
  // update the indicator based on the current speed and direction
  updateIndicator(speed, direction);
}

function postKeyStroke(key, type) {
  socket.send(JSON.stringify({key: key, type: type}));
}

// listens to key strokes and sends them to server
var keyMap = {};
var keyIntervalMap = {};

document.addEventListener('DOMContentLoaded', () => {
  document.addEventListener('keydown', function(e) {
    if (keyMap[e.key]) return;
    keyMap[e.key] = true;
    console.log(e.key + ' pressed');
    postKeyStroke(e.key, 'pressed');
    
    keyIntervalMap[e.key] = setInterval(function() {
      if (keyMap[e.key]) {
        console.log(e.key + ' pressed');
        postKeyStroke(e.key, 'pressed');
      } else {
        clearInterval(keyIntervalMap[e.key]);
      }
    }, 70); // Change the interval as desired 70ms
  });

  document.addEventListener('keyup', function(e) {
    keyMap[e.key] = false;
    console.log(e.key + ' released');
    postKeyStroke(e.key, 'released');
    
    clearInterval(keyIntervalMap[e.key]);
  });
});

let speed = 0;
let direction = 0;

const indicator = document.getElementById("indicator");

function updateIndicator(speed, direction) {
    var topPosition = -speed + 100
    var leftPosition = direction
    // Update the style properties
    indicator.style.top = `${topPosition}%`;
    indicator.style.left = `${leftPosition}%`;
}

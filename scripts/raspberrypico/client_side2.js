// client-side JavaScript code using fetch API
function postData() {
  fetch('http://localhost:5000/data', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json'
    },
    body: JSON.stringify({name: 'John', age: 30})
  })
  .then(response => response.json())
  .then(data => console.log(data));
}

let SendDataButton = document.getElementById('button1');

SendDataButton.onclick = function () {
  postData();
}

function updateValue(data) {
  const speed = data.speed;
  const direction = data.direction;
  document.getElementById('value').innerText = `Speed: ${speed}, Direction: ${direction}`;
}

function postKeyStroke(key, type) {
  fetch('http://localhost:5000/keystroke', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json'
    },
    body: JSON.stringify({key: key, type: type})
  })
  .then(response => response.json())
  .then(data => {
    updateValue(data);
    console.log(data);
  });
}

// listens to key strokes and sends them to console
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
    }, 100); // Change the interval as desired
    
    // Add your code to handle the keypress here
    
  });

  document.addEventListener('keyup', function(e) {
    keyMap[e.key] = false;
    console.log(e.key + ' released');
    postKeyStroke(e.key, 'released');
    
    clearInterval(keyIntervalMap[e.key]);
    
    // Add your code to handle the key release here
    
  });
});

function updateValue(data) {
  const speed = data.speed;
  const direction = data.direction;
  document.getElementById('value').innerText = `Speed: ${speed}, Direction: ${direction}`;

  let indicator = document.getElementById("indicator");
  if (speed === 0 && direction === 0) {
    indicator.className = "center";
  } else if (speed === 10) {
    indicator.className = "top center";
  } else if (direction === -10) {
    indicator.className = "left center";
  } else {
    // reset the class to remove any previous positioning styles
    indicator.className = "";
  }
}

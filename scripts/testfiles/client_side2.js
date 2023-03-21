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


function postKeyStroke(key) {
  fetch('http://localhost:5000/keystroke', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json'
    },
    body: JSON.stringify({key: key})
  })
  .then(response => response.json())
  .then(data => console.log(data));
}

// listens to key strokes and sends them to console
var keyMap = {};

document.addEventListener('DOMContentLoaded', () => {
  document.addEventListener('keydown', function(e) {
    if (keyMap[e.key]) return;
    keyMap[e.key] = true;
    console.log(e.key + ' pressed');
    postKeyStroke(e.key + ' pressed');

    
    // Add your code to handle the keypress here
    
  });

  document.addEventListener('keyup', function(e) {
    keyMap[e.key] = false;
    console.log(e.key + ' released');
    postKeyStroke(e.key + ' released');
    
    // Add your code to handle the key release here
    
  });
});





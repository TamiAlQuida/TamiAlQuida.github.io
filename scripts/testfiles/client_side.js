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
  
// WebSocket Configuration
// Since this is a local setup, we'll try to connect to the Pico's IP.
// In a real scenario, this might need to be configurable or discovered.
// For now, we'll placeholder it with a common local IP or use `window.location.hostname` 
// if served from the Pico itself.
const WEBSOCKET_URL = `ws://${window.location.hostname}:80/ws`;
//sudo ufw allow 8000/tcp
//python -m http.server 8000
//sudo ufw delete allow 8000/tcp

// DOM Elements
const statusDot = document.getElementById('connectionStatus')?.querySelector('.status-dot');
const statusText = document.getElementById('statusText');

// Sensor Displays
const tempValue = document.getElementById('tempValue');
const humidityValue = document.getElementById('humidityValue');
const soilValue = document.getElementById('soilValue');

// Controls
const btnLightToggle = document.getElementById('btnLightToggle');
const btnPumpToggle = document.getElementById('btnPumpToggle');
const btnFanToggle = document.getElementById('btnFanToggle');

// Logs & Input
const logOutput = document.getElementById('logOutput');
const commandInput = document.getElementById('commandInput');
const btnSend = document.getElementById('btnSend');

// Test Buttons
const btnPythonToggle = document.getElementById('btnPythonToggle');
const btnCppToggle = document.getElementById('btnCppToggle');
const btnBashToggle = document.getElementById('btnBashToggle');

/**
 * WebSocket Manager class to handle connection, reconnection, and messaging
 */
class PicoController {
  constructor(url) {
    this.ws = null;
    this.url = url;
    this.retryInterval = 3000;
    this.isConnected = false;

    this.init();
  }

  init() {
    this.log('system', `Attempting to connect to ${this.url}...`);

    try {
      this.ws = new WebSocket(this.url);

      this.ws.onopen = this.onOpen.bind(this);
      this.ws.onmessage = this.onMessage.bind(this);
      this.ws.onclose = this.onClose.bind(this);
      this.ws.onerror = this.onError.bind(this);

    } catch (e) {
      this.log('error', 'Connection failed immediately. Retrying...');
      this.scheduleReconnect();
    }
  }

  onOpen() {
    this.isConnected = true;
    this.updateStatus(true);
    this.log('system', 'Connected to Pico W');
  }

  onClose() {
    this.isConnected = false;
    this.updateStatus(false);
    this.log('system', 'Disconnected from Pico W');
    this.scheduleReconnect();
  }

  onError(event) {
    this.log('error', 'WebSocket Error occurred');
    console.error('WebSocket Error:', event);
  }

  onMessage(event) {
    try {
      const data = event.data;
      this.log('received', `< ${data}`);

      // Attempt to parse JSON if message is structured
      // Expected format example: {"type": "sensor", "temp": 24.5, "humid": 60, "soil": 45}
      try {
        const parsed = JSON.parse(data);
        this.handleData(parsed);
      } catch (e) {
        // Not JSON, just plain text message
        // Could be a simple command acknowledgment
      }

    } catch (e) {
      console.error('Error processing message:', e);
    }
  }

  handleData(data) {
    if (data.type === 'sensor') {
      if (data.temp !== undefined && tempValue) tempValue.textContent = data.temp.toFixed(1);
      if (data.humid !== undefined && humidityValue) humidityValue.textContent = data.humid.toFixed(1);
      if (data.soil !== undefined && soilValue) soilValue.textContent = data.soil.toFixed(0);
    }
  }

  send(message) {
    if (this.ws && this.isConnected) {
      this.ws.send(message);
      this.log('sent', `> ${message}`);
    } else {
      this.log('error', 'Cannot send: Not connected');
    }
  }

  scheduleReconnect() {
    setTimeout(() => {
      if (!this.isConnected) {
        this.init();
      }
    }, this.retryInterval);
  }

  updateStatus(connected) {
    if (connected) {
      statusDot?.classList.add('connected');
      if (statusText) {
        statusText.textContent = 'Connected';
        statusText.style.color = 'var(--text-primary)';
      }
    } else {
      statusDot?.classList.remove('connected');
      if (statusText) {
        statusText.textContent = 'Disconnected';
        statusText.style.color = 'var(--text-secondary)';
      }
    }
  }

  log(type, message) {
    if (!logOutput) return;

    const entry = document.createElement('div');
    entry.className = `log-entry ${type}`;

    const timestamp = new Date().toLocaleTimeString();
    entry.textContent = `[${timestamp}] ${message}`;

    logOutput.appendChild(entry);
    logOutput.scrollTop = logOutput.scrollHeight;
  }
}

// Initialize Controller
// Priority: 1. window.location.hostname (if served from Pico), 2. Hardcoded IP
const picoIp = (window.location.hostname && window.location.hostname !== 'localhost' && window.location.hostname !== '127.0.0.1')
  ? window.location.hostname
  : '192.168.4.1'; // Change this to your Pico's IP if testing locally

const controller = new PicoController(`ws://${picoIp}:80/ws`);

// Local Script Execution Helper
const runLocalScript = (type) => {
  // Use relative path so it works whether on localhost or network IP
  fetch(`/run-script`, {
    method: 'POST',
    mode: 'cors',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify({ type: type })
  })
    .then(response => {
      if (!response.ok) throw new Error('Bridge server not running');
      return response.json();
    })
    .catch(error => {
      console.error('Error running local script:', error);
      controller.log('error', `Local Bridge Server not detected. Make sure bridge_server.py is running.`);
    });
};

// Event Listeners for Buttons
if (btnLightToggle) {
  btnLightToggle.addEventListener('click', () => {
    controller.send('TOGGLE_LIGHT');
  });
}

if (btnPumpToggle) {
  btnPumpToggle.addEventListener('click', () => {
    controller.send('TOGGLE_PUMP');
  });
}

if (btnFanToggle) {
  btnFanToggle.addEventListener('click', () => {
    controller.send('TOGGLE_FAN');
  });
}

if (btnPythonToggle) {
  btnPythonToggle.addEventListener('click', () => {
    // Ported logic from projects/old_historic/bolan.py
    const huskostnad = prompt("Vad kostar huset? (Bolan kalkylator)");
    if (huskostnad) {
      const kostnad = parseInt(huskostnad);
      const kontantinsats = kostnad * 0.15;

      // Show result in a nice alert
      alert(`Bolan Kalkyl:\nKostnad: ${kostnad.toLocaleString()} SEK\nKontantinsats (15%): ${kontantinsats.toLocaleString()} SEK`);

      // Also log it to the system log
      controller.log('system', `Bolan calculation: ${kontantinsats} SEK kontantinsats`);

      // Optionally still try to run the actual file if bridge server is up
      runLocalScript('python');
    }
  });
}

if (btnCppToggle) {
  btnCppToggle.addEventListener('click', () => {
    runLocalScript('cpp');
  });
}

if (btnBashToggle) {
  btnBashToggle.addEventListener('click', () => {
    runLocalScript('bash');
  });
}

// Manual Command Sending
if (btnSend && commandInput) {
  btnSend.addEventListener('click', () => {
    const cmd = commandInput.value.trim();
    if (cmd) {
      controller.send(cmd);
      commandInput.value = '';
    }
  });

  // Allow Enter key to send
  commandInput.addEventListener('keypress', (e) => {
    if (e.key === 'Enter') {
      const cmd = commandInput.value.trim();
      if (cmd) {
        controller.send(cmd);
        commandInput.value = '';
      }
    }
  });
}

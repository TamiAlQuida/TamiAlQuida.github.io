// WebSocket Configuration
// Since this is a local setup, we'll try to connect to the Pico's IP.
// In a real scenario, this might need to be configurable or discovered.
// For now, we'll placeholder it with a common local IP or use `window.location.hostname` 
// if served from the Pico itself.
const WEBSOCKET_URL = `ws://${window.location.hostname}:80/ws`;

// DOM Elements - Using definite assignment assertion since we know they exist in index.html
const statusDot = document.getElementById('connectionStatus')?.querySelector('.status-dot') as HTMLDivElement;
const statusText = document.getElementById('statusText') as HTMLSpanElement;

// Sensor Displays
const tempValue = document.getElementById('tempValue') as HTMLSpanElement;
const humidityValue = document.getElementById('humidityValue') as HTMLSpanElement;
const soilValue = document.getElementById('soilValue') as HTMLSpanElement;

// Controls
const btnLightToggle = document.getElementById('btnLightToggle') as HTMLButtonElement;
const btnPumpToggle = document.getElementById('btnPumpToggle') as HTMLButtonElement;
const btnFanToggle = document.getElementById('btnFanToggle') as HTMLButtonElement;

// Logs & Input
const logOutput = document.getElementById('logOutput') as HTMLDivElement;
const commandInput = document.getElementById('commandInput') as HTMLInputElement;
const btnSend = document.getElementById('btnSend') as HTMLButtonElement;

/**
 * WebSocket Manager class to handle connection, reconnection, and messaging
 */
class PicoController {
    private ws: WebSocket | null = null;
    private url: string;
    private retryInterval: number = 3000;
    private isConnected: boolean = false;

    constructor(url: string) {
        this.url = url;
        this.init();
    }

    private init() {
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

    private onOpen() {
        this.isConnected = true;
        this.updateStatus(true);
        this.log('system', 'Connected to Pico W');
    }

    private onClose() {
        this.isConnected = false;
        this.updateStatus(false);
        this.log('system', 'Disconnected from Pico W');
        this.scheduleReconnect();
    }

    private onError(event: Event) {
        this.log('error', 'WebSocket Error occurred');
        console.error('WebSocket Error:', event);
    }

    private onMessage(event: MessageEvent) {
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

    private handleData(data: any) {
        if (data.type === 'sensor') {
            if (data.temp !== undefined) tempValue.textContent = data.temp.toFixed(1);
            if (data.humid !== undefined) humidityValue.textContent = data.humid.toFixed(1);
            if (data.soil !== undefined) soilValue.textContent = data.soil.toFixed(0);
        }
    }

    public send(message: string) {
        if (this.ws && this.isConnected) {
            this.ws.send(message);
            this.log('sent', `> ${message}`);
        } else {
            this.log('error', 'Cannot send: Not connected');
        }
    }

    private scheduleReconnect() {
        setTimeout(() => {
            if (!this.isConnected) {
                this.init();
            }
        }, this.retryInterval);
    }

    private updateStatus(connected: boolean) {
        if (connected) {
            statusDot?.classList.add('connected');
            statusText.textContent = 'Connected';
            statusText.style.color = 'var(--text-primary)';
        } else {
            statusDot?.classList.remove('connected');
            statusText.textContent = 'Disconnected';
            statusText.style.color = 'var(--text-secondary)';
        }
    }

    private log(type: 'system' | 'sent' | 'received' | 'error', message: string) {
        const entry = document.createElement('div');
        entry.className = `log-entry ${type}`;

        const timestamp = new Date().toLocaleTimeString();
        entry.textContent = `[${timestamp}] ${message}`;

        logOutput.appendChild(entry);
        logOutput.scrollTop = logOutput.scrollHeight;
    }
}

// Initialize Controller
// For development testing without a running Pico, replace the URL with a test echo server like 'wss://echo.websocket.org' if needed.
// However, the user asked to communicate with a Pico via wifi.
// If testing locally (not served by Pico), you might need to hardcode the Pico's IP address.
// e.g., const controller = new PicoController('ws://192.168.1.50:80/ws');

// For now, we default to relative path assuming file acts as interface.
// If this file is just local, let's try a default local IP or placeholder.
const controller = new PicoController('ws://192.168.4.1/ws'); // Common Default AP IP for Pico or similar

// Event Listeners for Buttons
btnLightToggle.addEventListener('click', () => {
    controller.send('TOGGLE_LIGHT');
});

btnPumpToggle.addEventListener('click', () => {
    controller.send('TOGGLE_PUMP');
});

btnFanToggle.addEventListener('click', () => {
    controller.send('TOGGLE_FAN');
});

// Manual Command Sending
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

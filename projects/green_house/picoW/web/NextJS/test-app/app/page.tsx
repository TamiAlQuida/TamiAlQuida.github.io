"use client";

import { useEffect, useState, useRef } from "react";

// Types for our data
interface SensorData {
  temp: string;
  humid: string;
  soil: string;
}

interface LogEntry {
  type: "system" | "sent" | "received" | "error";
  message: string;
  timestamp: string;
}

export default function Home() {
  // --- State ---
  const [sensors, setSensors] = useState<SensorData>({ temp: "--", humid: "--", soil: "--" });
  const [logs, setLogs] = useState<LogEntry[]>([]);
  const [isConnected, setIsConnected] = useState(false);
  const [command, setCommand] = useState("");

  // Refs
  const ws = useRef<WebSocket | null>(null);
  const logEndRef = useRef<HTMLDivElement | null>(null);

  // --- Helpers ---
  const addLog = (type: LogEntry["type"], message: string) => {
    setLogs((prev) => [
      ...prev,
      { type, message, timestamp: new Date().toLocaleTimeString() },
    ].slice(-50)); // Keep only last 50 logs
  };

  const sendCommand = (msg: string) => {
    if (ws.current && ws.current.readyState === WebSocket.OPEN) {
      ws.current.send(msg);
      addLog("sent", `> ${msg}`);
    } else {
      addLog("error", "Cannot send: Not connected");
    }
  };

  const runLocalScript = async (type: string) => {
    try {
      const response = await fetch(`/run-script`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ type })
      });
      if (!response.ok) throw new Error('Bridge server not running');
      addLog("system", `Triggered ${type} script on local host`);
    } catch (error) {
      console.error(error);
      addLog("error", `Local Bridge Server not detected. Make sure bridge_server.py is running.`);
    }
  };

  // Auto-scroll logs
  useEffect(() => {
    logEndRef.current?.scrollIntoView({ behavior: "smooth" });
  }, [logs]);

  // --- WebSocket Logic ---
  useEffect(() => {
    let reconnectTimeout: NodeJS.Timeout;

    const connect = () => {
      const picoIp = (typeof window !== 'undefined' && window.location.hostname && !['localhost', '127.0.0.1'].includes(window.location.hostname))
        ? window.location.hostname
        : '192.168.4.1';

      addLog("system", `Attempting to connect to ws://${picoIp}:80/ws...`);
      const socket = new WebSocket(`ws://${picoIp}:80/ws`);

      socket.onopen = () => {
        setIsConnected(true);
        addLog("system", "Connected to Pico W");
      };

      socket.onclose = () => {
        setIsConnected(false);
        addLog("system", "Disconnected. Retrying in 3s...");
        reconnectTimeout = setTimeout(connect, 3000);
      };

      socket.onerror = (err) => {
        console.error("WS Error:", err);
      };

      socket.onmessage = (event) => {
        try {
          const data = JSON.parse(event.data);
          if (data.type === 'sensor') {
            setSensors({
              temp: data.temp !== undefined ? data.temp.toFixed(1) : "--",
              humid: data.humid !== undefined ? data.humid.toFixed(1) : "--",
              soil: data.soil !== undefined ? data.soil.toFixed(0) : "--"
            });
          }
          addLog("received", `< ${event.data}`);
        } catch (e) {
          addLog("received", `< ${event.data}`);
        }
      };

      ws.current = socket;
    };

    connect();

    return () => {
      ws.current?.close();
      clearTimeout(reconnectTimeout);
    };
  }, []);

  return (
    <div className="app-container">
      <header className="status-bar">
        <div className="logo">
          <span className="icon">🌿</span>
          <h1>Greenhouse<span className="highlight">Pico</span></h1>
        </div>
        <div className="connection-status">
          <div className={`status-dot ${isConnected ? 'connected' : ''}`}></div>
          <span id="statusText" style={{ color: isConnected ? 'var(--text-primary)' : 'var(--text-secondary)' }}>
            {isConnected ? 'Connected' : 'Disconnected'}
          </span>
        </div>
      </header>

      <main className="dashboard">
        <section className="card sensor-card">
          <h2>Environment</h2>
          <div className="sensor-grid">
            <div className="sensor-item">
              <span className="sensor-label">Temperature</span>
              <div className="sensor-value-container">
                <span className="sensor-value">{sensors.temp}</span>
                <span className="unit">°C</span>
              </div>
            </div>
            <div className="sensor-item">
              <span className="sensor-label">Humidity</span>
              <div className="sensor-value-container">
                <span className="sensor-value">{sensors.humid}</span>
                <span className="unit">%</span>
              </div>
            </div>
            <div className="sensor-item">
              <span className="sensor-label">Soil Moisture</span>
              <div className="sensor-value-container">
                <span className="sensor-value">{sensors.soil}</span>
                <span className="unit">%</span>
              </div>
            </div>
          </div>
        </section>

        <section className="card controls-card">
          <h2>Controls</h2>
          <div className="controls-grid">
            <div className="control-group">
              <label>Grow Lights</label>
              <button onClick={() => sendCommand('TOGGLE_LIGHT')} className="btn-toggle">
                <span className="btn-icon">💡</span>
                <span className="btn-text">Toggle</span>
              </button>
            </div>
            <div className="control-group">
              <label>Water Pump</label>
              <button onClick={() => sendCommand('TOGGLE_PUMP')} className="btn-toggle">
                <span className="btn-icon">💧</span>
                <span className="btn-text">Water Now</span>
              </button>
            </div>
            <div className="control-group">
              <label>Ventilation Fan</label>
              <button onClick={() => sendCommand('TOGGLE_FAN')} className="btn-toggle">
                <span className="btn-icon">🌪️</span>
                <span className="btn-text">Toggle</span>
              </button>
            </div>
          </div>
        </section>

        <section className="card logs-card">
          <h2>System Logs</h2>
          <div className="log-output">
            {logs.map((log, i) => (
              <div key={i} className={`log-entry ${log.type}`}>
                [{log.timestamp}] {log.message}
              </div>
            ))}
            <div ref={logEndRef} />
          </div>
          <form
            className="command-input-container"
            onSubmit={(e) => {
              e.preventDefault();
              if (command.trim()) {
                sendCommand(command.trim());
                setCommand("");
              }
            }}
          >
            <input
              type="text"
              value={command}
              onChange={(e) => setCommand(e.target.value)}
              placeholder="Send command to Pico..."
            />
            <button type="submit" className="btn-primary">Send</button>
          </form>
        </section>
      </main>

      <footer>
        <section className="card test-card">
          <h2>Test area</h2>
          <div className="sensor-grid">
            <div className="sensor-item">
              <label>Python script</label>
              <button onClick={() => {
                const huskostnad = prompt("Vad kostar huset? (Bolan kalkylator)");
                if (huskostnad) {
                  const kostnad = parseInt(huskostnad);
                  const kontantinsats = kostnad * 0.15;
                  alert(`Bolan Kalkyl:\nKostnad: ${kostnad.toLocaleString()} SEK\nKontantinsats (15%): ${kontantinsats.toLocaleString()} SEK`);
                  runLocalScript('python');
                }
              }} className="btn-toggle">
                <span className="btn-icon">💡</span>
                <span className="btn-text">Run Script</span>
              </button>
            </div>
            <div className="sensor-item">
              <label>C++ script</label>
              <button onClick={() => runLocalScript('cpp')} className="btn-toggle">
                <span className="btn-icon">💧</span>
                <span className="btn-text">Run Script</span>
              </button>
            </div>
            <div className="sensor-item">
              <label>Bash script</label>
              <button onClick={() => runLocalScript('bash')} className="btn-toggle">
                <span className="btn-icon">🌪️</span>
                <span className="btn-text">Run Script</span>
              </button>
            </div>
          </div>
        </section>
      </footer>
    </div>
  );
}
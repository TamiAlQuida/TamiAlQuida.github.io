"use client";

import { useEffect, useState, useRef, useCallback } from "react";

// =============================================================================
// ESP32 Baby Monitor Audio Player
// Handles WebSocket connection and Web Audio API playback of raw PCM data
// =============================================================================

const ESP32_SAMPLE_RATE = 16000; // Must match firmware SAMPLE_RATE
const ESP32_WS_PORT = 81;       // Must match firmware WS_PORT

type Esp32Status = "disconnected" | "connecting" | "connected" | "error";

function useEsp32Audio() {
  const [status, setStatus] = useState<Esp32Status>("disconnected");
  const [audioLevel, setAudioLevel] = useState<number>(0);
  const [errorMsg, setErrorMsg] = useState<string>("");

  const wsRef = useRef<WebSocket | null>(null);
  const audioCtxRef = useRef<AudioContext | null>(null);
  const nextPlayTimeRef = useRef<number>(0);

  const connect = useCallback((ip: string) => {
    // Clean up any existing connection
    disconnect();

    setStatus("connecting");
    setErrorMsg("");

    try {
      const ws = new WebSocket(`ws://${ip}:${ESP32_WS_PORT}/ws`);
      ws.binaryType = "arraybuffer";
      wsRef.current = ws;

      ws.onopen = () => {
        setStatus("connected");
        setErrorMsg("");
        // Create AudioContext on successful connection
        audioCtxRef.current = new AudioContext({ sampleRate: ESP32_SAMPLE_RATE });
        nextPlayTimeRef.current = 0;
      };

      ws.onmessage = (event: MessageEvent) => {
        if (!(event.data instanceof ArrayBuffer) || !audioCtxRef.current) return;

        const ctx = audioCtxRef.current;
        const int16Data = new Int16Array(event.data);
        const numSamples = int16Data.length;

        if (numSamples === 0) return;

        // Convert Int16 PCM to Float32 for Web Audio API
        const float32Data = new Float32Array(numSamples);
        let sumSquares = 0;
        for (let i = 0; i < numSamples; i++) {
          const sample = int16Data[i] / 32768.0;
          float32Data[i] = sample;
          sumSquares += sample * sample;
        }

        // Calculate RMS audio level (0-255 scale to match existing UI)
        const rms = Math.sqrt(sumSquares / numSamples);
        setAudioLevel(Math.min(rms * 512, 255));

        // Create audio buffer and schedule playback
        const audioBuffer = ctx.createBuffer(1, numSamples, ESP32_SAMPLE_RATE);
        audioBuffer.copyToChannel(float32Data, 0);

        const source = ctx.createBufferSource();
        source.buffer = audioBuffer;
        source.connect(ctx.destination);

        // Schedule at next available time for gapless playback
        const now = ctx.currentTime;
        const startTime = Math.max(now, nextPlayTimeRef.current);
        source.start(startTime);
        nextPlayTimeRef.current = startTime + audioBuffer.duration;
      };

      ws.onerror = () => {
        setStatus("error");
        setErrorMsg("WebSocket connection error");
      };

      ws.onclose = (event) => {
        if (status !== "disconnected") {
          setStatus("disconnected");
          if (!event.wasClean) {
            setErrorMsg("Connection lost");
          }
        }
        setAudioLevel(0);
      };
    } catch (err) {
      setStatus("error");
      setErrorMsg(`Failed to connect: ${err}`);
    }
  }, []);

  const disconnect = useCallback(() => {
    if (wsRef.current) {
      wsRef.current.close();
      wsRef.current = null;
    }
    if (audioCtxRef.current) {
      audioCtxRef.current.close();
      audioCtxRef.current = null;
    }
    setStatus("disconnected");
    setAudioLevel(0);
    nextPlayTimeRef.current = 0;
  }, []);

  // Cleanup on unmount
  useEffect(() => {
    return () => {
      disconnect();
    };
  }, [disconnect]);

  return { status, audioLevel, errorMsg, connect, disconnect };
}

// =============================================================================
// Surveillance Page Component
// =============================================================================

export default function SurveillancePage() {
  // --- Existing browser camera/mic state ---
  const [videoStream, setVideoStream] = useState<MediaStream | null>(null);
  const [audioStream, setAudioStream] = useState<MediaStream | null>(null);
  const [cameras, setCameras] = useState<MediaDeviceInfo[]>([]);
  const [selectedCamera, setSelectedCamera] = useState<string>("");
  const [audioLevel, setAudioLevel] = useState<number>(0);
  const [isListening, setIsListening] = useState(false);
  const [error, setError] = useState<string>("");

  const videoRef = useRef<HTMLVideoElement>(null);
  const audioContextRef = useRef<AudioContext | null>(null);
  const analyserRef = useRef<AnalyserNode | null>(null);
  const animationFrameRef = useRef<number>(0);

  // --- ESP32 Baby Monitor state ---
  const [esp32Ip, setEsp32Ip] = useState<string>("");
  const esp32 = useEsp32Audio();

  // Get available cameras
  useEffect(() => {
    const getCameras = async () => {
      try {
        await navigator.mediaDevices.getUserMedia({ video: true });

        const devices = await navigator.mediaDevices.enumerateDevices();
        const videoDevices = devices.filter(device => device.kind === 'videoinput');
        setCameras(videoDevices);

        if (videoDevices.length > 0) {
          setSelectedCamera(videoDevices[0].deviceId);
          startCamera(videoDevices[0].deviceId);
        }
      } catch (err) {
        setError("Camera access denied. Please allow camera permissions.");
        console.error("Camera error:", err);
      }
    };

    getCameras();

    return () => {
      videoStream?.getTracks().forEach(track => track.stop());
    };
  }, []);

  // Start camera with selected device
  const startCamera = async (deviceId: string) => {
    try {
      videoStream?.getTracks().forEach(track => track.stop());

      const stream = await navigator.mediaDevices.getUserMedia({
        video: { deviceId: { exact: deviceId } }
      });

      setVideoStream(stream);
      if (videoRef.current) {
        videoRef.current.srcObject = stream;
      }
      setError("");
    } catch (err) {
      setError("Failed to start camera. Please check permissions.");
      console.error("Camera start error:", err);
    }
  };

  // Handle camera change
  const handleCameraChange = (e: React.ChangeEvent<HTMLSelectElement>) => {
    const deviceId = e.target.value;
    setSelectedCamera(deviceId);
    startCamera(deviceId);
  };

  // Start microphone listening
  const startListening = async () => {
    try {
      const stream = await navigator.mediaDevices.getUserMedia({ audio: true });
      setAudioStream(stream);
      setIsListening(true);

      audioContextRef.current = new AudioContext();
      const source = audioContextRef.current.createMediaStreamSource(stream);
      analyserRef.current = audioContextRef.current.createAnalyser();
      analyserRef.current.fftSize = 256;
      source.connect(analyserRef.current);

      const dataArray = new Uint8Array(analyserRef.current.frequencyBinCount);

      const updateAudioLevel = () => {
        if (analyserRef.current) {
          analyserRef.current.getByteFrequencyData(dataArray);
          const average = dataArray.reduce((a, b) => a + b, 0) / dataArray.length;
          setAudioLevel(average);
        }
        animationFrameRef.current = requestAnimationFrame(updateAudioLevel);
      };

      updateAudioLevel();
      setError("");
    } catch (err) {
      setError("Microphone access denied. Please allow microphone permissions.");
      console.error("Microphone error:", err);
    }
  };

  // Stop microphone listening
  const stopListening = () => {
    audioStream?.getTracks().forEach(track => track.stop());
    setAudioStream(null);
    setIsListening(false);
    setAudioLevel(0);

    if (audioContextRef.current) {
      audioContextRef.current.close();
      audioContextRef.current = null;
    }

    if (animationFrameRef.current) {
      cancelAnimationFrame(animationFrameRef.current);
    }
  };

  // Toggle listening
  const toggleListening = () => {
    if (isListening) {
      stopListening();
    } else {
      startListening();
    }
  };

  // Handle ESP32 connect/disconnect
  const handleEsp32Toggle = () => {
    if (esp32.status === "connected" || esp32.status === "connecting") {
      esp32.disconnect();
    } else {
      if (esp32Ip.trim()) {
        esp32.connect(esp32Ip.trim());
      }
    }
  };

  const getEsp32StatusDot = () => {
    switch (esp32.status) {
      case "connected": return "●";
      case "connecting": return "◐";
      case "error": return "✖";
      default: return "○";
    }
  };

  const getEsp32StatusColor = () => {
    switch (esp32.status) {
      case "connected": return "#4ade80";
      case "connecting": return "#facc15";
      case "error": return "#f87171";
      default: return "#6b7280";
    }
  };

  return (
    <>
      <main className="dashboard">
        <section className="card surveillance-card">
          <h2>🎥 Surveillance Center</h2>

          {error && (
            <div className="error-banner">
              ⚠️ {error}
            </div>
          )}

          {/* ============================================================= */}
          {/* ESP32 Baby Monitor Section                                     */}
          {/* ============================================================= */}
          <div className="surveillance-section esp32-section">
            <h3>👶 ESP32 Baby Monitor</h3>

            <div className="esp32-controls">
              <div className="esp32-input-row">
                <label htmlFor="esp32-ip">ESP32 IP Address:</label>
                <input
                  id="esp32-ip"
                  type="text"
                  placeholder="e.g. 192.168.1.200"
                  value={esp32Ip}
                  onChange={(e) => setEsp32Ip(e.target.value)}
                  onKeyDown={(e) => {
                    if (e.key === "Enter") handleEsp32Toggle();
                  }}
                  className="esp32-ip-input"
                  disabled={esp32.status === "connected" || esp32.status === "connecting"}
                />
                <button
                  id="esp32-connect-btn"
                  onClick={handleEsp32Toggle}
                  className={`btn-toggle ${esp32.status === "connected" ? "active" : ""}`}
                  disabled={!esp32Ip.trim() && esp32.status === "disconnected"}
                >
                  <span className="btn-icon">
                    {esp32.status === "connected" || esp32.status === "connecting" ? "🔴" : "🟢"}
                  </span>
                  <span className="btn-text">
                    {esp32.status === "connected"
                      ? "Disconnect"
                      : esp32.status === "connecting"
                        ? "Connecting..."
                        : "Connect"}
                  </span>
                </button>
              </div>
            </div>

            {esp32.errorMsg && (
              <div className="error-banner" style={{ marginTop: "10px" }}>
                ⚠️ {esp32.errorMsg}
              </div>
            )}

            <div className="audio-visualizer">
              <div className="audio-level-bar">
                <div
                  className="audio-level-fill"
                  style={{
                    width: `${Math.min(esp32.audioLevel * 2, 100)}%`,
                    backgroundColor: esp32.audioLevel > 100 ? '#ff4444' : esp32.audioLevel > 50 ? '#ffaa00' : '#44ff44'
                  }}
                />
              </div>
              <p className="audio-level-text">
                ESP32 Mic Level: {Math.round(esp32.audioLevel)} / 255
              </p>
            </div>

            <div className="audio-info">
              <p style={{ color: getEsp32StatusColor(), fontWeight: 600 }}>
                {getEsp32StatusDot()} {esp32.status.charAt(0).toUpperCase() + esp32.status.slice(1)}
                {esp32.status === "connected" && ` — Streaming 16 kHz audio`}
              </p>
            </div>
          </div>

          {/* ============================================================= */}
          {/* Existing Camera Feed Section                                   */}
          {/* ============================================================= */}
          <div className="surveillance-section">
            <h3>Camera Feed</h3>

            <div className="camera-controls">
              <label htmlFor="camera-select">Select Camera:</label>
              <select
                id="camera-select"
                value={selectedCamera}
                onChange={handleCameraChange}
                className="camera-select"
              >
                {cameras.map((camera, index) => (
                  <option key={camera.deviceId} value={camera.deviceId}>
                    {camera.label || `Camera ${index + 1}`}
                  </option>
                ))}
              </select>
            </div>

            <div className="video-container">
              <video
                ref={videoRef}
                autoPlay
                playsInline
                muted
                className="video-feed"
              />
            </div>

            <div className="camera-info">
              <p>📹 {cameras.length} camera(s) available</p>
              {videoStream && (
                <p className="status-active">● Camera Active</p>
              )}
            </div>
          </div>

          {/* ============================================================= */}
          {/* Existing Browser Microphone Section                            */}
          {/* ============================================================= */}
          <div className="surveillance-section">
            <h3>🎤 Browser Microphone</h3>

            <div className="audio-controls">
              <button
                onClick={toggleListening}
                className={`btn-toggle ${isListening ? 'active' : ''}`}
              >
                <span className="btn-icon">{isListening ? '🔴' : '⚪'}</span>
                <span className="btn-text">
                  {isListening ? 'Stop Listening' : 'Start Listening'}
                </span>
              </button>
            </div>

            <div className="audio-visualizer">
              <div className="audio-level-bar">
                <div
                  className="audio-level-fill"
                  style={{
                    width: `${Math.min(audioLevel * 2, 100)}%`,
                    backgroundColor: audioLevel > 100 ? '#ff4444' : audioLevel > 50 ? '#ffaa00' : '#44ff44'
                  }}
                />
              </div>
              <p className="audio-level-text">
                Level: {Math.round(audioLevel)} / 255
              </p>
            </div>

            <div className="audio-info">
              {isListening ? (
                <p className="status-active">● Microphone Active</p>
              ) : (
                <p className="status-inactive">○ Microphone Off</p>
              )}
            </div>
          </div>
        </section>

        <section className="card logs-card">
          <h2>📋 Surveillance Notes</h2>
          <div className="surveillance-notes">
            <p>• <strong>ESP32 Baby Monitor</strong> — Enter the ESP32&apos;s IP and click Connect to stream audio from the INMP441 mic</p>
            <p>• Camera feed is local only — not streamed anywhere</p>
            <p>• Browser microphone uses your device&apos;s built-in mic</p>
            <p>• Audio levels show real-time sound detection</p>
            <p>• ESP32 streams 16 kHz / 16-bit mono PCM over WebSocket</p>
          </div>
        </section>
      </main>

      <style jsx>{`
        .surveillance-card {
          max-width: 900px;
        }

        .surveillance-section {
          margin: 20px 0;
          padding: 20px;
          background: rgba(0, 0, 0, 0.2);
          border-radius: 12px;
        }

        .surveillance-section h3 {
          margin-bottom: 15px;
          color: #4ade80;
        }

        .esp32-section {
          border: 1px solid rgba(74, 222, 128, 0.2);
          background: rgba(74, 222, 128, 0.05);
        }

        .esp32-controls {
          margin-bottom: 15px;
        }

        .esp32-input-row {
          display: flex;
          align-items: center;
          gap: 12px;
          flex-wrap: wrap;
        }

        .esp32-input-row label {
          color: #9ca3af;
          font-weight: 500;
          white-space: nowrap;
        }

        .esp32-ip-input {
          padding: 10px 15px;
          border-radius: 8px;
          border: 2px solid #374151;
          background: #1f2937;
          color: #f3f4f6;
          font-size: 14px;
          font-family: monospace;
          min-width: 180px;
          flex: 1;
          max-width: 250px;
        }

        .esp32-ip-input:hover:not(:disabled) {
          border-color: #4ade80;
        }

        .esp32-ip-input:focus {
          outline: none;
          border-color: #4ade80;
          box-shadow: 0 0 0 3px rgba(74, 222, 128, 0.15);
        }

        .esp32-ip-input:disabled {
          opacity: 0.5;
          cursor: not-allowed;
        }

        .camera-controls {
          display: flex;
          align-items: center;
          gap: 15px;
          margin-bottom: 15px;
        }

        .camera-controls label {
          color: #9ca3af;
          font-weight: 500;
        }

        .camera-select {
          padding: 10px 15px;
          border-radius: 8px;
          border: 2px solid #374151;
          background: #1f2937;
          color: #f3f4f6;
          font-size: 14px;
          cursor: pointer;
          min-width: 200px;
        }

        .camera-select:hover {
          border-color: #4ade80;
        }

        .video-container {
          width: 100%;
          max-width: 640px;
          margin: 0 auto;
          border-radius: 12px;
          overflow: hidden;
          background: #000;
          aspect-ratio: 16/9;
        }

        .video-feed {
          width: 100%;
          height: 100%;
          object-fit: cover;
        }

        .camera-info, .audio-info {
          margin-top: 15px;
          text-align: center;
          color: #9ca3af;
          font-size: 14px;
        }

        .status-active {
          color: #4ade80;
          font-weight: 600;
        }

        .status-inactive {
          color: #6b7280;
        }

        .audio-controls {
          display: flex;
          justify-content: center;
          margin-bottom: 20px;
        }

        .btn-toggle.active {
          background: #dc2626;
          border-color: #dc2626;
        }

        .audio-visualizer {
          max-width: 400px;
          margin: 0 auto;
          padding: 20px;
        }

        .audio-level-bar {
          width: 100%;
          height: 30px;
          background: #1f2937;
          border-radius: 15px;
          overflow: hidden;
          border: 2px solid #374151;
        }

        .audio-level-fill {
          height: 100%;
          transition: width 0.1s ease, background-color 0.2s ease;
          border-radius: 15px;
        }

        .audio-level-text {
          text-align: center;
          margin-top: 10px;
          color: #9ca3af;
          font-family: monospace;
        }

        .error-banner {
          background: rgba(220, 38, 38, 0.2);
          border: 1px solid #dc2626;
          color: #fca5a5;
          padding: 12px 16px;
          border-radius: 8px;
          margin-bottom: 20px;
        }

        .surveillance-notes {
          color: #9ca3af;
          line-height: 1.8;
        }

        .surveillance-notes p {
          margin: 8px 0;
        }
      `}</style>
    </>
  );
}

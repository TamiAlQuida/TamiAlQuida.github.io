"use client";

import { useEffect, useState, useRef } from "react";

export default function SurveillancePage() {
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

          <div className="surveillance-section">
            <h3>🎤 Audio Monitor</h3>

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
            <p>• Camera feed is local only - not streamed anywhere</p>
            <p>• Audio monitoring uses your browser&apos;s microphone</p>
            <p>• Select different cameras from the dropdown above</p>
            <p>• Audio level shows real-time sound detection</p>
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

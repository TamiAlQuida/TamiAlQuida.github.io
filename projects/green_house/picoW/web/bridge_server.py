import http.server
import subprocess
import json
import os

# Configuration
PORT = 8000

# Paths to your scripts
SCRIPTS = {
    "python": "/home/tom/TamiAlQuida.github.io/projects/old_historic/bolan.py",
    "bash": "/home/tom/TamiAlQuida.github.io/projects/old_historic/bme280_sensor.sh",
    "cpp": "/home/tom/TamiAlQuida.github.io/projects/old_historic/controller.cpp" # Placeholder
}

class BridgeHandler(http.server.SimpleHTTPRequestHandler):
    """
    A simple web server that serves frontend files AND executes local commands.
    """
    def do_POST(self):
        if self.path == '/run-script':
            # Parse request
            content_length = int(self.headers['Content-Length'])
            post_data = self.rfile.read(content_length)
            try:
                data = json.loads(post_data)
                script_type = data.get('type')
                
                if script_type in SCRIPTS:
                    target_path = SCRIPTS[script_type]
                    print(f"Executing {script_type} script: {target_path}")
                    
                    # Construct command to run in a new terminal
                    if script_type == "python":
                        # Run python and wait at the end so you can see output
                        exec_cmd = f"python3 {target_path}; echo; echo 'Process finished. Press Enter to close...'; read"
                    elif script_type == "bash":
                        exec_cmd = f"bash {target_path}; echo; echo 'Process finished. Press Enter to close...'; read"
                    elif script_type == "cpp":
                        # C++ files usually need compilation, but we can try to run it if it's already an executable
                        # or just open it in an editor. For now, let's just echo it.
                        exec_cmd = f"echo 'C++ Script would run here'; echo '{target_path}'; echo; echo 'Press Enter to close...'; read"
                    
                    # Launch Alacritty terminal
                    subprocess.Popen(['alacritty', '-e', 'bash', '-c', exec_cmd])
                    
                    self.send_response(200)
                    self.send_header('Content-type', 'application/json')
                    self.send_header('Access-Control-Allow-Origin', '*')
                    self.end_headers()
                    self.wfile.write(json.dumps({"status": "success", "message": f"Started {script_type}"}).encode())
                else:
                    self.send_error(400, "Unknown script type")
            except Exception as e:
                print(f"Error: {e}")
                self.send_error(500, str(e))
        else:
            self.send_error(404)

    def do_OPTIONS(self):
        # Handle CORS
        self.send_response(200)
        self.send_header('Access-Control-Allow-Origin', '*')
        self.send_header('Access-Control-Allow-Methods', 'POST, OPTIONS')
        self.send_header('Access-Control-Allow-Headers', 'Content-Type')
        self.end_headers()

if __name__ == "__main__":
    # Change directory to the web folder to serve files correctly
    os.chdir(os.path.dirname(os.path.abspath(__file__)))
    
    print("==================================================")
    print(f"  BRIDGE SERVER RUNNING ON http://localhost:{PORT}")
    print("  1. Serves your HTML/JS/CSS files")
    print("  2. Runs local scripts when requested")
    print("==================================================")
    
    server = http.server.HTTPServer(('0.0.0.0', PORT), BridgeHandler)
    server.serve_forever()

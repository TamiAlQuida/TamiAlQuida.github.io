# Connect from another computer
import socket

HOST_IP = '100.93.196.94'  # Replace with the server's IP address
PORT = 10001

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST_IP, PORT))
    # Now you can receive the video stream data
    with open("received_video.h264", "wb") as f:
        while True:
            data = s.recv(4096)
            if not data:
                break
            f.write(data)
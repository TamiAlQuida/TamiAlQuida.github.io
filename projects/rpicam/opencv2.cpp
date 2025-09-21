#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    // GStreamer pipeline for Raspberry Pi Camera Module using v4l2
    std::string pipeline = "v4l2src device=/dev/video0 ! video/x-raw, width=640, height=480 ! videoconvert ! appsink";

    // Use the pipeline string to open the camera
    cv::VideoCapture cap(pipeline, cv::CAP_GSTREAMER);

    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open camera with GStreamer pipeline." << std::endl;
        return -1;
    }

    std::cout << "Starting video capture..." << std::endl;

    cv::Mat frame;
    while (true) {
        cap >> frame;

        if (frame.empty()) {
            std::cerr << "Error: No frame captured." << std::endl;
            break;
        }

        // Display frame for testing, or write to file as before
        cv::imshow("Live Feed", frame);
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }
    cap.release();
    return 0;
}
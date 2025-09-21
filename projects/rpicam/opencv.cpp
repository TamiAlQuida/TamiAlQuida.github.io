#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::VideoCapture cap(0); // Open the default camera (index 0)

    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open camera." << std::endl;
        return -1;
    }

    // Define video properties
    int frame_width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    int frame_height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
    double fps = cap.get(cv::CAP_PROP_FPS);

    // Create a VideoWriter object to save the output video
    cv::VideoWriter writer("test.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, cv::Size(frame_width, frame_height));

    if (!writer.isOpened()) {
        std::cerr << "Error: Could not create video writer." << std::endl;
        return -1;
    }

    std::cout << "Starting video capture..." << std::endl;
    cv::Mat frame;
    long long start_time = cv::getTickCount();

    while (true) {
        cap >> frame; // Read a new frame from the camera

        if (frame.empty()) {
            std::cerr << "Error: No frame captured." << std::endl;
            break;
        }

        writer.write(frame); // Write the frame to the video file

        // Capture for approximately 10 seconds
        if ((cv::getTickCount() - start_time) / cv::getTickFrequency() > 10) {
            std::cout << "Video capture complete." << std::endl;
            break;
        }
    }

    cap.release();
    writer.release();
    return 0;
}
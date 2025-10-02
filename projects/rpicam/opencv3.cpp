#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::VideoCapture cap(0, cv::CAP_V4L2); // Use /dev/video0

    cap.set(cv::CAP_PROP_FRAME_WIDTH, 160);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 120);

    std::cout << "VideoCapture opened: " << cap.isOpened() << std::endl;

    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open camera device." << std::endl;
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

        cv::imshow("Live Feed", frame);
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }
    cap.release();
    return 0;
}
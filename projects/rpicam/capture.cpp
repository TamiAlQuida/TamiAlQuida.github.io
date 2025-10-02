// capture_rpicam.cpp
#include <cstdlib>
#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sys/stat.h>

// Helper to check file exists
bool file_exists(const std::string &p) {
    struct stat st;
    return stat(p.c_str(), &st) == 0;
}

int main() {
    std::string out = "/tmp/zero2w_capture.jpg";

    // Make sure rpicam-still is installed; if not: `sudo apt install rpicam-apps`
    // Construct the command. Adjust options as you like (exposure, width/height etc).
    std::string cmd = "rpicam-still -o " + out + " --nopreview";

    std::cout << "Running: " << cmd << std::endl;
    int rc = std::system(cmd.c_str());
    if (rc != 0) {
        std::cerr << "rpicam-still failed with code " << rc << std::endl;
        return 1;
    }

    if (!file_exists(out)) {
        std::cerr << "Output file not created: " << out << std::endl;
        return 2;
    }

    // Read file into memory (example)
    std::ifstream ifs(out, std::ios::binary | std::ios::ate);
    if (!ifs) {
        std::cerr << "Failed to open output file" << std::endl;
        return 3;
    }
    std::ifstream::pos_type pos = ifs.tellg();
    std::vector<char> data(pos);
    ifs.seekg(0, std::ios::beg);
    ifs.read(&data[0], pos);

    std::cout << "Captured " << data.size() << " bytes in " << out << std::endl;

    // Optionally: write it somewhere else (or process with libjpeg/OpenCV)
    std::string saved = "/home/zero2w/capture_copy.jpg";
    std::ofstream ofs(saved, std::ios::binary);
    ofs.write(data.data(), data.size());
    ofs.close();
    std::cout << "Copied to " << saved << std::endl;

    return 0;
}
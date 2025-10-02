// capture_file.cpp
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <sys/stat.h>

bool file_exists(const std::string &path) {
    struct stat st;
    return stat(path.c_str(), &st) == 0;
}

int main() {
    const std::string out = "/tmp/zero2w_vid.h264";
    std::cout << 1 << std::endl;

    // Run rpicam-still
    std::string cmd = "rpicam-vid -t 10000 -o test.h264";
    std::cout << "Running: " << cmd << std::endl;
    int rc = std::system(cmd.c_str());
    std::cout << 2 << std::endl;
    if (rc != 0) {
        std::cerr << "rpicam-still failed with code " << rc << std::endl;
        return 1;
    }

    if (!file_exists(out)) {
        std::cerr << "Output file not created: " << out << std::endl;
        return 2;
    }

    //for (size_t i = 0; i < 3; i++)
    //{
    //    // Read JPEG into memory
    //std::ifstream ifs(out, std::ios::binary | std::ios::ate);
    //std::cout << 3 << std::endl;
    //std::vector<char> buffer(ifs.tellg());
    //ifs.seekg(0, std::ios::beg);
    //std::cout << 4 << std::endl;
    //ifs.read(buffer.data(), buffer.size());
//
    //std::cout << "Captured " << buffer.size() << " bytes." << std::endl;
//
    //std::string stringy = "/home/zero2w/capture_copy_" + std::to_string(i) + ".jpg";
//
    //// Optional: save to another file
    //std::ofstream ofs(stringy, std::ios::binary);
    //std::cout << 5 << std::endl;
    //ofs.write(buffer.data(), buffer.size());
    //std::cout << 6 << std::endl;
    //std::cout << "Saved copy to " + stringy << std::endl;
    //}
    
    // Read JPEG into memory
    std::ifstream ifs(out, std::ios::binary | std::ios::ate);
    std::cout << 3 << std::endl;
    std::vector<char> buffer(ifs.tellg());
    ifs.seekg(0, std::ios::beg);
    std::cout << 4 << std::endl;
    ifs.read(buffer.data(), buffer.size());

    std::cout << "Captured " << buffer.size() << " bytes." << std::endl;

    // Optional: save to another file
    std::ofstream ofs("/home/zero2w/capture_copy.jpg", std::ios::binary);
    std::cout << 5 << std::endl;
    ofs.write(buffer.data(), buffer.size());
    std::cout << 6 << std::endl;
    std::cout << "Saved copy to /home/zero2w/capture_copy.jpg" << std::endl;

    return 0;
}
#include "httplib.h"
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>

// Helper to extract a single string value from a simple JSON like {"type":
// "value"}
std::string get_json_value(const std::string &body, const std::string &key) {
  std::string search_key = "\"" + key + "\":";
  size_t pos = body.find(search_key);
  if (pos == std::string::npos)
    return "";

  size_t start = body.find("\"", pos + search_key.length());
  if (start == std::string::npos)
    return "";

  size_t end = body.find("\"", start + 1);
  if (end == std::string::npos)
    return "";

  return body.substr(start + 1, end - start - 1);
}

int main() {
  httplib::Server svr;

  // Configuration
  const int PORT = 8000;
  std::map<std::string, std::string> scripts = {
      {"python",
       "/home/tom/TamiAlQuida.github.io/projects/old_historic/bolan.py"},
      {"bash", "/home/tom/TamiAlQuida.github.io/projects/old_historic/"
               "bme280_sensor.sh"},
      {"cpp",
       "/home/tom/TamiAlQuida.github.io/projects/old_historic/controller.cpp"}};

  // 1. Serve static files from the current directory
  auto ret = svr.set_mount_point("/", "./");
  if (!ret) {
    std::cerr << "Error: Directory not found." << std::endl;
    return 1;
  }

  // 2. Handle POST requests to /run-script
  svr.Post("/run-script", [&](const httplib::Request &req,
                              httplib::Response &res) {
    std::string script_type = get_json_value(req.body, "type");

    // Add CORS headers
    res.set_header("Access-Control-Allow-Origin", "*");

    if (scripts.find(script_type) != scripts.end()) {
      std::string target_path = scripts[script_type];
      std::cout << "Executing " << script_type << " script: " << target_path
                << std::endl;

      std::string exec_cmd;
      if (script_type == "python") {
        exec_cmd =
            "python3 " + target_path +
            "; echo; echo 'Process finished. Press Enter to close...'; read";
      } else if (script_type == "bash") {
        exec_cmd =
            "bash " + target_path +
            "; echo; echo 'Process finished. Press Enter to close...'; read";
      } else {
        exec_cmd = "echo 'C++ Script info: " + target_path +
                   "'; echo; echo 'Press Enter to close...'; read";
      }

      // Launch Alacritty in background
      std::string full_cmd = "alacritty -e bash -c \"" + exec_cmd + "\" &";
      std::system(full_cmd.c_str());

      res.set_content("{\"status\": \"success\", \"message\": \"Started " +
                          script_type + "\"}",
                      "application/json");
    } else {
      res.status = 400;
      res.set_content(
          "{\"status\": \"error\", \"message\": \"Unknown script type\"}",
          "application/json");
    }
  });

  // 3. Handle OPTIONS for CORS (pre-flight)
  svr.Options("/run-script",
              [](const httplib::Request &, httplib::Response &res) {
                res.set_header("Access-Control-Allow-Origin", "*");
                res.set_header("Access-Control-Allow-Methods", "POST, OPTIONS");
                res.set_header("Access-Control-Allow-Headers", "Content-Type");
                res.status = 200;
              });

  std::cout << "=================================================="
            << std::endl;
  std::cout << "  C++ BRIDGE SERVER RUNNING ON http://localhost:" << PORT
            << std::endl;
  std::cout << "  1. Serves static files" << std::endl;
  std::cout << "  2. Runs local scripts via alacritty" << std::endl;
  std::cout << "=================================================="
            << std::endl;

  svr.listen("0.0.0.0", PORT);

  return 0;
}

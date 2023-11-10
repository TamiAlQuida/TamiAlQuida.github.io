#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // For system()

#ifdef _WIN32
#include <windows.h> //if compiling with windows (Sleep)
#else
#include <unistd.h> //if compiling with ubuntu (usleep)
#endif

const std::string imagePath = "../images/cat.jpg";
const std::string scriptPath = "../scripts/foraldradagar.py";

void sleep_ms(int milliseconds)
{
    #ifdef _WIN32
    Sleep(milliseconds); //if compiling with windows (Sleep / usleep)
    #else
    usleep(milliseconds * 1000); //if compiling with ubuntu (Sleep / usleep)
    #endif
}

void last_function()
{
    std::vector<std::string> msg {"I  said,", " that you are", "a real mothafucka!"};
    
    for (const std::string& word : msg)
    {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}

void openImage() {
    #ifdef _WIN32
    std::string command = "start " + imagePath;
    #else
    std::string command = "xdg-open " + imagePath;
    #endif
    system(command.c_str());
}

void runPythonScript() {
    // Command to run a Python script. Assumes 'python' command is available.
    #ifdef _WIN32
    std::string command = "python " + scriptPath;
    #else
    std::string command = "python3.11 " + scriptPath;
    #endif
    system(command.c_str());
}

int main()
{
    std::cout << "Hello,  my friend! wait 5 sec please.\n";
    sleep_ms(5000);
    std::cout << "You mothafucka";
    std::cout << std::endl; //Inserts line like \n and "flushes the buffer"
    sleep_ms(3000);

    last_function();
    sleep_ms(3000);
    runPythonScript();
    openImage();

    return 0; // supposedly here to add an exit code so that the program ends without errors
}
#include <iostream>
#include <vector>
#include <string>

#ifdef _WIN32
#include <windows.h> //if compiling with windows (Sleep / usleep)
#else
#include <unistd.h> //if compiling with ubuntu (Sleep / usleep)
#endif

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

int main()
{
    std::cout << "Hello,  my friend! wait 5 sec please.\n";
    sleep_ms(5000);
    std::cout << "You mothafucka";
    std::cout << std::endl; //Inserts line like \n and "flushes the buffer"
    sleep_ms(3000);

    last_function();
    sleep_ms(3000);

    return 0; // supposedly here to add an exit code so that the program ends without errors
}
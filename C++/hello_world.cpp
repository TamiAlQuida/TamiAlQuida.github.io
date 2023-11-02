#include <iostream>
#include <vector>
#include <string>
#ifdef _WIN32
#include <windows.h>
#else
#include <linux_header.h>
#endif

void last_function()
{
    std::vector<std::string> msg {"Hello,", "C++ World from VS Code", "and the C++ extension!"};
    
    for (const std::string& word : msg)
    {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "Hello,  my friend! wait 5 sec please.\n";
    Sleep(5000);
    std::cout << "You mothafucka";
    std::cout << std::endl; //Inserts line like \n and "flushes the buffer"
    Sleep(3000);

    last_function();
    Sleep(3000);

    return 0; // supposedly here to add an exit code so that the program ends without errors
}
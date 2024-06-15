#include <iostream>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

int main() {
    // Create/open a shared memory region
    int shm_fd = shm_open("/tickers", O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        std::cerr << "Error creating shared memory" << std::endl;
        return 1;
    }

    // Set the size of the shared memory region
    ftruncate(shm_fd, sizeof(char) * 1024);

    // Map the shared memory region into the address space
    // Line below tells the system to use "shared memory", which which is fast, and stored in the RAM which is stored in /dev/shm/
    char* shared_memory = (char*) mmap(NULL, sizeof(char) * 1024, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shared_memory == MAP_FAILED) {
        std::cerr << "Error mapping shared memory" << std::endl;
        return 1;
    }

    // Write the tickers list into the shared memory region
    std::string tickers = "TSM,MSFT,META,NVDA,GOOG";
    std::strcpy(shared_memory, tickers.c_str()); //copies the string above into "shared memory" and creates a binary file called (/dev/shm/)tickers

    // Unmap and close the shared memory region
    munmap(shared_memory, sizeof(char) * 1024);
    close(shm_fd);

    // Unmap the shared memory
    //munmap(shared_memory, sizeof(char) * 1024);

    // Close the shared memory file descriptor
    //close(shm_fd);

    // Unlink the shared memory object
    shm_unlink("/tickers");

    return 0;
}
#include <iostream>
#include <thread>
#include "timer.h"

int main(int argc, char **argv)
{
    std::cout << "Starting Timer example" << std::endl;
    
    Timer timer([](){
        std::cout << "External Function" << std::endl;
    });

    timer.start(2000);

    std::this_thread::sleep_for(std::chrono::milliseconds(4500));

    timer.stop();

    std::cout << "Ending Timer example" << std::endl;

    timer.start(100);

    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    return 0;
}
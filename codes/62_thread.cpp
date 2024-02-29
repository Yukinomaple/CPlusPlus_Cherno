#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork()
{
    using namespace std::literals::chrono_literals;
    while (!s_Finished)
    {
        std::cout << "Working..." << std::endl;
        std::this_thread::sleep_for(1s);
    }
    std::cout << "DoWork Thread id: " << std::this_thread::get_id() << std::endl;
}


int main()
{
    std::thread Worker(DoWork);
    
    std::cin.get();
    s_Finished = true;

    Worker.join();
    std::cout << "Finished." << std::endl;
    std::cout << "Main Thread id: " << std::this_thread::get_id() << std::endl;
    std::cin.get();
}
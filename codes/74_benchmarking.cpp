#include <iostream>
#include <chrono>
#include <array>
#include <memory>
//确保测量的时候是你写的东西，否则release版本编译器可能优化了许多操作

class Timer
{
private:
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;
public:
    Timer()
    {
        start = std::chrono::steady_clock::now();
    }
    ~Timer()
    {
        end = std::chrono::steady_clock::now();
        auto total = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        std::cout << "Time took: " << total << " us (" << total*0.001f <<" ms)" << std::endl;
    }

};

int main()
{
    int value = 0;
    {
        Timer timer;
        for(int i = 0; i < 10000000; i++)
        {
            value += 2;
        }
    }
    struct Vector2
    {
        float x, y;
    };
    
    std::cout << "Make Shared\n";
    {
        std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
        Timer timer;
        for(int i = 0; i < sharedPtrs.size(); i++)
        {
            sharedPtrs[i] = std::make_shared<Vector2>();
        }
    }
    
    std::cout << "New Shared\n";
    {
        std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
        Timer timer;
        for(int i = 0; i < sharedPtrs.size(); i++)
        {
            sharedPtrs[i] = std::shared_ptr<Vector2>(new Vector2());
        }
    }

    std::cout << "Make Unique\n";
    {
        std::array<std::unique_ptr<Vector2>, 1000> uniquePtrs;
        Timer timer;
        for(int i = 0; i < uniquePtrs.size(); i++)
        {
            uniquePtrs[i] = std::make_unique<Vector2>();
        }
    }

    


}
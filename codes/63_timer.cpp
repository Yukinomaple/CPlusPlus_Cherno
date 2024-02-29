#include <iostream>
#include <thread>
#include <chrono>

/*
high_resolution_clock不同平台实现不一样
尽量使用steady_clock和system_clock


steady_clock：
    是一个稳定的时钟，它提供了一个单调递增的时间。这意味着它不受系统时间的影响，并且不会因为系统时间的调整（比如修改系统时钟或者发生夏令时调整）而产生变化。
适用于测量时间间隔或者计时操作，特别是对于需要高精度的计时要求，因为它保证了单调递增，不受系统时间影响。

system_clock：
    是一个表示系统时钟的类型，它提供了系统当前的时间。这个时间与系统的时钟设置相关，并且受到系统时间的影响，比如可能会受到时区、夏令时等的调整。
适用于需要获取当前的系统时间，比如日历时钟操作、记录事件的时间戳等。
*/
struct Timer
{
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;
    //std::chrono::milliseconds duration;
    Timer()
    {
        start = std::chrono::steady_clock::now();
    }

    ~Timer()
    {
        end = std::chrono::steady_clock::now();
        
        //duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        //std::cout << "Timer took: " << duration.count() << " ms" << std::endl;
        
        //Cherno的做法
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        std::cout << "Timer took: " << ms << " ms" << std::endl;

    }
};


void Function()
{
    Timer timer;
    for(int i = 0; i < 100; i++)
    {
        std::cout << "hello\n";
    }
    
}


int main()
{
    Function();



#if 0
    using namespace std::literals::chrono_literals;

    auto start = std::chrono::high_resolution_clock::now();

    std::this_thread::sleep_for(1s);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start;

    std::cout << "work time: " << duration.count() << " s" << std::endl;
#endif
}

/*
#include <iostream>
#include <chrono>

int main() {
    // 获取程序开始执行的时间点
    auto start = std::chrono::high_resolution_clock::now();

    // 执行一些需要计时的操作，比如一个复杂的计算或者其他耗时操作

    // 获取程序结束执行的时间点
    auto end = std::chrono::high_resolution_clock::now();

    // 计算时间间隔，即执行耗时
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // 输出执行耗时
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
*/
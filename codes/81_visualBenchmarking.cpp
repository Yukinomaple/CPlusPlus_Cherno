#include <iostream>
#include <chrono>
#include <string>
//Î´Íê³É
class Timer
{
public:
    explicit Timer(const char* name) : m_Name(name), m_Stopped(false)
    {
        m_StartTimePoint = std::chrono::steady_clock::now();
    }
    ~Timer()
    {
        if(!m_Stopped)
        {
            Stop();
        }
    }
    void Stop()
    {
        auto endTimePoint = std::chrono::steady_clock::now();
        long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
        long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();
        std::cout << m_Name << ": " << (end - start) << " us (" << (end - start) * 0.001f << " ms)" << std::endl; 
        m_Stopped = true;
    }
private:
    std::chrono::time_point<std::chrono::steady_clock> m_StartTimePoint;
    const char* m_Name;
    bool m_Stopped;
};

void Function1()
{
    Timer timer("Function1");
    for(int i = 0; i < 10000000; i++)
    {
        i+=2;
    }
}

int main()
{
    Function1();
}


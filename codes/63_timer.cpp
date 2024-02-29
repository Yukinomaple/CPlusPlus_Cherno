#include <iostream>
#include <thread>
#include <chrono>

/*
high_resolution_clock��ͬƽ̨ʵ�ֲ�һ��
����ʹ��steady_clock��system_clock


steady_clock��
    ��һ���ȶ���ʱ�ӣ����ṩ��һ������������ʱ�䡣����ζ��������ϵͳʱ���Ӱ�죬���Ҳ�����Ϊϵͳʱ��ĵ����������޸�ϵͳʱ�ӻ��߷�������ʱ�������������仯��
�����ڲ���ʱ�������߼�ʱ�������ر��Ƕ�����Ҫ�߾��ȵļ�ʱҪ����Ϊ����֤�˵�������������ϵͳʱ��Ӱ�졣

system_clock��
    ��һ����ʾϵͳʱ�ӵ����ͣ����ṩ��ϵͳ��ǰ��ʱ�䡣���ʱ����ϵͳ��ʱ��������أ������ܵ�ϵͳʱ���Ӱ�죬������ܻ��ܵ�ʱ��������ʱ�ȵĵ�����
��������Ҫ��ȡ��ǰ��ϵͳʱ�䣬��������ʱ�Ӳ�������¼�¼���ʱ����ȡ�
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
        
        //Cherno������
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
    // ��ȡ����ʼִ�е�ʱ���
    auto start = std::chrono::high_resolution_clock::now();

    // ִ��һЩ��Ҫ��ʱ�Ĳ���������һ�����ӵļ������������ʱ����

    // ��ȡ�������ִ�е�ʱ���
    auto end = std::chrono::high_resolution_clock::now();

    // ����ʱ��������ִ�к�ʱ
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // ���ִ�к�ʱ
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
*/
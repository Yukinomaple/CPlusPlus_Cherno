#include <iostream>
#include <array>

template<typename T, int N>
void PrintArray(const std::array<T, N>& data)
{
    for(int i = 0; i < N; i++)
    {
        std::cout << data[i] << std::endl;
    }
}

int main()
{
    std::array<int, 5> data;
    data[0] = 0;
    data[1] = 1;
    data[2] = 2;
    data[3] = 3;
    data[4] = 4;

    PrintArray<int, data.size()>(data);

}
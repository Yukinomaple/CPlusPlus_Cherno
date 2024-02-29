#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
    std::vector<int> values{3, 5, 1, 4, 2};

    //std::sort(values.begin(), values.end(), std::greater<int>());
    std::sort(values.begin(), values.end(), [](int a, int b)//
    {
        /*想要把1排到最后
        谓词中return true 就是第一个参数， return false就是第二个参数
        */
        if (a == 1)
            return false;
        if (b == 1)
            return true;
        return a < b;
    });

    for(int& a : values)
    {
        std::cout << a << std::endl;
    }
}
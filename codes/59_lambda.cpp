#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
/*
用到函数指针的地方就可以使用lambda

*/


void ForEach(const std::vector<int>& values, const std::function<void(int)>& Func)
{
    for(const int& val : values)
    {
        Func(val);
    }
}

int main()
{
    std::vector<int> values = {1,5,4,2,3};
    
    auto it = std::find_if(values.begin(), values.end(), [](int value){ return value > 3;});//std::find_if 函数接受三个参数：第一个参数是容器的起始迭代器，第二个参数是容器的结束迭代器，第三个参数是一个谓词（即函数对象或 Lambda 表达式），用于指定搜索条件。
    //如果找到了满足条件的元素，则返回该元素的迭代器；如果没有找到满足条件的元素，则返回容器的结束迭代器。
    std::cout << *it << std::endl;
    
    
    
    int a = 5;
    auto lambda = [=](int value){ std::cout << "Value:" << a << std::endl; };
    ForEach(values,lambda); //不存在从 "lambda [](int value)->void" 到 "void (*)(int)" 的适当转换函数: 使用std::function

    return 0;
}

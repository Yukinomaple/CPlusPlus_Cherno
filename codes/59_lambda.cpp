#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
/*
�õ�����ָ��ĵط��Ϳ���ʹ��lambda

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
    
    auto it = std::find_if(values.begin(), values.end(), [](int value){ return value > 3;});//std::find_if ��������������������һ����������������ʼ���������ڶ��������������Ľ�����������������������һ��ν�ʣ������������ Lambda ���ʽ��������ָ������������
    //����ҵ�������������Ԫ�أ��򷵻ظ�Ԫ�صĵ����������û���ҵ�����������Ԫ�أ��򷵻������Ľ�����������
    std::cout << *it << std::endl;
    
    
    
    int a = 5;
    auto lambda = [=](int value){ std::cout << "Value:" << a << std::endl; };
    ForEach(values,lambda); //�����ڴ� "lambda [](int value)->void" �� "void (*)(int)" ���ʵ�ת������: ʹ��std::function

    return 0;
}

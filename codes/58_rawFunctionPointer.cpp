#include <iostream>
#include <vector>

/*
��������ַ��ֵ��һ����������ʹ��auto�ؼ���
ʹ��typedefʹ����ɶ��Ը���

�����������ʱ�������䶯
lambda�滻

*/

void HelloWorld(int a)
{
    std::cout << "Hello World : " << a << std::endl;
}

void PrintValue(int a)
{
    std::cout << a << std::endl;
}

void ForEach(const std::vector<int>& values, void(*Func)(int))
{
    for(const int& val : values)
    {
        Func(val);
    }

}


int main()
{
    typedef void(*HelloWorldFunciton)(int);
    //auto Function = &HelloWorld;
    //void(*Function)() = HelloWorld;
    HelloWorldFunciton Function = HelloWorld;
    Function(8);


    std::vector<int> values = {1,5,4,2,3};
    //ForEach(values, PrintValue);
    ForEach(values,[](int a){ std::cout << "Value:" << a << std::endl; });

    return 0;
}
#include <iostream>
#include <string>

//一、初级用法
template<typename T>
void Print(T value)
{
    std::cout << value << std::endl;
}

//二、数组
template<typename T, int N>
class Array
{
private:
    T m_Array[N];
public:
    Array() {}
    const int GetSize() const 
    { 
        return N; 
    }
};




int main()
{
    Print(5);
    Print<std::string>("Hello");

    const Array<int,10> arr;
    Array<std::string, 100> arr1;
    std::cout << arr.GetSize() << std::endl;
    std::cout << arr1.GetSize() << std::endl;
    
}
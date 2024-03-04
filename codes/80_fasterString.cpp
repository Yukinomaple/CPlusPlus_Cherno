#include <iostream>
#include <string>

//获取字符串的内存视图，而不是创建一个新的字符串
static uint32_t s_AllocCount = 0;

void* operator new(size_t size)
{
    s_AllocCount++;
    std::cout << "Allocating " << size << " bytes\n";
    return malloc(size);
}

// void PrintName(const std::string& name)
// {
//     std::cout << name << std::endl;
// }

void PrintName(std::string_view name)
{
    std::cout << name << std::endl;
}

int main()
{
    /*
    std::string name = "aaaaabbbbbcccccd";
    std::string firstName = name.substr(0,9);
    std::string lastName = name.substr(10,15);
    PrintName(name);
    */
    std::string name = "Yan Chernikov123456";
    //const char* name = "Yan Chernikov123456";
    std::string_view firstName(name.c_str(), 3);
    std::string_view lastName(name.c_str() + 4, 9);
    PrintName(firstName);

    std::cout << s_AllocCount << " allocations" << std::endl;
}
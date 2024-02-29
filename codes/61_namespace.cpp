#include <iostream>
#include <string>
#include <algorithm>
//解决命名冲突问题，永远不要在头文件 顶部使用using namespace 


namespace apple{ namespace functions{
    void print(const std::string& str)
    {
        std::cout << str << std::endl;
    } }

    void print_again()
    {

    }
}
namespace orange{
    void print(const char* text)
    {
        std::string str = text;
        std::reverse(str.begin(), str.end());
        std::cout << str << std::endl;
    }
}

int main()
{
    using namespace apple::functions;
    //using apple::print;//仅使用命名空间里的一个函数
    print("hello");
    
    namespace a = apple::functions;//给命名空间取别名
    a::print("apple");



}
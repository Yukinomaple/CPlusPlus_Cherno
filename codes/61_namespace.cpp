#include <iostream>
#include <string>
#include <algorithm>
//���������ͻ���⣬��Զ��Ҫ��ͷ�ļ� ����ʹ��using namespace 


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
    //using apple::print;//��ʹ�������ռ����һ������
    print("hello");
    
    namespace a = apple::functions;//�������ռ�ȡ����
    a::print("apple");



}
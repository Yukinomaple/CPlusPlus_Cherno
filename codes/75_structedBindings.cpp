//only for C++17
#include <iostream>
#include <string>
#include <tuple>

//3. ����һ���ṹ��ʹ��,person.name person.age����
struct Person
{
    std::string name;
    int age;
};

std::tuple<std::string, int> CreatePerson()
{
    return { "Cherno", 24 };
}

int main()
{
    //1. std::tupleȡ�����е㷱��
    auto person = CreatePerson();
    std::string& name = std::get<0>(person);
    int age = std::get<1>(person);
    
    //2. std::tie,���й۸в���
    std::string name1;
    int age1;
    std::tie(name1, age1) = CreatePerson();
    

    //3.c++17����
    auto[name3, age3] = CreatePerson();
    std::cout << "Name: " << name3 << " Age: " << age3 << std::endl;
}
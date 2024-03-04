//only for C++17
#include <iostream>
#include <string>
#include <tuple>

//3. 返回一个结构体使用,person.name person.age访问
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
    //1. std::tuple取数据有点繁琐
    auto person = CreatePerson();
    std::string& name = std::get<0>(person);
    int age = std::get<1>(person);
    
    //2. std::tie,三行观感不好
    std::string name1;
    int age1;
    std::tie(name1, age1) = CreatePerson();
    

    //3.c++17特性
    auto[name3, age3] = CreatePerson();
    std::cout << "Name: " << name3 << " Age: " << age3 << std::endl;
}
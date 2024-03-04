#include <iostream>
//基类析构函数加上virtual，通过基类指针去删除派生类对象时候，才能先调用派生类的析构函数，再调用基类的析构函数
class Base
{
public:
    Base()
    {
        std::cout << "Base Constructor\n";
    }
    virtual ~Base()
    {
        std::cout << "Base Destructor\n";
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "Derived Constructor\n";
    }
    ~Derived()
    {
        std::cout << "Derived Destructor\n";
    }
};

int main()
{
    Base* base = new Base();
    delete base;
    std::cout << "--------------------------\n";
    Derived* derived = new Derived();
    delete derived;
    std::cout << "--------------------------\n";
    Base* poly = new Derived();
    delete poly;
}

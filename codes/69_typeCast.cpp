#include <iostream>

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

class Another : public Base
{
public:
    Another() {}
    ~Another() {}
};

int main()
{
    double value = 5.25;
    double a = (int)value + 5.3;

    double s = static_cast<int>(value) + 5.3;
    std::cout << s << std::endl;

    Derived* derived = new Derived();
    Base* base = derived;
    Another* ac = dynamic_cast<Another*>(base);
    if(!ac)
    {
        std::cout << "empty ptr ac" << std::endl;
    }






}
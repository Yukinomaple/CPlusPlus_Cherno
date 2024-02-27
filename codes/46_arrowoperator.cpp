#include <iostream>

/*
运算符重载箭头操作符
*/

class Entity
{
public:
    int x;
public:
    void Print() const
    {
        std::cout << "Hello" << std::endl;
    }
};

class ScopedPtr
{
private:
    Entity* m_Obj;
public:
    ScopedPtr(Entity* entity) : m_Obj(entity)
    {

    }
    ~ScopedPtr()
    {
        delete m_Obj;
    }
    Entity* GetObject() { return m_Obj; }

    const Entity* operator->() const
    {
        return m_Obj;
    }

};

struct Vector3
{
    float x, y, z;
};

int main()
{
    const ScopedPtr entity = new Entity();
   // entity.GetObject()->Print();
    entity->Print();

    int offset = (size_t)&((Vector3*)nullptr)->y;
    std::cout << offset << std::endl;

    return 0;
}
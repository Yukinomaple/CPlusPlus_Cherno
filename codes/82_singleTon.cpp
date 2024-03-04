#include <iostream>


/*
如果你的程序需要在程序启动时就立即初始化单例实例，你可以使用第一种方式:类内声明，类外定义。如果你想要延迟实例的创建，直到需要时才初始化，你可以选择第二种方式:GetInstance()函数中。
*/
#if 1
class Random
{
public:
    static Random& Get()
    {
        static Random instance;
        return instance;
    }
    static float Float() { return Get().FloatImpl(); }
private:
    Random(const Random&) = delete;
    Random& operator=(const Random&) = delete; 

    float FloatImpl() { return m_RandomGenerator; }
    Random() {}
    float m_RandomGenerator = 0.5f;
};
namespace RandomClass
{
    static float s_RandomGenerator = 1.5f;
    static float Float() { return s_RandomGenerator; }
} // namespace RandomClass


int main()
{
    auto& random = Random::Get();
    float data = random.Float();//如果我想写成Random::Float()怎么办,将Float()移入私有成员,增加公共静态函数

    float data2 = Random::Float();
    std::cout << data2 << std::endl;
}

#else
class Singleton
{
public:
    static Singleton& GetInstance()//1.静态方法确保单例的设计要求
    {
        return s_Instance;
    }
    Singleton(const Singleton& instance) = delete;
    void Function()
    {
    }
private:
    Singleton() {}
    static Singleton s_Instance;
    float m_Number = 0.0f;
};


//2.类外定义
Singleton Singleton::s_Instance;

int main()
{
    Singleton::GetInstance().Function();

    //Singleton instance = Singleton::GetInstance();//3.需要删除复制构造函数
    //instance.GetInstance();
    Singleton& s1 = Singleton::GetInstance();
}
#endif
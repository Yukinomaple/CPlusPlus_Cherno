#include <iostream>


/*
�����ĳ�����Ҫ�ڳ�������ʱ��������ʼ������ʵ���������ʹ�õ�һ�ַ�ʽ:�������������ⶨ�塣�������Ҫ�ӳ�ʵ���Ĵ�����ֱ����Ҫʱ�ų�ʼ���������ѡ��ڶ��ַ�ʽ:GetInstance()�����С�
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
    float data = random.Float();//�������д��Random::Float()��ô��,��Float()����˽�г�Ա,���ӹ�����̬����

    float data2 = Random::Float();
    std::cout << data2 << std::endl;
}

#else
class Singleton
{
public:
    static Singleton& GetInstance()//1.��̬����ȷ�����������Ҫ��
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


//2.���ⶨ��
Singleton Singleton::s_Instance;

int main()
{
    Singleton::GetInstance().Function();

    //Singleton instance = Singleton::GetInstance();//3.��Ҫɾ�����ƹ��캯��
    //instance.GetInstance();
    Singleton& s1 = Singleton::GetInstance();
}
#endif
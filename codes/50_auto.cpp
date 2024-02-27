#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

/*
���ͺܳ��������ʹ��auto
using���������ı���
��������ʹ��auto����ή�ʹ���Ŀɶ���
*/

class Device
{

};

class DeviceManager
{
private:
    std::unordered_map<std::string, std::vector<Device*>> m_Devices;
public:
    const std::unordered_map<std::string, std::vector<Device*>>& GetDevice() const
    {
        return m_Devices;
    }
};

int main()
{
    std::vector<std::string> strings;
    strings.push_back("Apple");
    strings.push_back("Orange");

#if 0
    for(std::vector<std::string>::iterator it = strings.begin(); 
        it != strings.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    //1.������ʹ��auto
#else
    for(auto it = strings.begin(); it != strings.end(); it++)
    {
        std::cout << *it << std::endl;
    }
#endif

    //2.GetDevice()����ֵ����̫��
    //��ʹ��using
    using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;

    DeviceManager dm;
    //const std::unordered_map<std::string, std::vector<Device*>>& devices1 = dm.GetDevice();
    const DeviceMap& devices2 = dm.GetDevice();
    const auto& devices3 = dm.GetDevice();

    std::cin.get();




    return 0;
}
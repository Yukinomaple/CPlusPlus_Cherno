#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

/*
类型很长的情况下使用auto
using创建变量的别名
尽量避免使用auto，这会降低代码的可读性
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
    //1.迭代器使用auto
#else
    for(auto it = strings.begin(); it != strings.end(); it++)
    {
        std::cout << *it << std::endl;
    }
#endif

    //2.GetDevice()返回值类型太长
    //①使用using
    using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;

    DeviceManager dm;
    //const std::unordered_map<std::string, std::vector<Device*>>& devices1 = dm.GetDevice();
    const DeviceMap& devices2 = dm.GetDevice();
    const auto& devices3 = dm.GetDevice();

    std::cin.get();




    return 0;
}
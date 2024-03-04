#include <any>
#include <iostream>
//大空间，std::any会动态分配而std::variant不会。避免复制提高性能
//ps:std::any就是来搞笑的
int main()
{
    std::any data;
    data = 5;
    data = "Cher";
    data = std::string("Cherno");
    std::string& value = std::any_cast<std::string&>(data);
    std::cout << value << std::endl;
}
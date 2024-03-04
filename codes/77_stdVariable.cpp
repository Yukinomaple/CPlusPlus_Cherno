#include <iostream>
#include <variant>

//优化 76optional，现在想知道出错在哪，而不仅仅返回一个空值
enum class ErrorCode
{
    None = 0, NotFound, NoAccess
};


std::variant<std::string, ErrorCode> ReadFileAsString()
{

}


int main()
{
    std::variant<std::string, int> data;
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(std::string) << std::endl;
    std::cout << sizeof(data) << std::endl;
    
    
    data = "Cherno";
    std::cout << std::get<std::string>(data) << std::endl;
    if(auto value = std::get_if<std::string>(&data))
    {
        std::string& v = *value;
    }


    data = 2;
    std::cout << std::get<int>(data) << std::endl;
}

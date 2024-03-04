#include <iostream>
#include <fstream>
#include <optional>

#define CPP17 1

#if CPP17 == 0
std::string ReadFileAsString(const std::string& filepath, bool& outSuccess)
{
    std::ifstream stream(filepath);
    if(stream)
    {
        std::string result;

        stream.close();
        outSuccess = true;
        return result;
    }
    outSuccess = false;
    return std::string();
}
#else
std::optional<std::string> ReadFileAsString(const std::string& filepath)
{
    std::ifstream stream(filepath);
    if(stream)
    {
        std::string result;

        stream.close();
        return result;
    }
    return {};
}

#endif

int main()
{
#if CPP17 == 0
    bool success;
    std::string data = ReadFileAsString("data.txt", success);
    if(success)
    {

    }
#else
    std::optional<std::string> data = ReadFileAsString("data.txt");

    std::string value = data.value_or("Not present");
    std::cout << value << std::endl;

    if (data)
    {
        std::cout << "Read Successfully" << std::endl;
    }   
    else
    {
        std::string& string = *data;
        //data.value();
        std::cout << "File could not be opened!" << std::endl;
    }

#endif
}
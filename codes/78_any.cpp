#include <any>
#include <iostream>
//��ռ䣬std::any�ᶯ̬�����std::variant���ᡣ���⸴���������
//ps:std::any��������Ц��
int main()
{
    std::any data;
    data = 5;
    data = "Cher";
    data = std::string("Cherno");
    std::string& value = std::any_cast<std::string&>(data);
    std::cout << value << std::endl;
}
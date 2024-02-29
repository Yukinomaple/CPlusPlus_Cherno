#include <iostream>

/*如果int向double发生隐式类型转换，会在新的内存地址生成新的double数据
    但如果想在原int类型的地址上，按double类型解释，做法有：

*/
struct Entity
{
    int x, y;
};

int main()
{
    int a = 5;
    double b = a;
    double value1 = *(double*)&a;//1.多读取了int后面的4个字节，创建了新的变量value1
    double& value2 = *(double*)&a;//不创建新的变量，如果写的花会写8个字节，而不是原int的4个字节，非常危险
    std::cout << value1 << std::endl;

    Entity e{5,8};//2.结构体内连续存放2个int变量，可用数组的思想访问
    int* position = (int*)&e;
    int y = *(int*)((char*)&e+4);
    std::cout << "y: " << y << std::endl;

    std::cout << position[0] << ", " << position[1] << std::endl; 

}
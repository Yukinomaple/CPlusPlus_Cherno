#include <iostream>

/*���int��double������ʽ����ת���������µ��ڴ��ַ�����µ�double����
    ���������ԭint���͵ĵ�ַ�ϣ���double���ͽ��ͣ������У�

*/
struct Entity
{
    int x, y;
};

int main()
{
    int a = 5;
    double b = a;
    double value1 = *(double*)&a;//1.���ȡ��int�����4���ֽڣ��������µı���value1
    double& value2 = *(double*)&a;//�������µı��������д�Ļ���д8���ֽڣ�������ԭint��4���ֽڣ��ǳ�Σ��
    std::cout << value1 << std::endl;

    Entity e{5,8};//2.�ṹ�����������2��int���������������˼�����
    int* position = (int*)&e;
    int y = *(int*)((char*)&e+4);
    std::cout << "y: " << y << std::endl;

    std::cout << position[0] << ", " << position[1] << std::endl; 

}
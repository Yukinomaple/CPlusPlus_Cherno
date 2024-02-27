#include <iostream>
#include <vector>

/*
vector������Ż�����ôÿ���һ����Ԫ�ض���Ծ�Ԫ�ؽ��и��ƣ����·����´�С���ڴ�

for(Vector3& v : vertices)

ostream������

erase����Ҫ����������
*/

#define LOG(x) std::cout << x << std::endl;



class Vector3
{
public:
    float x, y, z;
    Vector3(float x, float y, float z) : x(x), y(y), z(z)
    {
    }
    Vector3(const Vector3& vertex) : x(vertex.x), y(vertex.y), z(vertex.z)//[ERROR]:һ��ʼû�г�ʼ���б���vector�и��ƵĶ������ڴ��е�δ��ʼ����ֵ
    {
        std::cout << "copied" << std::endl;
    }


};

std::ostream& operator<<(std::ostream& stream, const Vector3& vertex)
{
    stream << vertex.x << "," << vertex.y << "," << vertex.z;
    return stream;
}

void Function(const std::vector<Vector3>& vertex)
{

}



int main()
{
    //һ��δ�Ż��汾, ����6��(1+2+3)
    std::vector<Vector3> vertices;
    vertices.push_back(Vector3(1, 2, 3));
    vertices.push_back(Vector3(4, 5, 6));
    vertices.push_back(Vector3(7, 8, 9));
    Function(vertices);
#if 0
    for(int i = 0; i < vertices.size(); i++)
    {
        std::cout << vertices[i] << std::endl;
    }
#else   
    for(Vector3& v : vertices)
    {
        std::cout << v << std::endl;
    }
#endif
    vertices.erase(vertices.begin()+2);
    
    //�����Ż��汾, reserveָ��vector������ڴ��С, ����3��
    std::vector<Vector3> betterVertices;
    betterVertices.reserve(3);
    betterVertices.push_back(Vector3(10,20,30));
    betterVertices.push_back(Vector3(40,50,60));
    betterVertices.push_back(Vector3(70,80,90));

    
    //�����Ż��汾����vector���ڴ洦ֱ�Ӵ�������
    std::vector<Vector3> ultraVertices;
    ultraVertices.reserve(3);
    ultraVertices.emplace_back(100,200,300);
    ultraVertices.emplace_back(400,500,600);
    ultraVertices.emplace_back(700,800,900);

    for(auto& v : ultraVertices) { LOG(v); }

}
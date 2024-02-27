#include <iostream>
#include <vector>

/*
vector如果不优化，那么每添加一个新元素都会对旧元素进行复制，重新分配新大小的内存

for(Vector3& v : vertices)

ostream的重载

erase中需要迭代器参数
*/

#define LOG(x) std::cout << x << std::endl;



class Vector3
{
public:
    float x, y, z;
    Vector3(float x, float y, float z) : x(x), y(y), z(z)
    {
    }
    Vector3(const Vector3& vertex) : x(vertex.x), y(vertex.y), z(vertex.z)//[ERROR]:一开始没有初始化列表导致vector中复制的对象是内存中的未初始化的值
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
    //一、未优化版本, 复制6次(1+2+3)
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
    
    //二、优化版本, reserve指定vector分配的内存大小, 复制3次
    std::vector<Vector3> betterVertices;
    betterVertices.reserve(3);
    betterVertices.push_back(Vector3(10,20,30));
    betterVertices.push_back(Vector3(40,50,60));
    betterVertices.push_back(Vector3(70,80,90));

    
    //三、优化版本，在vector的内存处直接创建对象
    std::vector<Vector3> ultraVertices;
    ultraVertices.reserve(3);
    ultraVertices.emplace_back(100,200,300);
    ultraVertices.emplace_back(400,500,600);
    ultraVertices.emplace_back(700,800,900);

    for(auto& v : ultraVertices) { LOG(v); }

}
#include <iostream>
/*
多维数组的堆分配造成内存碎片，cache miss 二维变一维存储
多维数组的内存释放
*/
int main()
{
    int** a2d = new int*[50];
    for(int i = 0; i < 50; i++)
        a2d[i] = new int[50];

    for(int i = 0; i < 50; i++)
    {
        delete[] a2d[i];
    }
    delete[] a2d;



    int*** a3d = new int**[50];
    for(int i = 0; i < 50; i++)
    {
        a3d[i] = new int*[50];
        for(int j = 0; j < 50; j++)
        {
            a3d[i][j] = new int[50];
        }
    }
        
        


}
#include <iostream>
/*
��ά����Ķѷ�������ڴ���Ƭ��cache miss ��ά��һά�洢
��ά������ڴ��ͷ�
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
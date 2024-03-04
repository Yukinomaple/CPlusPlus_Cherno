#include <iostream>
//dynamic_cast �������������п�����ר���ڼ̳в�νṹ���е�ǿ������ת ��Ҫ����RTTI

class Entity
{
    virtual void PrintName() {}
};

class Enemy : public Entity
{

};

class Player : public Entity
{

};

int main()
{
    Player* player = new Player();
    Entity* actuallyEnemy = new Enemy();
    Entity* actuallyPlayer = player;

    Player* p1 = dynamic_cast<Player*>(actuallyEnemy);
    if(!p1)
    {
        std::cout << "p1 empty" << std::endl;
    }

    Player* p2 = dynamic_cast<Player*>(actuallyPlayer);

    if(!p2)
    {
        std::cout << "p2 empty" << std::endl;
    }


}
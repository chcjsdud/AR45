#pragma once
#include <iostream>
#include <conio.h>

class Monster
{
public:
    inline int GetAtt()
    {
        return Att;
    }

    inline bool IsDeath()
    {
        return Hp <= 0;
    }

    // 헤더와 구현이 분리된 함수는 inline화 될수 없다.
    void StatusRender();
    void Damage(int _Damage);

protected:
private:
    int Att = 10;
    int Hp = 100;
};

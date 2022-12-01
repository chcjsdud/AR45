#pragma once

// 클래스 자체가 이미 선언에 가까운 성질을 띄우고 있다.
class Player
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

    void StatusRender();
    void Damage(int _Damage);

protected:
private:
    // 변수는 
    int Att = 10;
    int Hp = 100;
};

// Player NewPlayer;
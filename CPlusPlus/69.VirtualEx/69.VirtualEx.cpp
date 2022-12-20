// 69.VirtualEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class FightUnit
{
protected:
    int Hp = 100;
    int Att = 10;

public:
    virtual int GetAtt()
    {
        return Att;
    }

    virtual int GetHp()
    {
        return Att;
    }

public:
    // 부모의 형태이면서 
    // 특정 상황에서는 다양한 자식들의 형태로 동작해야하는 경우가 존재한다.

    void Fight(FightUnit* _Fight)
    {
        if (this == _Fight)
        {
            return;
        }

        this->Hp -= _Fight->GetAtt();
        _Fight->Hp -= this->GetAtt();

        int a = 0;
    }

    void Damage(int _Damage)
    {
        int a = 0;
    }

    FightUnit(int _Att, int _Hp)
        : Att(_Att), Hp(_Hp)
    {
        this;

        printf_s("파이트 유니트 생성자");
    }

    //FightUnit() 
    //{
    //    printf_s("파이트 유니트 생성자");
    //}

    ~FightUnit()
    {
        printf_s("파이트 유니트 소멸자");
    }

};

class Player : public FightUnit
{
public:
    int Lv = 1;
    int Equip = 1;

    // 자식쪽에서 부모의 함수를 재정의 했다는 명시.
    int GetAtt() /*override*/
    {
        return Att + Lv + Equip;
    }

public:
    // 부모의 생성자가 아래와 같은 방식으로 무조건 먼저 호출됩니다.
    Player()
        : FightUnit(10, 200)
    {
        this;
        printf_s("Player 생성자");
    }

    ~Player()
    {
        printf_s("Player 소멸자");
    }
};

class Monster : public FightUnit
{
public:
    int Fury;

public:
    Monster()
        : FightUnit(10, 100)
    {
        printf_s("Monster 생성자");
    }

    ~Monster()
    {
        printf_s("Monster 소멸자");
    }
};


class NPC : public FightUnit
{
public:

public:
    NPC()
        : FightUnit(10, 100)
    {
        printf_s("Monster 생성자");
    }

    ~NPC()
    {
        printf_s("Monster 소멸자");
    }
};

void Function0() 
{
}

void Function1()
{
}

void Function2()
{
}


int main()
{
    Player NewPlayer = Player();

    // __vfptr

    //void(*Functions[10])();

    //Functions[0] = Function0;
    //Functions[1] = Function1;

    // 자료형** Ptr = Functions[0]

    std::cout << "Hello World!\n";
}

// 64.Casting.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class FightUnit 
{
protected:
    int Hp = 100;
    int Att = 10;

public:
    void Fight(FightUnit* _Fight) 
    {
        int a = 0;
    }

    void Damage(int _Damage)
    {
        int a = 0;
    }

    FightUnit(int _Att, int _Hp)
        : Att(_Att), Hp(_Hp)
    {
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
    int Lv;
    int Equip;

public:
    // 부모의 생성자가 아래와 같은 방식으로 무조건 먼저 호출됩니다.
    Player()
        : FightUnit(10, 200)
    {
        Hp = 20;
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

int main()
{
    {
        Player NewPlayer = Player();

        Monster NewMonster;
        // NewPlayer.Damage(10);

        // 자식의 자료형은 언제나 쉽게 부모의 참조형이 될수 있다.
        // 업캐스팅입니다.
        NewPlayer.Fight(&NewMonster);
    }

    {
        Player NewPlayer = Player();
        Monster NewMonster;

        FightUnit* FightUnitPtr = &NewPlayer;

        // 다운캐스팅을 아예 하지 않을수는 없다.
        // 그런데 절대로 실수하면 안됩니다.
        Monster* PlayerPtr = (Monster*)FightUnitPtr;
        // 안전장치가 있는데 그 안전장치를 쉽게 사용할수가 없어요.
        // 그걸 알아보기 위해서 아래의 3가지 문법을 배웠는데
        // 아직 본론은 나오지도 않았다.
    }


}

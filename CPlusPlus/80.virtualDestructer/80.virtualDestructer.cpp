// 80.virtualDestructer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class FightUnit 
{
public:
    virtual void Function()  = 0
    {

    }

    // 가상함수 테이블이 존재해야지만 상속관계확인이나 자식의 함수 호출이 가능해지는 것이다.

    // 딱히 가상함수를 붙일곳이 없네??????? 소멸자에 붙입니다.

    //virtual ~FightUnit()  = 0
    //{

    //}
};

class Player : public FightUnit
{
    int* Value;

public:
    void Function() 
    {
        FightUnit::Function();
    }


public:
    Player() 
    {
        Value = new int();
    }


    ~Player()
    {
        delete Value;
    }
};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // Player NewPlayer;

    FightUnit* PtrPlayer = new Player();

    // 가상함수 테이블이 없으면 c++은 상속 관계를 이해하지 못합니다.
    delete PtrPlayer;
}

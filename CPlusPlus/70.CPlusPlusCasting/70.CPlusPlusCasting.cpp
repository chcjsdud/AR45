// 70.CPlusPlusCasting.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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


class NPC 
{
public:

public:
    NPC()
    {
        printf_s("NPC 생성자");
    }

    ~NPC()
    {
        printf_s("NPC 소멸자");
    }
};


int main()
{
    int Value;

    int* Ptr4 = &Value;
    __int64* Ptr16 = (__int64*)Ptr4;
    // c 캐스팅이라고 합니다.
    // c때 사용하던 캐스팅

    // c++에서는
    // 그걸 종류에 따라서 세분화한 cplusplus casting을 시원한다.

    {
        // 바이트차이가 나는 값과 값사이의 형변환은 static_cast<>
        int Value = 10;
        short Test0 = static_cast<short>(Value);
        short Test1 = (short)(Value);
    }

    {
        // 포인터형을 정수형으로 혹은 정수형을 포인터형으로 변경할수 있는 캐스팅
        int Value = 0;
        int* Test0 = reinterpret_cast<int*>(Value);
        __int64 Address0 = reinterpret_cast<__int64>(Test0);
        __int64 Address1 = (__int64)(Test0);
    }

    {
        // 상수화를 풉니다.
        // 안쓸겁니다.
        int Value = 0;
        const int* Ptr = &Value;
        int* Test0 = const_cast<int*>(Ptr);
    }

    {
        // 상수화를 풉니다.
        int Value = 0;
        const int* Ptr = &Value;
        int* Test0 = const_cast<int*>(Ptr);
    }

    {
        Player* PlayerPtr = new Player();

        NPC* NPCPtr = dynamic_cast<NPC*>(PlayerPtr);

        // 업캐스팅의 경우에는 다이나믹 캐스트를 안해도 됩니다.
        FightUnit* FightUnitPtr = dynamic_cast<FightUnit*>(PlayerPtr);

        // 다형클래스 => virtual이 존재하는 클래스
        // FightUnit* FightUnitErrorPtr = dynamic_cast<FightUnit*>(NPCPtr);

        Monster* FightUnitToMonsterPtr = dynamic_cast<Monster*>(FightUnitPtr);

        if (nullptr == FightUnitToMonsterPtr)
        {

        }

        Player* FightUnitToPlayerPtr = dynamic_cast<Player*>(FightUnitPtr);
        int a = 0;
    }

    // std::cout << "Hello World!\n";
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

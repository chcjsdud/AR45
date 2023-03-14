// 92.Functional.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <functional>

class Player 
{
public:
    void Damage() 
    {
        printf_s("Player 맞았습니다.");
    }
};

class Monster
{
    int Hp;

public:
    void Damage()
    {
        printf_s("Monster 맞았습니다.");
    }

    void TestMonsterFunction(int _Value)
    {
        this->Hp = 20;
        std::cout << _Value << std::endl;
    }
};

class Button
{
public:
    Player* PtrPlayer;
    void(Player::* Ptr)();
};

void Test(int _Value) 
{
    int a = 0;
}

int main()
{

    {
        Player NewPlayer;
        void(Player:: * Ptr)();
        Ptr = &Player::Damage;
        (NewPlayer.*Ptr)();
    }

    {
        Player NewPlayer;
        std::function<void()> TestFunction;
        TestFunction = std::bind(&Player::Damage, &NewPlayer);
        TestFunction();

        Monster NewMonster;
        TestFunction = std::bind(&Monster::Damage, &NewMonster);
        TestFunction();
    }

    {
        std::function<void(int)> TestFunction;

        // std::placeholders::_1 인자가 있을경우에는 
        // std::placeholders::_1를 사용해서 인자가 있다는것을 명시해줘야 합니다.
        TestFunction = std::bind(Test, std::placeholders::_1);

        TestFunction(20);


        Monster* NewMonster = new Monster();

        delete NewMonster;
        NewMonster = nullptr;

        NewMonster->TestMonsterFunction(20);

        // std::placeholders::_1는 내가 직접 넣어주겠다.
        TestFunction = std::bind(&Monster::TestMonsterFunction, NewMonster, std::placeholders::_1);

        TestFunction(20);
        
    }

    {
        std::function<void()> TestFunction;

        TestFunction = std::bind(Test, 10);

        TestFunction();
    }

    // std::shared_ptr

}




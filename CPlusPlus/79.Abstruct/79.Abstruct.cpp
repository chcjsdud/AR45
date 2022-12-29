// 79.Abstruct.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 추상 혹은 pure virtual이라고 부른데.

// 이 클래스를 종이나 목에 가까운 개념으로 보려고 하는 것.

// 이 클래스의 기능은 싸울수 있다.
class FightUnit
{
public:
    // pure virtual 순수 가상함수라고 한다.
    // 순수가상함수를 가진 클래스를 추상클래스라고 부르고
    // 구현을 해도되고 안해도 된다.
    virtual void Damage() = 0 
    {

    }
};

class Player : public FightUnit
{

public:
    // fightunit 의 자식이 아닌거야.
    void Damage() 
    {
        // 무조건 구현해줘야 한다.
    }

};

int main()
{
    // FightUnit NewArr;
    Player NewPlayer;
    NewPlayer.Damage();


}

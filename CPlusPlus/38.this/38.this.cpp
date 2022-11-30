// 38.this.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 맴버함수는 코드영역에 존재하게 됩니다.
// 전역함수랑 완전히 똑같은 규칙을 가지고 코드영역에 존재합니다.

class Player
{
public:
    // 맴버함수
    // 맴버함수는 특별한 규칙이 있기는 하지만
    // 함수의 기본규칙을 벗어나지는 않는다.

    // 1. 맴버함수 앞에는 자신의 자료형이 삭제되어있다
    //    그걸 다 합친 이름만이 풀네임이다.

    // 2. 맴버함수의 인자는 언제나 하나의 생략된 인자가 있고
    //    그 인자는 여러분들이 아무것도 넣어주지 않아도 자동으로 컴파일러 넣어준다.

    void /*__thiscall*/ /*Player::*/Damage(/*Player* const this,*/ int _Damage)
    {
        // this = nullptr;

        /*this->Player::*/Hp -= _Damage;

        //this->Hp = 100;
        //this->Att = 10;
        //this->Def = 10;
    }

    void /*__thiscall*/ Heal(int _Damage/*, int _Damage*/)
    {
        // this = nullptr;

        Player* const Ptr = this;

        (*Ptr).Player::Hp += _Damage;
    }

private:
    int Att = 10;
    int Def = 10;
    int Hp = 100;
};

int Hp = 10;

void Damage(Player& _Player, int _Damage)
{
    // _Player.Hp -= _Damage;

    // Hp -= _Damage;
}

int main()
{
    Player NewPlayer0;

    //NewPlayer0.Hp = 100;
    //NewPlayer0.Att = 10;
    //NewPlayer0.Def = 10;


    int PlayerSize = sizeof(Player);

    // Damage();

    // Player::Damage

    // :: 범위확인 연산자라고 하고.
    // n::x n에 속해있는 x

    // NewPlayer0./*Player::*/Damage(10);

    // Damage(NewPlayer0, 10);

    // NewPlayer0./*Player::*/Hp

    NewPlayer0.Damage(/*&NewPlayer0,*/ 10);

    Player NewPlayer1;

    NewPlayer1.Damage(/*&NewPlayer1,*/ 10);

    // NewPlayer1./*Player::*/Damage(20);

    // Damage(NewPlayer1, 10);

    int a = 0;
}

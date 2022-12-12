// 60.Inheritance.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// 상속을 써야할 시점은
// 2개 이상의 클래스에서 
// 같은 맴버변수 같은 맴버함수가 중복될때 고려할 수 있다.

// 1. 클래스를 하나 만든다.

// 전투를 하는 애들은 이걸 사용하면 누구나 전투를 할수 있다.


//            다른클래스 전역 지역 자식내부 클래스내부
// private:          x     x   x       x         0
// protected:        x     x   x       0         0
// public:           0     0   0       0         0

class FightUnit 
{
public:
    int /*FightUnit::*/GetAtt()
    {
        return Att;
    }

    int GetHp()
    {
        return Att;
    }

public:
    int Index;

protected:
    int Level;

private:
    int Att;
    int Hp;
};

// 1. private은 다 삭제.
// 2. private 미만의 접근제한지정자는 아래로 넣고 주석.
// 3. 맴버변수로 어떤 접근제한 지정자를 가질거냐?
// 4. 상속접근제한 지정자를 본다.
// 5. 상속접근제한 지정자 vs 부모의 맴버의 접근제한지정자를 비교하고 더 범위가 좁은쪽으로 선택한다.
// 대부분의 상황에서 public만 사용한다.

// 상속문법
class Player : public FightUnit
{
public:
    // 겹치게 만들지 않습니다.
    //int /*Player::*/GetAtt()
    //{
    //    return 10;
    //}



// 비교해서 더 좁은 쪽으로 선택합니다.
//private: 
//    int GetAtt()
//    {
//        return Att;
//    }
//
//    int GetHp()
//    {
//        return Att;
//    }
//private:
//     int Index;
//
//private: 
//    int Level;

public:
    void PlayerFunction() 
    {
    }
};

class Monster : public FightUnit
{
};

int main()
{
    Player NewPlayer;

    NewPlayer.GetAtt();

    // NewPlayer.PlayerFunction

    // NewPlayer.GetAtt();

    std::cout << "Hello World!\n";
}

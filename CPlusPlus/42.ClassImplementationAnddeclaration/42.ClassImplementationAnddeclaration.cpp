// 42.ClassImplementationAnddeclaration.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 맴버변수는 따로 분리할필요가 없습니다.
class Player 
{
public:
    void Damage();

    void Test() 
    {

    }

public:
    int Att = 10;
    int Hp = 100;
};

void Damage() 
{

}

int main()
{
    std::cout << "Hello World!\n";
}


void Player::Damage()
{

}

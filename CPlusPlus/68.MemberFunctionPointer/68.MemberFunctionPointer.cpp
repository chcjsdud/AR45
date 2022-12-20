// 68.MemberFunctionPointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Player 
{
public:
    void Render() 
    {
        printf_s("출력됩니다.");
    }
};

int main()
{
    void(*Test)();

    //Test = &Player::Render;

    void(Player::*PlayerTest)();

    PlayerTest = &Player::Render;

    Player NewPlayer;

    (NewPlayer.*PlayerTest)();

    Player* NewPlayerPtr = &NewPlayer;

    (NewPlayerPtr->*PlayerTest)();

    // 값확인해라.
    // 타입확인하는버릇
    // 에러보는법
    // 때려 맞추면 안됩니다.

    // 저장하려면 공간이
    // 메모리
    // 포인터라는 참조라면 포인터 자체는 8바이트일수박에 없다.

    std::cout << sizeof(PlayerTest);

    // PlayerTest();
}

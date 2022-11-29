// 37.MemberFunction.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Player 
{
//            다른클래스 전역 지역 자식내부 클래스내부
// private:          x     x   x       x         0
// protected:        x     x   x       0         0
// public:           0     0   0       0         0


public:
    // const int Value = 10;
    // 행동 쳐맞는다는 행동.
    void Damage(int _Damage) 
    {
        // 왜 굳이 함수까지 만들어서 해야지?
        // 1. 대부분의 행동은 단순하게 짜여지지 않는다.
        // 맞는다는 행위는 게임 적으로 생각해봐도 
        // 복합적인일이 벌어지게 된다.
        // 이펙트
        // 애니메이션 변경
        Hp -= _Damage;

        if (Hp <= 0)
        {
            int a = 0;
        }
    }

protected:

private:
    int Att = 10;
    int Def = 10;

public:
    int Hp = 100;

};

// 클래스 설계에서 중요한 몇가지 포인트가 있는데.
// 최대한 외부와 결합성을 제거하는것
// 최대한 내부에서 자신의 일을 처리하는것을 말한다.

int main()
{
    Player NewPlayer;

    //NewPlayer.이펙트생성()
    //NewPlayer.애니메이션변경()
    NewPlayer.Damage(10);

    NewPlayer.Damage(10);
    NewPlayer.Damage(10);

    NewPlayer.Damage(10);

    NewPlayer.Damage(10);

    NewPlayer.Damage(10);

    NewPlayer.Damage(10);


    NewPlayer.Damage(10);

    NewPlayer.Damage(10);


    NewPlayer.Damage(10);


    NewPlayer.Damage(10);

    NewPlayer.Damage(10);

    //NewPlayer.Hp -= 10;


    //NewPlayer.Hp -= 10;


    //NewPlayer.Hp -= 10;


    //NewPlayer.Hp -= 10;


    //NewPlayer.Hp -= 10;

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

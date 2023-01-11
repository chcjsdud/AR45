// 87.Union.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

union UTest
{
    struct
    {
        int LowPart;
        int HighPart;
    };
    struct
    {
        int uLowPart;
        int uHighPart;
    } u;
    __int64 QuadPart;
};

// LowPart HighPart
// QuadPart
// [][][][][][][][]

// 가장 위에는 이름이 있어야 합니다.
union UTest1
{
    // 이안에서 이름이 없는  class나 struct를 사용하면
    // 메모리 구조를 여기만 이렇게 써줘가 됩니다.
    // 메모리구조가 
    struct 
    {
        int X;
        int Y;
    };
    __int64 Value64;
};

class A
{
    // 특정 사용자 정의 자료형 내부에서
    // 이름없이 새로운 사용자 정의 자료형을 사용한다는것은
    // 그 키워드에 해당하는 메모리 구성을 사용하라는 말이 됩니다.
    union 
    {
        int a;
        int b;
    };
};

// X       Y
// Value64
// [][][][][][][][]

// class Player
// {
//      int Att;
//      int Hp;
// }

// Att      Hp
// [][][][] [][][][]

int main()
{
    UTest1 UT1 = UTest1();

    UT1.X = 1;

    A NewA;

    int size = sizeof(A);

    UTest UT = UTest();

    std::cout << "Hello World!\n";
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

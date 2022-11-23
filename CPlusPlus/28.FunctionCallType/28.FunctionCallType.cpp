// 28.FunctionCallType.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

// _cdecl
// _thiscall 이녀석은 정말 잘 이해해야하는데 <= 클래스까지 가야합니다.
// _stdcall 

// 몰라도 될정도로 안쓰인다.
// fastcall 

// 기본적으로 전역함수는 _cdecl로 거의 고정
void _cdecl Test(int A, int B, int C)
{

}

//int printf_s(const char* const, int, int, int, int, int, int)
//{
//
//}

//void Test() 
//{
//
//}

//void Test()
//{
//
//}

// 나중에 함수포인터를 사용할때 명시해줘야 한다는것 빼고.

int main()
{
    // Test(1, 2, 3, 5, 8);

    int a = printf_s("%ddddaaaa", 1000, 2000, 3000, 400, 5000, 6000);
    // "1000dddaaaa"

    // int a = printf_s("%ddddaaaa", 1000, 2000, 3000, 400);

    _getch();
}
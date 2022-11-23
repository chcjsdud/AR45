// 27. inline.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

// inline이 표기된 함수는 스택을 만들지 않고 함수 내부의 내용을 
// 가능하다면 그대로 복사해서 코드 삽입하라는 키워드 입니다.
// 이때 가능하다면 컴파일러가 판단해서 스택을 제거하고 내부코드만 실행하고
// 불가능하면 그냥 스택만들고 일반적인 함수처럼 실행한다.
inline void _cdecl Function() 
{
    int a = 10;
}

int main()
{
    int value = _getch();

    signed int a = 10;

    signed int a = 10;
    // Function();
}

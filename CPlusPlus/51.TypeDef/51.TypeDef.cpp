// 51.TypeDef.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 어떠한 자료형에 별명을 붙이는 겁니다.
typedef int INTINT;

//typedef unsigned __int64 size_t;

typedef class _Test 
{
public:
    int Value;

} Test;

// typedef class _Test TTT;

#ifdef _WIN64
typedef unsigned __int64 size_t;
typedef __int64          ptrdiff_t;
typedef __int64          intptr_t;
#else
typedef unsigned int     size_t;
typedef int              ptrdiff_t;
typedef int              intptr_t;
#endif

int main()
{
    INTINT NewInt;

    // long long 
    // 4바이트 정수형
    // int == long
    int Size = sizeof(long long);
}
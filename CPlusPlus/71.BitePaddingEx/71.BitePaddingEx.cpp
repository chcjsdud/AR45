// 71.BitePaddingEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 1. 가장큰 자료형 8바이트 가상함수 테이블로 봅니다.
// 2. 그 상태에서 4바이트로 끊습니다.

// 1. 첫번째 자료형이 나오면 일단 가장큰 바이트를 할당한다.
// 2. 그다음 다른 자료형이 나온다고 치면
// 3. 4바이트로 확인해서 꽉채울수 없다면 패딩을 두고 그다음 바이트 번째에 놓습니다.
// 4. 그 이후에는 그걸 읽으면서 반복.

class Size 
{
public:
    // 4바이트 혹은 8바이트 단위로
    short v1; // 8 // 8바이트 
    short v2;   // 
    short v3; // 8
    int v8; // 8
    int v4; // 8
};

class Base
{
public:
    int Value0;
};

class A : public Base
{
public:
    int Value1;

    virtual void Test() 
    {

    }
};

class C : public A
{
public:
    int Value2;
};

// 

int main()
{
    Size Value;

    A NewA;

    std::cout << sizeof(A) << std::endl;

    std::cout << sizeof(Value) << std::endl;
    // 100
    std::cout << reinterpret_cast<__int64>(&NewA) << std::endl;
    // 108
    std::cout << reinterpret_cast<__int64>(&NewA.Value0) << std::endl;
}

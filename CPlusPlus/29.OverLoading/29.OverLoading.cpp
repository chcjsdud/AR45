// 29.OverLoading.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 이름이 같은 함수를 인자만 다르게해서 여러개 선언하는 문법입니다.

// 컴파일러가 컴파일을 하면서 네임맹글링이라는 단계를 거칩니다.

// 자기가 인식할수 있는 이름으로 바꿀때


void Test() 
{

}

// a은 영향을 주지 않는다.
void Test(int a)
{

}

void Test(int a, int b)
{

}

void Test(int a, char b)
{

}

void Test(char a)
{

}

void TestVar(...) 
{

}

//void TestVar(int a, int b, int c)
//{
//
//}
//
//void TestVar(int a, int b)
//{
//
//}

int main()
{
    Test();
    Test(10);
    Test(10, 20);
    Test('c');

    TestVar(10, 20, 30);
    TestVar(10, 20, 30);

    TestVar(10, 20);
}

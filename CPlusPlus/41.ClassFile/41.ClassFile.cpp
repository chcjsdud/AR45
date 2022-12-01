// 41.ClassFile.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 실체가 1개인게 중요하지 
// 선언은 100개가 되건 1000개가 되건 어차피 컴파일러가 감안하고 알아서 최적화 합니다.
void Function1();
void Function1();
void Function1();
void Function1();
void Function1();
void Function1();
// 이런함수가 분명히 존재할거야.
// 자세한 내용은 나중에 다 컴파일되어서 만들어지니까.
// 지금은 이것만 믿고 사용가능하게 해줘.

void TestFunction(); // 선언

// 변수의 선언
extern int A;
extern int A;
extern int A;
extern int A;

int main()
{
    A = 10;

    // Function1();
    // std::cout << "Hello World!\n";
}

int A = 10;

// 구현
void TestFunction()  // 함수선언
{
    // 함수바디
}
//
//
//void TestFunction()  // 함수선언
//{
//    // 함수바디
//}
//


void Function1()
{
    // Function0();
}

void Function0()
{
    // Function1();
}
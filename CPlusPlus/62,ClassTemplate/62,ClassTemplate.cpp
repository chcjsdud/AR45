// 62,ClassTemplate.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 템플릿 클래스
template<typename DataType>
class NewArr 
{
public:
    DataType Value;
};

//class NewArrint
//{
//public:
//    int Value;
//};

//class NewArrbool
//{
//public:
//    int Value;
//};

class A
{
};

class B
{
};

int main()
{
    A Aa;
    B BB;

    // Aa = BB;

    // 템플릿은 코드치는 시간은 줄어들지만
    // 컴파일 시간은 늘어나는 문법입니다.
    // 컴파일 시간(exe파일(결과파일들)이 만들어질때까지의 시간)

    // 인자를 생략할수 없다.


    NewArr<int*> Test0;
    NewArr<int> Test1;
    NewArr<int> Test11;
    NewArr<bool> Test2;

    // Test1 = Test11;

    // Test0 = Test1;

    std::cout << "Hello World!\n";
}

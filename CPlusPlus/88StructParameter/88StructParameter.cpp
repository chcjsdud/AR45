// 88StructParameter.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

struct Parameter
{
    int Value0 = 0;
    int Value1 = 1;
    int Value2 = 2;
    int Value3 = 3;
};

void Function(const Parameter& _Para)
{
    int a = 0;
}

int main()
{
    Function({.Value1 = 10, .Value3 = 100});

    std::cout << "Hello World!\n";
}

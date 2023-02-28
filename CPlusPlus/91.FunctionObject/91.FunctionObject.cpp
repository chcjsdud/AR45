// 91.FunctionObject.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 함수 객체라고 부른다
class A 
{
public:
    int operator()(int _Value) 
    {
        return 100;
    }
};

int main()
{
    A NewA;

    NewA(10);
}

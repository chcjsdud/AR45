// GameArray.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class A 
{
public:
    int Arr[20];

public:
    bool Function() {
        Arr[10] = 20;
        return true;
    }
};

int main()
{
    A NewA;
    A* NewAPtr = &NewA;

    NewA.Function();
    NewAPtr->Function();

    std::cout << "Hello World!\n";
}

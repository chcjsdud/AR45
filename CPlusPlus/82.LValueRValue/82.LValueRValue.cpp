// 82.LValueRValue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int Return() 
{
    return 10;
}

int main()
{
    int Value;

    // 100번지다.
    // Value = ;
    Value = 10;

    Value = Return();

    // LValue는 왼쪽이든 오른쪽이든 올수 있다.
    // 0 = Value;

    std::cout << "Hello World!\n";
}

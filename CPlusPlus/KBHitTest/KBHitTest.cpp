// KBHitTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h>
#include <conio.h>

int main()
{

    while (true)
    {
        int Count = _kbhit();

        if (0 == Count)
        {
            continue;
        }
        printf_s("%d", Count);

        _getch();
        Sleep(1000);
    }
    

    std::cout << "Hello World!\n";
}

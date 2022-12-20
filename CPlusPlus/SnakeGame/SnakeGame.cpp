// SnakeGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <ConsoleGameScreen.h>
#include "Head.h"

ConsoleGameScreen Screen;
int4 ScreenSize = { 15, 11 };

int main()
{
    LeckCheck();

    Part* StartPart = new Head();

    Screen.ScreenInit(ScreenSize, L'■');

    while (true)
    {
        system("cls");
        Screen.ScreenClear();

        StartPart->Update();

        StartPart->Render();

        Screen.ScreenRender();
        Sleep(100);
    }

}

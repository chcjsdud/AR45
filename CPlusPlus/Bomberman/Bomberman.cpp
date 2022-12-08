// Bomberman.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "ConsoleGameScreen.h"
#include "Player.h"
#include "GameEngineDebug.h"
#include <conio.h>

ConsoleGameScreen Screen;
Player MainPlayer;


int main()
{
    LeckCheck();

    // 지역변수로 만들어졌어.
    Screen.ScreenInit({15, 10}, L'■');

    // 정상종료를 시켜줘야 하는데.
    while (true)
    {
        system("cls");
        Screen.ScreenClear();

        Screen.SetPixelChar(MainPlayer.GetPos(), MainPlayer.GetRenderChar());

        Screen.ScreenRender();
        Sleep(500);
    }
    
}

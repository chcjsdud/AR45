// SnakeGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <ConsoleGameScreen.h>
#include <GameEngineInput.h>

#include "Head.h"
#include "Body.h"
#include <conio.h>

ConsoleGameScreen Screen;
int4 ScreenSize = { 5, 5 };

int main()
{
    LeckCheck();

    Part* StartPart = new Head();

    // Part* CurBody = new Body();
    Screen.ScreenInit(ScreenSize, L'□');

    Body::CreateBody();

    while (true)
    {
        GameEngineInput::ConsoleInputCheck();

        if (
            true == GameEngineInput::GetIsInput()
            && ('q' == GameEngineInput::GetKey() || 'Q' == GameEngineInput::GetKey())
            )
        {
            break;
        }


        system("cls");
        Screen.ScreenClear();

        Body::GetCurBody()->Update();

        StartPart->Update();

        StartPart->RecursionBackRender();

        Body::GetCurBody()->Render();

        // CurBody->Render();

        Screen.ScreenRender();
        Sleep(100);
    }

    if (nullptr != StartPart)
    {
        delete StartPart;
        StartPart = nullptr;
    }

}

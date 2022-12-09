// Bomberman.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "ConsoleGameScreen.h"
#include "Player.h"
#include "GameEngineDebug.h"
#include <conio.h>

ConsoleGameScreen Screen;
// 이렇게 생성해도 됩니다.
Player MainPlayer;

// 1. 폭탄 릭을 없애오세요.
// 2. 폭탄을 여러개 설치하게 만드세요.
// 3. 플레이어가 폭타을 못지나가게 하세요.
// 4. 폭탄이 일정 시간후에 사라지게 하세요.
      // ex)폭탄이 사라지고 난후에는 플레이어가 그 위치를 지나갈수 있어야 합니다.


int main()
{
    LeckCheck();

    // 지역변수로 만들어졌어.
    Screen.ScreenInit({15, 10}, L'■');

    // 

    // ■■
    // ■■

    // 정상종료를 시켜줘야 하는데.
    while (true)
    {
        // AA
        // AA
        system("cls");
        // AA
        // AA
        Screen.ScreenClear();

        
        bool End = MainPlayer.Update();

        // Ao
        // AA

        // 화면에 그린다.
        Screen.ScreenRender();
        Sleep(100);

        if (false == End)
        {
            printf_s("게임을 종료했습니다.");
            break;
        }
    }
    
}

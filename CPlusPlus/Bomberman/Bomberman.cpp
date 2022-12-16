// Bomberman.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "ConsoleGameScreen.h"
#include "Player.h"
#include "Wall.h"
#include "Monster.h"
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

// 1. 장애물 만들기
// 2. 플레이어는 못지나감.

// 1. 몬스터를 1개 화면에 나오게 한다.
// 2. 몬스터a가 왼쪽으로 움직이다가 끝을 만나면 오른쪽으로 가게 만드세요.
// 3. 몬스터b를 만들고 위로 움직이다가 끝을 만나면 

int4 ScreenSize = { 15, 11 };

int main()
{
    LeckCheck();

    // 지역변수로 만들어졌어.
    Screen.ScreenInit(ScreenSize, L'■');

    Boom::BoomMapInit(ScreenSize);
    Wall::WallMapInit(ScreenSize);
    Monster::AllMonsterInit(L'◎');

    Monster::CreateMonster({0, 2}, int4::LEFT);
    Monster::CreateMonster({ 0, 3 }, int4::UP);
    Monster::CreateMonster({ 0, 4 }, int4::RIHGT);

    // 정상종료를 시켜줘야 하는데.
    while (true)
    {
        // AA
        // AA
        system("cls");
        // AA
        // AA
        Screen.ScreenClear();

        Wall::WallUpdate();
        Monster::AllMonsterUpdate();
        
        bool End = MainPlayer.Update();

        // Ao
        // AA


        // 화면에 그린다.
        Screen.ScreenRender();
        Sleep(100);

        Boom::MapClear();

        if (false == End)
        {
            printf_s("게임을 종료했습니다.");
            break;
        }
    }
    
}

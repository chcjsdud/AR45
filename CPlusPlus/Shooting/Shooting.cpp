// Shooting.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "GameMap.h"
#include "Player.h"
#include <Windows.h>

int main()
{
    // char Arr[3] = "□";

        //aaaaaaaaaa
        //＠＠＠＠＠
        //※※※※※
        //※※※※※
        //※※※※※
        //※※※※※


    GameMap NewMap;
    Player NewPlayer;

    // 맵이 만들어지고
    // 플레이어를 위치시키고 
    // 리스트 이니셜라이저 문법
    NewPlayer.SetPos(/*Int4*/{2, 2});

    // 맵에 플레이어의 위치에 글자를 찍어야한다.
    NewMap.Init("□");


    while (true)
    {
        system("cls");

        NewMap.Clear();

        // 움직이고
        NewPlayer.Update();

        // 적용하고.
        NewMap.SetTile(NewPlayer.GetPos(), NewPlayer.GetDisplayChar());

        // 그려진다.
        NewMap.Render();
        // 1000 이
        Sleep(100);
    }

}

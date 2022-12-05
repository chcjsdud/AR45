// Shooting.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "GameMap.h"
#include "Player.h"
#include <Windows.h>

int main()
{
    // 와이드 바이트의 경우
    // 국가코드에 따라서 특수기호 위치나 이런것들이 달라지므로
    // 국가코드를 변경해줘야 한국을 기준으로한 특수기호나 한글을 사용할수 있다.

    setlocale(LC_ALL, "KOR");

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
    NewMap.Init(L'□');


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

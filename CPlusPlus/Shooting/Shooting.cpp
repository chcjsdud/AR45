// Shooting.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "GameMap.h"
#include "Player.h"

int main()
{
    GameMap NewMap;
    Player NewPlayer;

    // 맵이 만들어지고
    NewMap.Init('a');

    // 플레이어를 위치시키고 
    Int4 Pos;
    Pos.X = 2;
    Pos.Y = 2;
    NewPlayer.SetPos(Pos);

    // 맵에 플레이어의 위치에 글자를 찍어야한다.
    NewMap.Init('a');

    NewMap.SetTile(NewPlayer.GetPos(), NewPlayer.GetDisplayChar());

    NewMap.Render();

}

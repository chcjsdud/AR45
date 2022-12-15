
#include "Wall.h"
#include <conio.h>
#include "ConsoleGameScreen.h"
#include "player.h"
#include <Windows.h>

GameEngineArray<GameEngineArray<Wall>> Wall::WallMap;

/*static */void Wall::WallMapInit(int4 _Size)
{
	WallMap.ReSize(_Size.Y);

	for (int y = 0; y < WallMap.GetCount(); y++)
	{
		WallMap[y].ReSize(_Size.X);
		for (int x = 0; x < WallMap[y].GetCount(); x++)
		{
			WallMap[y][x].SetPos(int4{x, y});
			if (0 == y % 2)
			{
				continue;
			}

			if (0 == x % 2)
			{
				continue;
			}
			WallMap[y][x].IsWall = true;
		}
	}
}

/*static */void Wall::WallUpdate()
{

	for (int y = 0; y < WallMap.GetCount(); y++)
	{
		for (int x = 0; x < WallMap[y].GetCount(); x++)
		{
			WallMap[y][x].Update();
		}
	}
}

/*static */bool Wall::GetIsWall(int4 _Size)
{
	return WallMap[_Size.Y][_Size.X].IsWall;
}


Wall::Wall()
	: IsWall(false)
{
	SetRenderChar(L'бр');
}

Wall::~Wall()
{

}

void Wall::Update()
{
	if (false == IsWall)
	{
		return;
	}

	Render();
}



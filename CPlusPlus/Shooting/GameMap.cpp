#include "GameMap.h"
#include <iostream>


void GameMap::Init(const char* _Char)
{
	// "бр"
	// 3
	// _Char

	// y0 aa
	// y1 г└
	// y2 [a][a][a][a][a][0]
	// y3 [][][][][][0]
	// y4 [][][][][][0]
	BaseChar = _Char;

	for (unsigned int y = 0; y < 5; ++y)
	{
		for (unsigned int x = 0; x < 5; ++x)
		{
			ArrTile[y][x * 2 + 0] = BaseChar[0];
			ArrTile[y][x * 2 + 1] = BaseChar[1];
		}

		ArrTile[y][10] = 0;
	}

	
}

void GameMap::Clear()
{
	for (unsigned int y = 0; y < 5; ++y)
	{
		for (unsigned int x = 0; x < 5; ++x)
		{
			ArrTile[y][x * 2 + 0] = BaseChar[0];
			ArrTile[y][x * 2 + 1] = BaseChar[1];
		}

		ArrTile[y][10] = 0;
	}
}

void GameMap::Render()
{
	for (unsigned int y = 0; y < 5; ++y)
	{
		const char* Ptr = ArrTile[y];
		printf_s(Ptr);
		printf_s("\n");
	}

}

void GameMap::SetTile(const Int4& _Pos, const char* _Char)
{
	ArrTile[_Pos.Y][_Pos.X * 2 + 0] = _Char[0];
	ArrTile[_Pos.Y][_Pos.X * 2 + 1] = _Char[1];
}
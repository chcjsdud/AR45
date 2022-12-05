#include "GameMap.h"
#include <iostream>


void GameMap::Init(const wchar_t _Char)
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
			ArrTile[y][x] = BaseChar;
		}

		ArrTile[y][5] = 0;
	}

	
}

void GameMap::Clear()
{
	for (unsigned int y = 0; y < 5; ++y)
	{
		for (unsigned int x = 0; x < 5; ++x)
		{
			ArrTile[y][x] = BaseChar;
		}

		ArrTile[y][5] = 0;
	}
}

void GameMap::Render()
{
	for (unsigned int y = 0; y < 5; ++y)
	{
		const wchar_t* Ptr = ArrTile[y];
		wprintf_s(Ptr);
		wprintf_s(L"\n");
	}

}

void GameMap::SetTile(const Int4& _Pos, wchar_t _Char)
{
	ArrTile[_Pos.Y][_Pos.X] = _Char;
}
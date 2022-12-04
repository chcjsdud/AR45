#include "GameMap.h"
#include <iostream>


char GameMap::Init(const char _Char)
{
	// "бр"
	// 3
	// _Char

	// y0 [a][a][a][a][a][0]
	// y1 [a][a][a][a][a][0]
	// y2 [a][a][a][a][a][0]
	// y3 [][][][][][0]
	// y4 [][][][][][0]

	for (unsigned int y = 0; y < 5; ++y)
	{
		for (unsigned int x = 0; x < 5; ++x)
		{
			ArrTile[y][x] = _Char;			
		}

		ArrTile[y][5] = 0;		
	}
	return ArrTile[5][5];
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

void GameMap::SetTile( const Int4& _Pos, char _Char)
{
	ArrTile[_Pos.Y][_Pos.X] = _Char;

	

}
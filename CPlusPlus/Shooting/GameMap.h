#pragma once
#include "ContentsMath.h"

class GameMap 
{

public:
	void Render();
	char Init(const char _BaseChar);

	void SetTile(const Int4& _Pos, char _Char);
	char* Mapsize()
	{
		return (char*)ArrTile;
	}
	
private:
	char ArrTile[5][6];
	
};

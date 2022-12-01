#pragma once
#include "ContentsMath.h"

class GameMap 
{

public:
	void Render();
	void Init(const char _BaseChar);

	void SetTile(const Int4& _Pos, char _Char);

private:
	char ArrTile[5][6];
	
};
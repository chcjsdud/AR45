#pragma once
#include "ContentsMath.h"

class GameMap 
{

public:
	void Clear();
	void Render();
	void Init(const char* _BaseChar);
	void SetTile(const Int4& _Pos, const char* _Char);

private:
	// 무조건 2바이트 짜리 글자라고 생각할 겁니다.
	const char* BaseChar;
	char ArrTile[5][11];
	
};
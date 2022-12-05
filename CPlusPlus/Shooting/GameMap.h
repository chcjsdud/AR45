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
	// ������ 2����Ʈ ¥�� ���ڶ�� ������ �̴ϴ�.
	const char* BaseChar;
	char ArrTile[5][11];
	
};
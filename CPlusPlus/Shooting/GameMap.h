#pragma once
#include "ContentsMath.h"

class GameMap 
{

public:
	void Clear();
	void Render();
	void Init(const wchar_t _BaseChar);
	void SetTile(const Int4& _Pos, wchar_t _Char);

private:
	// 무조건 2바이트 짜리 글자라고 생각할 겁니다.
	wchar_t BaseChar;
	wchar_t ArrTile[5][6];
	
};

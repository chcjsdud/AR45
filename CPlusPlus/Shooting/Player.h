#pragma once
#include "ContentsMath.h"

class Player 
{
public:
	// 바꾸기 위한 기능
	void SetPos(const Int4& _Pos) 
	{
		Pos = _Pos;
	}

	void Move(const Int4& _Dir)
	{
		Pos += _Dir;
	}
	
	// 외부에 알려주기만 하는 기능을 명확하게 구분
	Int4 GetPos()
	{
		return Pos;
	}

	wchar_t GetDisplayChar()
	{
		return DisplayChar;
	}

	void Update();

private:
	wchar_t DisplayChar = L'■';
	Int4 Pos;
};
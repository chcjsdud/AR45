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

	const char* GetDisplayChar()
	{
		return DisplayChar;
	}

	void Update(char a[]);

private:
	const char* DisplayChar = "■";
	Int4 Pos;
};
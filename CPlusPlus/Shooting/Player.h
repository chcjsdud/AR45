#pragma once
#include "ContentsMath.h"

class Player 
{
public:
	// �ٲٱ� ���� ���
	void SetPos(const Int4& _Pos) 
	{
		Pos = _Pos;
	}

	// �ܺο� �˷��ֱ⸸ �ϴ� ����� ��Ȯ�ϰ� ����
	Int4 GetPos()
	{
		return Pos;
	}

	char GetDisplayChar()
	{
		return DisplayChar;
	}

private:
	char DisplayChar = '*';
	Int4 Pos;
};
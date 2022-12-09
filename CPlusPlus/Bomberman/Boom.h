#pragma once
#include "ConsoleGameMath.h"

// Ό³Έν :
class Boom
{
public:
	// constrcuter destructer
	Boom();
	~Boom();

	// delete Function
	Boom(const Boom& _Other) = delete;
	Boom(Boom&& _Other) noexcept = delete;
	Boom& operator=(const Boom& _Other) = delete;
	Boom& operator=(Boom&& _Other) noexcept = delete;

	void Update();

	int4 GetPos()
	{
		return Pos;
	}

	void SetPos(const int4& _Value)
	{
		Pos = _Value;
	}

	wchar_t GetRenderChar()
	{
		return RenderChar;
	}

protected:

private:
	int4 Pos = { 0, 0 };
	wchar_t RenderChar = L'’Β';

};


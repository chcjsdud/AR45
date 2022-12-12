#pragma once
#include "ConsoleGameMath.h"
#include "Boom.h"
// ¼³¸í :
class Boom;
class ConsoleGameScreen;
class Player
{
public:
	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

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

	bool Update();

protected:

private:

	int4 Pos = { 0,0 };
	wchar_t RenderChar = L'¡Ú';
	int BoomUseCount = 0;
	Boom* ArrBoomObject = nullptr;

};


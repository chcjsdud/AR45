#pragma once
#include "ConsoleGameMath.h"

// ¼³¸í :
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

	wchar_t GetRenderChar()
	{
		return RenderChar;
	}

protected:

private:
	int4 Pos = {0, 0};
	wchar_t RenderChar = L'¡Ú';

};


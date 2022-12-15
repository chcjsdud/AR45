#pragma once
#include "ConsoleGameMath.h"
#include "ConsoleGameObject.h"
#include "Boom.h"
#include <GameEngineArray.h>


// Ό³Έν :
class Boom;
class ConsoleGameScreen;
class Player : public ConsoleGameObject
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
	
	bool Update();

protected:

private:
	int BoomUseCount = 0;
	GameEngineArray<Boom> ArrBoomObject;

};


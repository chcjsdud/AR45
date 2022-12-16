#pragma once
#include "ConsoleGameMath.h"
#include "ConsoleGameObject.h"
#include <GameEngineArray.h>

// Ό³Έν :

class ConsoleGameScreen;
class Player;
class Wall : public ConsoleGameObject
{
public:
	static void WallMapInit(int4 _Size);

	static void WallUpdate();

	static bool GetIsWall(int4 _Size);

	// constrcuter destructer
	Wall();
	~Wall();

	// delete Function
	Wall(const Wall& _Other) = delete;
	Wall(Wall&& _Other) noexcept = delete;

	Wall& operator=(const Wall& _Other)
	{
		return *this;
	}
	Wall& operator=(Wall&& _Other) noexcept = delete;

	void Update();

protected:

private:
	static GameEngineArray<GameEngineArray<Wall>> WallMap;
};


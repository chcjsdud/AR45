#pragma once
#include "ConsoleGameMath.h"
#include "ConsoleGameObject.h"

// Ό³Έν :

class ConsoleGameScreen;
class Player;
class Boom : public ConsoleGameObject
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

	bool IsDeath()
	{
		return 0 > Time;
	}

protected:

private:
	int Time = 20;
	int Range = 4;


};


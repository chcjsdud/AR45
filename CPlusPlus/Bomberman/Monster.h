#pragma once
#include "ConsoleGameMath.h"
#include <GameEngineArray.h>
#include "ConsoleGameObject.h"

// Ό³Έν :
class Monster : public ConsoleGameObject
{

public:
	static size_t MonsterUpdateCount;

	static Monster* CreateMonster(int4 _Pos, int4 _Dir);

	static void AllMonsterInit(wchar_t _BaseChar);

	static void AllMonsterUpdate();

	// delete Function
	Monster(const Monster& _Other) = delete;
	Monster(Monster&& _Other) noexcept = delete;

	Monster& operator=(const Monster& _Other) 
	{
		return *this;
	}

	Monster& operator=(Monster&& _Other) noexcept = delete;

	void SetDir(int4 _Dir) 
	{
		Dir = _Dir;
	}

	void Update();

	Monster();
	~Monster();

protected:

private:
	static GameEngineArray<Monster> AllMonster;

	int4 Dir;

	void Init();

};


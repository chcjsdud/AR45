#include "GameEngineInput.h"
#include <conio.h>

bool GameEngineInput::IsInput;
int GameEngineInput::CurKey;

GameEngineInput::GameEngineInput() 
{
}

GameEngineInput::~GameEngineInput() 
{
}


void GameEngineInput::ConsoleInputCheck()
{
	IsInput = false;

	if (0 == _kbhit())
	{
		return;
	}

	IsInput = true;

	CurKey = _getch();
}
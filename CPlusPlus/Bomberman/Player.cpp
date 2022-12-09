#include "Player.h"
#include <conio.h>
#include "ConsoleGameScreen.h"
#include "Boom.h"

Player::Player()
{
}

Player::~Player() 
{
}

bool Player::Update() 
{
	if (0 == _kbhit())
	{
		ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());
		return true;
	}

	// 프로그램 입력이 올때까지 멈추죠?
	int Input = _getch();

	int4 NextPos = GetPos();

	switch (Input)
	{
	case 'a':
	case 'A':
		NextPos += {-1, 0};
		break;
	case 'd':
	case 'D':
		NextPos += {1, 0 };
		break;
	case 's':
	case 'S':
		NextPos += { 0, 1 };
		break;
	case 'w':
	case 'W':
		NextPos += { 0, -1 };
		break;
	case 'f':
	case 'F':
		//BoomObject = new Boom();
		//BoomObject->SetPos(GetPos());
		break;
	case 'q':
	case 'Q':
		return false;
	default:
		break;
	}

	// [][][][][]
	// [][][][][]
	// [][][][][]
	// [][][][][]
	// [][][][][]

	// 나가지 않았다면
	if (false == ConsoleGameScreen::GetMainScreen()->IsOver(NextPos))
	{
		SetPos(NextPos);
	}

	ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());

	return true;
}
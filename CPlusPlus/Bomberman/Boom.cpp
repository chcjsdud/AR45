
#include "Boom.h"
#include <conio.h>
#include "ConsoleGameScreen.h"
#include "player.h"
#include <Windows.h>
Boom::Boom()
{
	SetRenderChar(L'¡Ý');
}

Boom::~Boom()
{

}

void Boom::Update()
{
	if (CurRange >= Range)
	{
		return;
	}

	if (0 > --Time)
	{
		++CurRange;
		// return;
	}

	// ÆøÅº ±×ÀÚÃ¼´Â ±×³É Ãâ·Â
	int4 Pos = GetPos();
	ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());

	for (int i = 1; i < CurRange; i++)
	{
		int4 Left = Pos + int4{-i, 0};
		if (false == ConsoleGameScreen::GetMainScreen()->IsOver(Left))
		{
			ConsoleGameScreen::GetMainScreen()->SetPixelChar(Left, L'¡ß');
		}

		int4 Right = Pos + int4{ i, 0 };
		if (false == ConsoleGameScreen::GetMainScreen()->IsOver(Right))
		{
			ConsoleGameScreen::GetMainScreen()->SetPixelChar(Right, L'¡ß');
		}

		int4 Up = Pos + int4{ 0, i };
		if (false == ConsoleGameScreen::GetMainScreen()->IsOver(Up))
		{
			ConsoleGameScreen::GetMainScreen()->SetPixelChar(Up, L'¡ß');
		}

		int4 Down = Pos + int4{ 0, -i };
		if (false == ConsoleGameScreen::GetMainScreen()->IsOver(Down))
		{
			ConsoleGameScreen::GetMainScreen()->SetPixelChar(Down, L'¡ß');
		}
	}
}



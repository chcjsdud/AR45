
#include "Boom.h"
#include <conio.h>
#include "ConsoleGameScreen.h"
#include "player.h"
#include "Wall.h"
#include <Windows.h>

GameEngineArray<GameEngineArray<Boom*>> Boom::BoomMap;

/*static */void Boom::BoomMapInit(int4 _Size)
{
	BoomMap.ReSize(_Size.Y);

	for (size_t y = 0; y < BoomMap.GetCount(); y++)
	{
		BoomMap[y].ReSize(_Size.X);
		for (size_t x = 0; x < BoomMap[y].GetCount(); x++)
		{
			BoomMap[y][x] = nullptr;
		}
	}
}

/*static */Boom* Boom::GetBoom(int4 _Size)
{
	return BoomMap[_Size.Y][_Size.X];
}


/*static */void Boom::MapClear()
{
	for (size_t y = 0; y < BoomMap.GetCount(); y++)
	{
		for (size_t x = 0; x < BoomMap[y].GetCount(); x++)
		{
			BoomMap[y][x] = nullptr;
		}
	}
}

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

	int4 BoomPos = GetPos();

	BoomMap[BoomPos.Y][BoomPos.X] = this;

	if (0 > --Time)
	{
		++CurRange;
		// return;
	}

	// ÆøÅº ±×ÀÚÃ¼´Â ±×³É Ãâ·Â
	int4 Pos = GetPos();
	wchar_t MyChar = GetRenderChar();
	ConsoleGameScreen::GetMainScreen()->SetPixelChar(Pos, MyChar);

	bool LeftWall = false;
	bool RightWall = false;
	bool UpWall = false;
	bool DownWall = false;

	for (int i = 1; i < CurRange; i++)
	{
		int4 Left = Pos + int4{-i, 0};

		if (false == ConsoleGameScreen::GetMainScreen()->IsOver(Left) && true == Wall::GetIsWall(Left))
		{
			LeftWall = true;
		}

		if (false == LeftWall && false == ConsoleGameScreen::GetMainScreen()->IsOver(Left))
		{
			ConsoleGameScreen::GetMainScreen()->SetPixelChar(Left, L'¡ß');
		}

		int4 Right = Pos + int4{ i, 0 };

		if (false == ConsoleGameScreen::GetMainScreen()->IsOver(Right) && true == Wall::GetIsWall(Right))
		{
			RightWall = true;
		}


		if (false == RightWall && false == ConsoleGameScreen::GetMainScreen()->IsOver(Right))
		{
			ConsoleGameScreen::GetMainScreen()->SetPixelChar(Right, L'¡ß');
		}

		int4 Up = Pos + int4{ 0, i };

		if (false == ConsoleGameScreen::GetMainScreen()->IsOver(Up) && true == Wall::GetIsWall(Up))
		{
			UpWall = true;
		}
		if (false == UpWall && false == ConsoleGameScreen::GetMainScreen()->IsOver(Up))
		{
			ConsoleGameScreen::GetMainScreen()->SetPixelChar(Up, L'¡ß');
		}

		int4 Down = Pos + int4{ 0, -i };

		if (false == ConsoleGameScreen::GetMainScreen()->IsOver(Down) && true == Wall::GetIsWall(Down))
		{
			DownWall = true;
		}

		if (false == DownWall && false == ConsoleGameScreen::GetMainScreen()->IsOver(Down))
		{
			ConsoleGameScreen::GetMainScreen()->SetPixelChar(Down, L'¡ß');
		}
	}
}



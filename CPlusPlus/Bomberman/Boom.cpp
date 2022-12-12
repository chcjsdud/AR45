
#include "Boom.h"
#include <conio.h>
#include "ConsoleGameScreen.h"
#include "player.h"
#include <Windows.h>
Boom::Boom()
{

}

Boom::~Boom()
{

}

void Boom::Update()
{
	if (0 > --Time)
	{
		return;
	}

	ConsoleGameScreen::GetMainScreen()->SetPixelChar(Pos, GetRenderChar());
}



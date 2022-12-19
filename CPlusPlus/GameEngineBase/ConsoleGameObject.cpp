#include "ConsoleGameObject.h"
#include "ConsoleGameScreen.h"

ConsoleGameObject::ConsoleGameObject() 
{
}

ConsoleGameObject::~ConsoleGameObject() 
{
}



void ConsoleGameObject::Render()
{
	ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());
}
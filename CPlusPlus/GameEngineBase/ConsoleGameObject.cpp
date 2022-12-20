#include "ConsoleGameObject.h"
#include "ConsoleGameScreen.h"

ConsoleGameObject::ConsoleGameObject() 
{
}

ConsoleGameObject::~ConsoleGameObject() 
{
}

ConsoleGameObject::ConsoleGameObject(wchar_t _RenderChar)
	: RenderChar(_RenderChar)
{

}



void ConsoleGameObject::Render()
{
	ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());
}
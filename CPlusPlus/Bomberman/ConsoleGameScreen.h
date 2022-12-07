#pragma once
#include "ConsoleGameMath.h"

// Ό³Έν :
class ConsoleGameScreen
{
public:
	// constrcuter destructer
	ConsoleGameScreen();
	~ConsoleGameScreen();

	// delete Function
	ConsoleGameScreen(const ConsoleGameScreen& _Other) = delete;
	ConsoleGameScreen(ConsoleGameScreen&& _Other) noexcept = delete;
	ConsoleGameScreen& operator=(const ConsoleGameScreen& _Other) = delete;
	ConsoleGameScreen& operator=(ConsoleGameScreen&& _Other) noexcept = delete;

	void ScreenInit(const Int4& _Size, wchar_t _Char);

	void ScreenRender();

protected:
	

private:
	// wchar_t** ScreenChar;

};


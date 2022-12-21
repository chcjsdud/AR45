#pragma once
#include "ConsoleGameMath.h"
#include "GameEngineDebug.h"
#include <GameEngineArray.h>

//class ConsoleGameLine 
//{
//	wchar_t* Arr = nullptr;
//	wchar_t BaseChar;
//	size_t XCount = 0;
//
//public:
//	wchar_t& operator[](size_t _Index);
//
//	void Init(size_t _XCount, wchar_t _Char);
//	void Render();
//	void Clear();
//
//	~ConsoleGameLine();
//};

// 설명 :
class ConsoleGameScreen
{
private:
	static ConsoleGameScreen* MainScreen;

public:
	static ConsoleGameScreen* GetMainScreen() 
	{
		return MainScreen;
	}

public:
	// constrcuter destructer
	ConsoleGameScreen();
	~ConsoleGameScreen();

	// delete Function
	ConsoleGameScreen(const ConsoleGameScreen& _Other) = delete;
	ConsoleGameScreen(ConsoleGameScreen&& _Other) noexcept = delete;
	ConsoleGameScreen& operator=(const ConsoleGameScreen& _Other) = delete;
	ConsoleGameScreen& operator=(ConsoleGameScreen&& _Other) noexcept = delete;

	void ScreenInit(const int4& _Size, wchar_t _Char);

	void SetPixelChar(int4 _Pos, wchar_t _Char);

	void ScreenRender();
	void ScreenClear();

	bool IsOver(int4 _Pos);


protected:
	

private:

	// 사용하지 않았다를 *에는 nullptr을 넣어서 표현합니다. 
	GameEngineArray<GameEngineArray<wchar_t>> Lines;
	int4 ScreenSize;
	wchar_t BaseChar = '□';
};


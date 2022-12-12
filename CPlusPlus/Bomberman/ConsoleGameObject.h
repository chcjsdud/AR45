#pragma once
#include "ConsoleGameMath.h"

// ¼³¸í :
class ConsoleGameObject
{
public:
	// constrcuter destructer
	ConsoleGameObject();
	~ConsoleGameObject();

	// delete Function
	ConsoleGameObject(const ConsoleGameObject& _Other) = delete;
	ConsoleGameObject(ConsoleGameObject&& _Other) noexcept = delete;
	ConsoleGameObject& operator=(const ConsoleGameObject& _Other) = delete;
	ConsoleGameObject& operator=(ConsoleGameObject&& _Other) noexcept = delete;


	int4 GetPos()
	{
		return Pos;
	}

	void SetPos(const int4& _Value)
	{
		Pos = _Value;
	}

	void SetRenderChar(wchar_t _Value)
	{
		RenderChar = _Value;
	}

	wchar_t GetRenderChar()
	{
		return RenderChar;
	}

private:
	int4 Pos = { 0,0 };
	wchar_t RenderChar = L'¡¡';
};


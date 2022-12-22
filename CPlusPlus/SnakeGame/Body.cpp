#include "Body.h"
#include <iostream>
#include <ConsoleGameScreen.h>
#include <GameEngineInput.h>

Body* Body::CurBody = nullptr;

void Body::CreateBody() 
{
	srand(time(nullptr));

	CurBody = new Body();

	CurBody->SetPos({ rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().X , rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().Y });
}

Body* Body::GetCurBody()
{
	return CurBody;
}

Body::Body()
	: Part(L'★')
{
}

Body::~Body() 
{
}

void Body::Update() 
{
	// 나중에 이 제한을 풀어야 할 가능성이 높다.
	if (true == GameEngineInput::GetIsInput())
	{
		if (nullptr == GetFront())
		{
			return;
		}

		SetPos(GetFront()->GetPos());
	}
}

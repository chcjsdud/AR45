#include "Body.h"
#include <iostream>
#include <ConsoleGameScreen.h>
#include <GameEngineInput.h>

Body* Body::CurBody = nullptr;

void Body::CreateBody() 
{
	CurBody = new Body();

	CurBody->SetPos({ rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().X , rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().Y });
}

Body* Body::GetCurBody()
{
	return CurBody;
}

Body::Body()
	: Part(L'��')
{
}

Body::~Body() 
{
}

void Body::Update() 
{
	// ���߿� �� ������ Ǯ��� �� ���ɼ��� ����.
	if (true == GameEngineInput::GetIsInput())
	{
		if (nullptr == GetNext())
		{
			return;
		}

		SetPos(GetNext()->GetPos());
	}
}

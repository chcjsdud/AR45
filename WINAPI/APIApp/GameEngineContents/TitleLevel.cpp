#include "TitleLevel.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "TitleBack.h"

TitleLevel::TitleLevel() 
{
}

TitleLevel::~TitleLevel() 
{
}


void TitleLevel::Loading()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Title");

	// �̹��� �ε�
	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("TitleBack.BMP"));
	}

	if (false == GameEngineInput::IsKey("LevelChange"))
	{
		GameEngineInput::CreateKey("LevelChange", 'P');
		GameEngineInput::CreateKey("TitleScrollLeft", 'A');
		GameEngineInput::CreateKey("TitleScrollRight", 'D');
		GameEngineInput::CreateKey("TitleScrollUp", 'W');
		GameEngineInput::CreateKey("TitleScrollDown", 'S');
	}

	CreateActor<TitleBack>();

	Start = float4::Zero;
	End = float4(0.0f, GameEngineWindow::GetScreenSize().half().y);

}

bool ScrollStart = false;
float4 DownPosTitle = float4::Zero;

void TitleLevel::Update(float _DeltaTime)
{
	// if (true == GameEngineInput::IsDown("LevelChange"))
	if (true == GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::GetInst()->ChangeLevel("PlayLevel");
	}

	if (false == ScrollStart)
	{
		if (true == GameEngineInput::IsDown("TitleScrollLeft"))
		{
			End = Start + float4(-GameEngineWindow::GetScreenSize().half().x, 0.0f);
			ScrollStart = true;
		}
		else if (true == GameEngineInput::IsDown("TitleScrollRight"))
		{
			End = Start + float4(GameEngineWindow::GetScreenSize().half().x, 0.0f);
			ScrollStart = true;
		}
		else if (true == GameEngineInput::IsDown("TitleScrollUp"))
		{
			End = Start + float4(0.0f, GameEngineWindow::GetScreenSize().half().y);
			ScrollStart = true;
		}
		else if (true == GameEngineInput::IsDown("TitleScrollDown"))
		{
			End = Start + float4(0.0f, -GameEngineWindow::GetScreenSize().half().y);
			ScrollStart = true;
		}
	}


	if (true == ScrollStart)
	{
		// ���ۿ��� ������ �̵��ϴµ� 1�ʰ� �ɸ��� �Լ�
		Time += _DeltaTime * 0.5f;
		float4 Pos = float4::LerpClamp(Start, End, Time);
		SetCameraPos(Pos);

		if (Time >= 1.0f)
		{
			ScrollStart = false;
			Time = 0.0f;
			Start = Pos;
		}
	}

}

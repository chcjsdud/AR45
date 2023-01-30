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

	// 이미지 로드
	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("TitleBack.BMP"));
	}

	if (false == GameEngineInput::IsKey("LevelChange"))
	{
		GameEngineInput::CreateKey("LevelChange", 'P');
		GameEngineInput::CreateKey("TitleScroll", 'O');
	}

	CreateActor<TitleBack>();

}

bool Start = false;
float4 DownPosTitle = float4::Zero;

void TitleLevel::Update(float _DeltaTime)
{
	// if (true == GameEngineInput::IsDown("LevelChange"))
	if (true == GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::GetInst()->ChangeLevel("PlayLevel");
	}

	if (true == GameEngineInput::IsDown("TitleScroll"))
	{
		Start = true;
	}

	if (true == Start)
	{
		DownPosTitle += float4::Down * 100.0f * _DeltaTime;

		SetCameraMove(float4::Down * 100.0f * _DeltaTime);

		if (GameEngineWindow::GetScreenSize().half().y <= DownPosTitle.y)
		{
			DownPosTitle.y = GameEngineWindow::GetScreenSize().half().y;
			SetCameraPos(DownPosTitle);
			Start = false;
		}
	}
}

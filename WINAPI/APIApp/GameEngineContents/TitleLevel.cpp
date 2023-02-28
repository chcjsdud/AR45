#include "TitleLevel.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/Button.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "TitleBack.h"
#include "MouseObject.h"
#include "ContentsValue.h"

TitleLevel::TitleLevel() 
{
}

TitleLevel::~TitleLevel() 
{
}

void TestError(Button* _Btn) 
{
	MsgAssert("버튼을 눌렀습니다.");
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

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Hover.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Press.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Release.BMP"));
	}

	if (false == GameEngineInput::IsKey("LevelChange"))
	{
		GameEngineInput::CreateKey("LevelChange", 'P');
		GameEngineInput::CreateKey("TitleScrollLeft", 'A');
		GameEngineInput::CreateKey("TitleScrollRight", 'D');
		GameEngineInput::CreateKey("TitleScrollUp", 'W');
		GameEngineInput::CreateKey("TitleScrollDown", 'S');
	}

	MouseObject* MouseObjectInst = CreateActor<MouseObject>();

	MouseObjectInst->GetMouseRender()->EffectCameraOff();
	MouseObjectInst->GetMouseRender()->SetOrder(100);
	MouseObjectInst->GetMouseRender()->SetScale({50, 50});
	MouseObjectInst->GetMouseRender()->SetImage("Hover.BMP");

	CreateActor<TitleBack>();

	Button* NewButton = CreateActor<Button>();
	NewButton->GetButtonRender()->EffectCameraOff();
	NewButton->SetPos(GameEngineWindow::GetScreenSize().half());
	NewButton->SetHoverImage("Hover.BMP");
	NewButton->SetPressImage("Press.BMP");
	NewButton->SetReleaseImage("Release.BMP");
	NewButton->SetScale({100, 100});
	NewButton->SetClickCallBack(TestError);

	// GameEngineInput::MouseCursorOff();

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
		// 시작에서 끝까지 이동하는데 1초가 걸리는 함수
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


void TitleLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	ContentsValue::CameraScale = { 2000, 3000 };
}
#include "PlayLevel.h"

#include "Structs.h"

// 프로젝트 순서에 따라서 정렬
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>

// 나랑 같은 등급의 헤더들
#include "Player.h"
#include "Monster.h"
#include "Map.h"
#include "ContentsEnums.h"
#include "ContentsValue.h"

PlayLevel::PlayLevel()
{
	// SetName("PlayerLevel");

	// WeaponInfo::Infos.insert(std::make_pair(std::string("철검"), WeaponInfo{ 10, "aaaaa.bmp"}));
	WeaponInfo::Infos["철검"] = WeaponInfo{10, "aaaaa.bmp"};
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::SoundLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Sound");

	{
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Appear.wav"));
	}

	// GameEngineResources::GetInst().SoundPlay("Appear.wav");

}
void PlayLevel::ImageLoad()
{

	// 상대경로 탐색
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");

	// 이미지 로드
	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Right_Player.BMP"));
		Image->Cut(5, 17);
	}
	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Left_Player.BMP"));
		Image->Cut(5, 17);
	}
	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BackGround.BMP"));
		Image->Cut(3, 1);
	}
	{
		GameEngineImage* Image2 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Map.BMP"));
		GameEngineImage* Image3 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ColMap.BMP"));
	}
	{
		GameEngineImage* Image2 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Number.BMP"));
		Image2->Cut(10, 1);
	}

}

void PlayLevel::Loading()
{
	SoundLoad();
	ImageLoad();

	SetCameraScale({1000, 100});


	{
		Map* Actor = CreateActor<Map>();
	}
	{
		Player* Actor = CreateActor<Player>(BubbleRenderOrder::Player);
		Actor->SetMove(GameEngineWindow::GetScreenSize().half());
		Actor->SetMove({100, 0});
	}
	{
		srand(static_cast<unsigned int>(time(nullptr)));
		for (size_t i = 0; i < 0; i++)
		{
			Monster* Actor = CreateActor<Monster>(BubbleRenderOrder::Monster);
			Actor->SetMove(
				float4(static_cast<float>(rand() % GameEngineWindow::GetScreenSize().ix()), static_cast<float>(rand() % GameEngineWindow::GetScreenSize().iy()))
			);
		}
	}


	if (false == GameEngineInput::IsKey("DebugRenderSwitch"))
	{
		GameEngineInput::CreateKey("DebugRenderSwitch", 'R');
	}


	if (false == GameEngineInput::IsKey("CameraLeftMove"))
	{
		// VK 알파뱃과 숫자를 제외한 키를 표현하는데 쓰고 있다. 
		GameEngineInput::CreateKey("CameraLeftMove", VK_LEFT);
		GameEngineInput::CreateKey("CameraRightMove", VK_RIGHT);
		GameEngineInput::CreateKey("CameraDownMove", VK_DOWN);
		GameEngineInput::CreateKey("CameraUpMove", VK_UP);
	}

	// class NumbersRender : GameEngineActor
	// {
	// }

	// NumbersRender = CreateActor<NumbersRender>();
	// NumbersRender->SetValue(190111);
}

void PlayLevel::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("DebugRenderSwitch"))
	{
		BGMPlayer.Stop();
		DebugRenderSwitch();
		// Player::MainPlayer->Death()p;
	}

	float CameraMoveSpeed = 100.0f;

	//if (GameEngineInput::IsPress("CameraLeftMove"))
	//{
	//	SetCameraMove(float4::Left * _DeltaTime * CameraMoveSpeed);
	//}
	//if (GameEngineInput::IsPress("CameraRightMove"))
	//{
	//	SetCameraMove(float4::Right * _DeltaTime * CameraMoveSpeed);
	//}
	//if (GameEngineInput::IsPress("CameraDownMove"))
	//{
	//	SetCameraMove(float4::Down * _DeltaTime * CameraMoveSpeed);
	//}
	//if (GameEngineInput::IsPress("CameraUpMove"))
	//{
	//	SetCameraMove(float4::Up * _DeltaTime * CameraMoveSpeed);
	//}

}

void PlayLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{

	BGMPlayer = GameEngineResources::GetInst().SoundPlayToControl("Appear.wav");
	BGMPlayer.LoopCount(100);


	ContentsValue::CameraScale = { 2000, 3000 };
	int a = 0;
}
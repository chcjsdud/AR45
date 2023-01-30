#include "PlayLevel.h"

// 프로젝트 순서에 따라서 정렬
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>

// 나랑 같은 등급의 헤더들
#include "Player.h"
#include "Map.h"

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::Loading()
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
		Map* Actor = CreateActor<Map>();

		// Actor->GetRender()
		// Actor->GetRender()->SetImage();
	}
	{
		Player* Actor = CreateActor<Player>();

		// 횡스크롤류 게임은 맵의 크기를 
		// 시작위치를 
		// 레벨마다 배경맵 이미지가 다를것이고
		// 그때마다 스테이지가 다르니까.
		//Actor->SetMove();
		//SetCameraMove();

	}


	if (false == GameEngineInput::IsKey("PlayerOff"))
	{
		GameEngineInput::CreateKey("PlayerOff", 'R');
	}


	if (false == GameEngineInput::IsKey("CameraLeftMove"))
	{
		// VK 알파뱃과 숫자를 제외한 키를 표현하는데 쓰고 있다. 
		GameEngineInput::CreateKey("CameraLeftMove", VK_LEFT);
		GameEngineInput::CreateKey("CameraRightMove", VK_RIGHT);
		GameEngineInput::CreateKey("CameraDownMove", VK_DOWN);
		GameEngineInput::CreateKey("CameraUpMove", VK_UP);
	}
}

void PlayLevel::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("PlayerOff"))
	{
		Player::MainPlayer->OnOffSwtich();
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
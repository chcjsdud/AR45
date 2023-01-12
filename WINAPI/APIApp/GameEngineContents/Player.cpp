#include "Player.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"

Player::Player() 
{
}

Player::~Player() 
{
}

void Player::Start()
{
	SetMove(GameEngineWindow::GetScreenSize().half());

	{
		GameEngineRender* Render = CreateRender("Heros.bmp", BubbleRenderOrder::BackGround);
		Render->SetScale({ 100, 100 });
	}

	{
		GameEngineRender* Render = CreateRender("aaaaa.bmp", BubbleRenderOrder::Player);
		Render->SetPosition({ 10, 0 });
		Render->SetScale({ 500, 500 });
	}


	// Render->SetPosition({0.0f, -100.0f});

	// CreateRender("PlayerCharacter.Bmp");

}

void Player::Update(float _DeltaTime) 
{
	// AccTime += _DeltaTime;

	// 렉이라고 하는 현상.
	//for (size_t i = 0; i < 1000000000; i++)
	//{

	//}
	
	// 1.0f * AccTime
	// SetMove(float4::Left * 100.0f * _DeltaTime);
}

void Player::Render(float _DeltaTime)
{
	// 디버깅용.
}
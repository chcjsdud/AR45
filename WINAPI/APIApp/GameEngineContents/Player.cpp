#include "Player.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "ContentsEnums.h"

Player* Player::MainPlayer;

Player::Player() 
{
}

Player::~Player() 
{
}

void Player::Start()
{
	MainPlayer = this;

	SetMove(GameEngineWindow::GetScreenSize().half());


	if (false == GameEngineInput::IsKey("LeftMove"))
	{
		GameEngineInput::CreateKey("LeftMove", 'A');
		GameEngineInput::CreateKey("RightMove", 'D');
		GameEngineInput::CreateKey("DownMove", 'S');
		GameEngineInput::CreateKey("UpMove", 'W');
	}

	{
		GameEngineRender* Render = CreateRender("Heros.bmp", BubbleRenderOrder::BackGround);
		Render->SetScale({ 100, 100 });
		Render->SetFrame(4);
	}

	// Render->SetPosition({0.0f, -100.0f});

	// CreateRender("PlayerCharacter.Bmp");

}

void Player::Update(float _DeltaTime) 
{
	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		SetMove(float4::Left * MoveSpeed * _DeltaTime);
	}

	if (true == GameEngineInput::IsPress("RightMove"))
	{
		SetMove(float4::Right * MoveSpeed * _DeltaTime);
	}

	if (true == GameEngineInput::IsPress("UpMove"))
	{
		SetMove(float4::Up * MoveSpeed * _DeltaTime);
	}

	if (true == GameEngineInput::IsPress("DownMove"))
	{
		SetMove(float4::Down * MoveSpeed * _DeltaTime);
	}

	//if (0 != GetAsyncKeyState('A'))
	//{
	//	SetMove(float4::Left * 100.0f * _DeltaTime);
	//}

	//if (0 != GetAsyncKeyState('D'))
	//{
	//	SetMove(float4::Right * 100.0f * _DeltaTime);
	//}

	//if (0 != GetAsyncKeyState('W'))
	//{
	//	SetMove(float4::Up * 100.0f * _DeltaTime);
	//}

	//if (0 != GetAsyncKeyState('S'))
	//{
	//	SetMove(float4::Down * 100.0f * _DeltaTime);
	//}

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
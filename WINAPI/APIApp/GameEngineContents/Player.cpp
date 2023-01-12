#include "Player.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>

Player::Player() 
{
}

Player::~Player() 
{
}

void Player::Start()
{
	SetMove(GameEngineWindow::GetScreenSize().half());
}

void Player::Update(float _DeltaTime) 
{
	// AccTime += _DeltaTime;

	// 렉이라고 하는 현상.
	//for (size_t i = 0; i < 1000000000; i++)
	//{

	//}
	
	// 1.0f * AccTime
	SetMove(float4::Left * 100.0f * _DeltaTime);
}

void Player::Render(float _DeltaTime)
{
	float4 PlayerPos = GetPos();
	GameEngineImage* Image = GameEngineResources::GetInst().ImageFind("Heros.bmp");

	AccTime += _DeltaTime;

	if (AccTime >= 0.1f)
	{
		// AccTime = 0.0f;
		AccTime -= 0.1f;
		++StartFrame;
	}

	if (10 < StartFrame)
	{
		StartFrame = 0;
	}

	GameEngineWindow::GetDoubleBufferImage()->TransCopy(Image, StartFrame, PlayerPos, { 100, 200 });
}
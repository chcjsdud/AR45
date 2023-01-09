#include "Player.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>

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

void Player::Update() 
{
	SetMove(float4::Left * 0.0001f);
}

void Player::Render() 
{
	float4 PlayerPos = GetPos();

	//GameEnginePath Path;

	//std::string PathText = Path.GetPathToString();

	// TextOutA(GameEngineWindow::GetDrawHdc(), 0, 0, PathText.c_str(), PathText.size());

	char Color[4] = {255, 0, 0, 0};
	int* Ptr = reinterpret_cast<int*>(Color);

	SetPixel(
		GameEngineWindow::GetWindowBackBufferHdc(),
		10, 10, *Ptr
	);


	Rectangle(
		GameEngineWindow::GetWindowBackBufferHdc(),
		PlayerPos.ix() - 50, 
		PlayerPos.iy() - 50, 
		PlayerPos.ix() + 50,
		PlayerPos.iy() + 50
		);

}
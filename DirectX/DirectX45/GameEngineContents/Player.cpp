#include "PrecompileHeader.h"
#include "Player.h"
#include <GameEngineCore/GameEngineFBXRenderer.h>

Player::Player() 
{
}

Player::~Player() 
{
}


void Player::Start()
{
	std::shared_ptr<GameEngineFBXRenderer> Renderer = CreateComponent<GameEngineFBXRenderer>();

	Renderer->SetFBXMesh("AnimMan.FBX", "MeshTexture");

}
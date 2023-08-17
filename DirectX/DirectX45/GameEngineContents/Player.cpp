#include "PrecompileHeader.h"
#include "Player.h"
#include <GameEngineCore/GameEngineFBXRenderer.h>
#include "ObjectUpdatePacket.h"

Player* Player::MainPlayer = nullptr;

Player::Player() 
{
	MainPlayer = this;
}

Player::~Player() 
{
}


void Player::Start()
{
	if (false == GameEngineInput::IsKey("MoveLeft"))
	{
		GameEngineInput::CreateKey("MoveLeft", 'A');
		GameEngineInput::CreateKey("MoveRight", 'D');
		GameEngineInput::CreateKey("MoveUp", 'Q');
		GameEngineInput::CreateKey("MoveDown", 'E');
		GameEngineInput::CreateKey("MoveForward", 'W');
		GameEngineInput::CreateKey("MoveBack", 'S');

		//GameEngineInput::CreateKey("RotY+", VK_NUMPAD1);
		//GameEngineInput::CreateKey("RotY-", VK_NUMPAD2);
		//GameEngineInput::CreateKey("RotZ+", VK_NUMPAD4);
		//GameEngineInput::CreateKey("RotZ-", VK_NUMPAD5);
		//GameEngineInput::CreateKey("RotX+", VK_NUMPAD7);
		//GameEngineInput::CreateKey("RotX-", VK_NUMPAD8);
	}


	std::shared_ptr<GameEngineFBXRenderer> Renderer = CreateComponent<GameEngineFBXRenderer>();
	Renderer->SetFBXMesh("House1.FBX", "MeshTexture");
	// Renderer->SetFBXMesh("AnimMan.FBX", "MeshTexture", 0, 0);
	// Renderer->SetFBXMesh("AnimMan.FBX", "MeshTexture", 0, 2);

}

void Player::Update(float _DeltaTime)
{
	// 서버의 관리를 받는 오브젝트라면
	// 클라이언트의 입장에서는 
	// 상대의 패킷으로만 움직여야 한다.
	// 2가지로 나뉘게 된다.

	NetControllType Type = GetControllType();

	switch (Type)
	{
	case NetControllType::None:
		UserUpdate(_DeltaTime);
		break;
	case NetControllType::UserControll:
		UserUpdate(_DeltaTime);
		break;
	case NetControllType::ServerControll:
		ServerUpdate(_DeltaTime);
		break;
	default:
		break;
	}

}

void Player::UserUpdate(float _DeltaTime)
{
	// 직접 조작할때는 아래와 같이
	float Speed = 200.0f;

	if (true == GameEngineInput::IsPress("MoveLeft"))
	{
		GetTransform()->AddLocalPosition(GetTransform()->GetWorldLeftVector() * Speed * _DeltaTime);
	}
	if (true == GameEngineInput::IsPress("MoveRight"))
	{
		GetTransform()->AddLocalPosition(GetTransform()->GetWorldRightVector() * Speed * _DeltaTime);
	}
	if (true == GameEngineInput::IsPress("MoveUp"))
	{
		GetTransform()->AddLocalPosition(GetTransform()->GetWorldUpVector() * Speed * _DeltaTime);
	}
	if (true == GameEngineInput::IsPress("MoveDown"))
	{
		GetTransform()->AddLocalPosition(GetTransform()->GetWorldDownVector() * Speed * _DeltaTime);
	}
	if (true == GameEngineInput::IsPress("MoveForward"))
	{
		GetTransform()->AddLocalPosition(GetTransform()->GetWorldForwardVector() * Speed * _DeltaTime);
	}
	if (true == GameEngineInput::IsPress("MoveBack"))
	{
		GetTransform()->AddLocalPosition(GetTransform()->GetWorldBackVector() * Speed * _DeltaTime);
	}

	static float Delta = 0.0f;

	Delta += _DeltaTime;

	if (Delta <= 1.0f / 60.0f)
	{
		return;
	}

	Delta -= 1.0f / 60.0f;
	
	if (true == IsNet())
	{
		std::shared_ptr<ObjectUpdatePacket> NewPacket = std::make_shared<ObjectUpdatePacket>();
		NewPacket->SetObjectID(GetNetObjectID());
		NewPacket->Position = GetTransform()->GetWorldPosition();
		NewPacket->Rotation = GetTransform()->GetWorldPosition();
		GetNet()->SendPacket(NewPacket);
	}
	
}
void Player::ServerUpdate(float _DeltaTime)
{

}
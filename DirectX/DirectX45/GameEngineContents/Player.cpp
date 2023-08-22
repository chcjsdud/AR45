#include "PrecompileHeader.h"
#include "Player.h"
#include <GameEngineCore/GameEngineFBXRenderer.h>
#include <GameEngineCore/GameEngineFontRenderer.h>
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


	{
		std::shared_ptr<GameEngineFBXRenderer> Renderer = CreateComponent<GameEngineFBXRenderer>();
		Renderer->SetFBXMesh("House1.FBX", "MeshTexture");
	}

	{
		std::shared_ptr<GameEngineFontRenderer> Renderer = CreateComponent<GameEngineFontRenderer>();
		Renderer->SetScale(100.0f);
		Renderer->SetFont("�ü�");
		Renderer->SetText("aaaaaaaaaa");
	}

	//Renderer->SetFBXMesh("AnimMan.FBX", "MeshAniTexture");
	//Renderer->CreateFBXAnimation("Run", "ALS_N_Run_F.FBX");
	//Renderer->ChangeAnimation("Run");


	// Renderer->SetFBXMesh("House1.FBX", "MeshTexture");
	// Renderer->SetFBXMesh("AnimMan.FBX", "MeshTexture", 0, 0);
	// Renderer->SetFBXMesh("AnimMan.FBX", "MeshTexture", 0, 2);

}

void Player::Update(float _DeltaTime)
{
	// ������ ������ �޴� ������Ʈ���
	// Ŭ���̾�Ʈ�� ���忡���� 
	// ����� ��Ŷ���θ� �������� �Ѵ�.
	// 2������ ������ �ȴ�.

	NetControllType Type = GetControllType();
	switch (Type)
	{
	case NetControllType::UserControll:
		UserUpdate(_DeltaTime);
		break;
	case NetControllType::NetControll:
		NetUpdate(_DeltaTime);
		break;
	default:
		break;
	}

}

void Player::NetUpdate(float _DeltaTime)
{
	if (false == IsPacket())
	{
		return;
	}

	while (IsPacket())
	{
		PacketEnum Type = GetFirstPacketType<PacketEnum>();

		switch (Type)
		{
		case PacketEnum::ObjectUpdatePacket:
		{
			std::shared_ptr<ObjectUpdatePacket> ObjectUpdate = PopFirstPacket<ObjectUpdatePacket>();
			GetTransform()->SetLocalPosition(ObjectUpdate->Position);
			GetTransform()->SetLocalRotation(ObjectUpdate->Rotation);
			break;
		}
		default:
			MsgAssert("ó������ ���ϴ� ��Ŷ�� �÷��̾�� ���ƿԽ��ϴ�.");
			return;
		}
	}

}

void Player::UserUpdate(float _DeltaTime)
{
	// ���� �����Ҷ��� �Ʒ��� ����
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
		NewPacket->Position = GetTransform()->GetLocalPosition();
		NewPacket->Rotation = GetTransform()->GetLocalRotation();
		GetNet()->SendPacket(NewPacket);
	}
	
}
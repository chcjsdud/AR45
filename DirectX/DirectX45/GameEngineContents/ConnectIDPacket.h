#pragma once
#include <GameEngineBase/GameEnginePacket.h>
#include <GameEngineCore/GameEngineTransform.h>

// ���� : �� 0�� �÷��̾��
//        �� 1�� �÷��̾��
class ConnectIDPacket : public GameEnginePacket
{
public:
	// constrcuter destructer
	ConnectIDPacket();
	~ConnectIDPacket();

	// delete Function
	ConnectIDPacket(const ConnectIDPacket& _Other) = delete;
	ConnectIDPacket(ConnectIDPacket&& _Other) noexcept = delete;
	ConnectIDPacket& operator=(const ConnectIDPacket& _Other) = delete;
	ConnectIDPacket& operator=(ConnectIDPacket&& _Other) noexcept = delete;

protected:

private:
};


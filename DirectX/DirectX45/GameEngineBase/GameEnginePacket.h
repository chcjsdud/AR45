#pragma once
#include "GameEngineSerializer.h"
#include <memory>

// ���� :
class GameEnginePacket : public std::enable_shared_from_this<GameEnginePacket>
{
public:
	// constrcuter destructer
	GameEnginePacket();
	~GameEnginePacket();

	// delete Function
	GameEnginePacket(const GameEnginePacket& _Other) = delete;
	GameEnginePacket(GameEnginePacket&& _Other) noexcept = delete;
	GameEnginePacket& operator=(const GameEnginePacket& _Other) = delete;
	GameEnginePacket& operator=(GameEnginePacket&& _Other) noexcept = delete;

protected:

private:
	unsigned int PacketID = -1; // <= �����ε� int�� ó���Ѵ�.
	unsigned int Size = -1; // <= ��Ŷ�� ũ��
	unsigned int ObjectID = -1; // <= � ������Ʈ�� ���´�.

};

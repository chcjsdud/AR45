#pragma once
#include "PacketEnum.h"
#include <GameEngineBase/GameEnginePacket.h>
#include <GameEngineCore/GameEngineTransform.h>

// 설명 : 넌 0번 플레이어야
//        넌 1번 플레이어야
class ConnectIDPacket : public GameEnginePacket
{
public:
	// constrcuter destructer
	ConnectIDPacket()
	{
		SetPacketID(PacketEnum::ConnectIDPacket);
	}
	~ConnectIDPacket()
	{

	}

protected:
	void Serialize(GameEngineSerializer& _Ser) override
	{
		GameEnginePacket::Serialize(_Ser);
		_Ser << TestValue;
	}

	void DeSeralize(GameEngineSerializer& _Ser) override
	{
		GameEnginePacket::DeSeralize(_Ser);
		_Ser << TestValue;
	}

private:
	int TestValue = 999;
};


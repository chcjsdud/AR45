#pragma once
#include "GameEngineSerializer.h"
#include "GameEngineDebug.h"
#include <memory>

// ���� :
class GameEnginePacket : public std::enable_shared_from_this<GameEnginePacket>
{
public:
	// constrcuter destructer
	GameEnginePacket();
	virtual ~GameEnginePacket();

	// delete Function
	GameEnginePacket(const GameEnginePacket& _Other) = delete;
	GameEnginePacket(GameEnginePacket&& _Other) noexcept = delete;
	GameEnginePacket& operator=(const GameEnginePacket& _Other) = delete;
	GameEnginePacket& operator=(GameEnginePacket&& _Other) noexcept = delete;

	template<typename EnumType>
	void SetPacketID(EnumType _PacketID)
	{
		PacketID = static_cast<int>(_PacketID);
	}

	void SetPacketID(unsigned int _PacketID)
	{
		PacketID = _PacketID;
	}

	void SerializePacket(GameEngineSerializer& _Ser)
	{
		Serialize(_Ser);
		SerializeEnd(_Ser);
	}

	void DeSerializePacket(GameEngineSerializer& _Ser)
	{
		DeSeralize(_Ser);
	}

	unsigned int GetPacketID()
	{
		return PacketID;
	}

	unsigned int GetObjectID()
	{
		return ObjectID;
	}

	void SetObjectID(unsigned int _ObjectID)
	{
		ObjectID = _ObjectID;
	}

protected:
	virtual void Serialize(GameEngineSerializer& _Ser)
	{
		_Ser << PacketID;
		_Ser << Size;
		_Ser << ObjectID;
	}

	virtual void DeSeralize(GameEngineSerializer& _Ser)
	{
		_Ser >> PacketID;
		_Ser >> Size;
		_Ser >> ObjectID;
	}

private:
	unsigned int PacketID = -1; // <= �����ε� int�� ó���Ѵ�.
	unsigned int Size = -1; // <= ��Ŷ�� ũ��
	unsigned int ObjectID = -1; // <= � ������Ʈ�� ���´�.

	void SerializeEnd(GameEngineSerializer& _Ser)
	{
		Size = _Ser.GetWriteOffSet();

		if (Size <= 0)
		{
			MsgAssert("0����Ʈ ��Ŷ�� �����Ǿ����ϴ�.");
		}

		// �̳༮�� 4����Ʈ ��°�� �����͸� size�� ��ü�Ѵ�.
		unsigned char* Ptr = _Ser.GetDataPtr();
		memcpy_s(&Ptr[4], sizeof(int), &Size, sizeof(int));
	}
};

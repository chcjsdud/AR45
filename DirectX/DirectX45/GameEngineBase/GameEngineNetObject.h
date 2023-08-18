#pragma once
#include "GameEngineNet.h"

// �������忡���� ������
// ���� ���� ���͵� ��������� ���ٸ� �ᱹ ������Ʈ�ϻ��̴�.
// ���͵��� 

enum class NetControllType
{
	NetControll,
	UserControll,
};

// ���� :
class GameEngineNetObject
{
public:
	static void PushNetObjectPacket(std::shared_ptr<GameEnginePacket> _Packet)
	{
		int Id = _Packet->GetObjectID();

		if (false == AllNetObjects.contains(Id))
		{
			MsgAssert("�������� �ʴ� ������Ʈ�� ��Ŷ�� ���ƿԽ��ϴ�.");
		}

		AllNetObjects[Id]->PushPacket(_Packet);
	}

	static bool IsNetObject(int _Id)
	{
		return AllNetObjects.contains(_Id);
	}

	// constrcuter destructer
	GameEngineNetObject();
	~GameEngineNetObject();

	// delete Function
	GameEngineNetObject(const GameEngineNetObject& _Other) = delete;
	GameEngineNetObject(GameEngineNetObject&& _Other) noexcept = delete;
	GameEngineNetObject& operator=(const GameEngineNetObject& _Other) = delete;
	GameEngineNetObject& operator=(GameEngineNetObject&& _Other) noexcept = delete;

	static int CreateServerID()
	{
		return ++AtomicObjectID;
	}

	void InitNetObject(int _ObjectID, GameEngineNet* _Net);

	void SetControll(NetControllType _ControllType)
	{
		ControllType = _ControllType;
	}

	NetControllType GetControllType()
	{
		return ControllType;
	}

	void SetUserControllType()
	{
		ControllType = NetControllType::UserControll;
	}

	int GetNetObjectID()
	{
		return ObjectID;
	}

	bool IsNet()
	{
		return nullptr != Net;
	}

	GameEngineNet* GetNet() 
	{
		return Net;
	}

	void PushPacket(std::shared_ptr<GameEnginePacket> _Packet);

	bool IsPacket() 
	{
		return Packets.size();
	}

	template<typename PacketType>
	std::shared_ptr<PacketType> PopFirstPacket()
	{
		std::shared_ptr<PacketType> PacketReturn = std::dynamic_pointer_cast<PacketType>(Packets.front());
		Packets.pop_front();
		return PacketReturn;
	}

	template<typename EnumType>
	EnumType GetFirstPacketType()
	{
		return static_cast<EnumType>(Packets.front()->GetPacketID());
	}

protected:

private:
	static std::atomic<int> AtomicObjectID;
	static std::mutex ObjectLock;
	static std::map<int, GameEngineNetObject*> AllNetObjects;

	NetControllType ControllType = NetControllType::NetControll;
	int ObjectID = -1;

	GameEngineNet* Net = nullptr;

	std::list<std::shared_ptr<GameEnginePacket>> Packets;
};


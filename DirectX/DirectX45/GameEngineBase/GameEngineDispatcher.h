#pragma once
#include <functional>
#include "GameEnginePacket.h"

// ���� :
class GameEngineDispatcher
{
public:
	// constrcuter destructer
	GameEngineDispatcher();
	~GameEngineDispatcher();

	// delete Function
	GameEngineDispatcher(const GameEngineDispatcher& _Other) = delete;
	GameEngineDispatcher(GameEngineDispatcher&& _Other) noexcept = delete;
	GameEngineDispatcher& operator=(const GameEngineDispatcher& _Other) = delete;
	GameEngineDispatcher& operator=(GameEngineDispatcher&& _Other) noexcept = delete;

	template<typename PacketType, typename EnumType>
	void AddHandler(std::function<void(std::shared_ptr<PacketType>)> _CallBack)
	{
		AddHandler(_CallBack);
	}

	template<typename PacketType>
	void AddHandler(std::function<void(std::shared_ptr<PacketType>)> _CallBack)
	{
		int Type = static_cast<int>(PacketType::Type);

		if (true == PacketHandlers.contains(Type))
		{
			MsgAssert("�̹� �����ϴ� �ڵ巯�� �� ����Ϸ��� �߽��ϴ�.");
		}

		ConvertPacketHandlers[Type] = [=](GameEngineSerializer& _Ser)
		{
			std::shared_ptr<PacketType> NewPacket = std::make_shared<PacketType>();
			NewPacket->DeSerializePacket(_Ser);
			return NewPacket;
		};

		PacketHandlers[Type] = [=](std::shared_ptr<GameEnginePacket> _Packet)
		{
			std::shared_ptr<PacketType> ConvertPacket = std::dynamic_pointer_cast<PacketType>(_Packet);

			if (nullptr == ConvertPacket)
			{
				MsgAssert("��Ŷ Ÿ�� ��ȯ�� �����߽��ϴ�.");
			}

			_CallBack(ConvertPacket);
		};
	}

	std::shared_ptr<GameEnginePacket> ConvertPacket(int Type, GameEngineSerializer& _Ser)
	{
		if (false == ConvertPacketHandlers.contains(Type))
		{
			MsgAssert("AddHandler�� ������� ���� ��Ŷ�Դϴ�");
			return nullptr;
		}

		return ConvertPacketHandlers[Type](_Ser);
	}

	void ProcessPacket(std::shared_ptr<GameEnginePacket> _Packet)
	{
		if (false == PacketHandlers.contains(_Packet->GetPacketID()))
		{
			MsgAssert("AddHandler�� ������� ���� ��Ŷ�Դϴ�");
			return;
		}

		PacketHandlers[_Packet->GetPacketID()](_Packet);
	}


protected:

private:
	// 0���� ������ ConnectIDPacket �ٲ㼭 ����
	// 1���� ������ ObjectUpdatePacket �ٲ㼭 ����
	std::map<int, std::function<std::shared_ptr<GameEnginePacket>(GameEngineSerializer&)>> ConvertPacketHandlers;

	// � ��Ŷ�� ������ ��� ó����?
	// int Packet 
	// std::function<void(std::shared_ptr<ConnectIDPacket>)>
	// std::function<void(std::shared_ptr<GameEnginePacket>)>
	std::map<int, std::function<void(std::shared_ptr<GameEnginePacket>)>> PacketHandlers;
};


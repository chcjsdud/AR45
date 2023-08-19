#include "PrecompileHeader.h"
#include "GameEngineNet.h"
#include "GameEngineSerializer.h"
#include "GameEnginePacket.h"

GameEngineNet::GameEngineNet() 
{
}

GameEngineNet::~GameEngineNet() 
{
	IsNetValue = false;
}

void GameEngineNet::RecvThreadFunction(SOCKET _Socket, GameEngineNet* _Net)
{
	// 1500 - 1024
	char Data[1024] = { 0 };

	GameEngineSerializer Serializer;
	unsigned int PacketType = -1;
	unsigned int PacketSize = -1;

	while (true == _Net->IsNet())
	{
		// ��밡 ������ ��Ŷ�� ��.
		int Result = recv(_Socket, Data, sizeof(Data), 0);

		// ���� ����
		if (-1 == Result)
		{
			return;
		}

		// ���� ����
		if (SOCKET_ERROR == _Socket || INVALID_SOCKET == _Socket)
		{
			return;
		}

		// TCP ���� ������ �ɼ� �ִºκ�.
		// TCP�� 12����Ʈ�� ��ٸ�
		// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
		// 7����Ʈ

		// �츮�� ���������� 
		// ������ ������
		// �Ǿ� 4����Ʈ ��Ŷ�� Ÿ��
		// �� �� 4����Ʈ ������ 
		Serializer.Write(Data, Result);

		if (8 > Serializer.GetWriteOffSet())
		{
			continue;
		}

		// 8����Ʈ �̻� �޾Ұ�
		// ���� ��ŶŸ���� ���� �˾Ƴ��� ���ߴٸ�
		if (-1 == PacketType)
		{
			// ��ŶŸ�� �˾Ƴ���.
			{
				unsigned char* TypePivotPtr = &Serializer.GetDataPtr()[0];
				int* ConvertPtr = reinterpret_cast<int*>(TypePivotPtr);
				PacketType = *ConvertPtr;
			}

			// ������ �˾Ƴ���
			{
				unsigned char* SizePivotPtr = &Serializer.GetDataPtr()[4];
				int* ConvertPtr = reinterpret_cast<int*>(SizePivotPtr);
				PacketSize = *ConvertPtr;
			}
		}

		// ��Ŷ������ε� �����Ұ� �ּ� �ִ� ��Ŷ�̶����
		if (-1 == PacketSize)
		{
			return;
		}

		// 8����Ʈ �̻� �޾�����
		// �װ� ���ؼ� �˾Ƴ� ��Ŷ�� ũ�⺸�ٴ� ���Ҿ�. 
		if (PacketSize > Serializer.GetWriteOffSet())
		{
			continue;
		}

		while (true)
		{
			
			// ConnectIDPacket
			std::shared_ptr<GameEnginePacket> Packet = _Net->Dispatcher.ConvertPacket(PacketType, Serializer);

			if (nullptr != Packet)
			{
				_Net->RecvPacketLock.lock();
				_Net->RecvPacket.push_back(Packet);
				_Net->RecvPacketLock.unlock();
			} else 
			{
				int a = 0;
			}

			// Write�� ������ ���̴�.
			// _Net->Dispatcher.ProcessPacket(Packet);
			
			// 12 ����Ʈ�� ���ƿԴµ� 12����Ʈ�� ó���ƴ�.
			if (Serializer.GetWriteOffSet() == Serializer.GetReadOffSet())
			{
				Serializer.Reset();
				PacketType = -1;
				PacketSize = -1;
				break;
			}
			else
			{
				unsigned int RemainSize = Serializer.GetWriteOffSet() - Serializer.GetReadOffSet();

				if (8 > RemainSize)
				{
					break;
				}

				{
					unsigned char* TypePivotPtr = &Serializer.GetDataPtr()[0];
					int* ConvertPtr = reinterpret_cast<int*>(TypePivotPtr);
					PacketType = *ConvertPtr;
				}

				{
					unsigned char* SizePivotPtr = &Serializer.GetDataPtr()[4];
					int* ConvertPtr = reinterpret_cast<int*>(SizePivotPtr);
					PacketSize = *ConvertPtr;
				}

				if (RemainSize < PacketSize)
				{
					// ���� ��ű⸦ �� ������ �о������.
					Serializer.ClearReadData();
					break;
				}
			}
		}
	}
}



void GameEngineNet::SendPacket(std::shared_ptr<GameEnginePacket> _Packet, int _IgnoreID)
{
	GameEngineSerializer Ser;
	_Packet->SerializePacket(Ser);
	Send(reinterpret_cast<const char*>(Ser.GetDataPtr()), Ser.GetWriteOffSet(), _IgnoreID);

}

void GameEngineNet::Send(SOCKET _Socket, const char* Data, unsigned int _Size)
{
	send(_Socket, Data, _Size, 0);
}

void GameEngineNet::UpdatePacket()
{
	// �̰� �����忡�� �� �̷����� �����Ҽ� �ִ�.
	RecvPacketLock.lock();

	if (0 >= RecvPacket.size())
	{
		RecvPacketLock.unlock();
		return;
	}

	ProcessPackets = RecvPacket;
	RecvPacket.clear();
	RecvPacketLock.unlock();

	for (std::shared_ptr<GameEnginePacket> Packet : ProcessPackets)
	{
		Dispatcher.ProcessPacket(Packet);
	}

	ProcessPackets.clear();
};
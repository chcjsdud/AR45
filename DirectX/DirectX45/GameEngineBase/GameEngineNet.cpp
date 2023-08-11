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
	int PacketType = -1;
	int PacketSize = -1;

	while (true == _Net->IsNet())
	{
		// 상대가 보내온 패킷의 양.
		int Result = recv(_Socket, Data, sizeof(Data), 0);

		// 접속 끊김
		if (-1 == Result)
		{
			return;
		}

		// 접속 끊김
		if (SOCKET_ERROR == _Socket || INVALID_SOCKET == _Socket)
		{
			return;
		}

		// TCP 에서 문제가 될수 있는부분.
		// TCP가 12바이트를 쏜다면
		// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
		// 7바이트

		// 우리의 프로토콜은 
		// 무조건 적으로
		// 맨앞 4바이트 패킷의 타입
		// 그 뒤 4바이트 사이즈 
		Serializer.Write(Data, Result);

		if (8 > Serializer.GetWriteOffSet())
		{
			continue;
		}

		// 8바이트 이상 받았고
		// 아직 패킷타입이 뭔지 알아내지 못했다면
		if (-1 == PacketType)
		{
			// 패킷타입 알아낸다.
			{
				unsigned char* TypePivotPtr = &Serializer.GetDataPtr()[0];
				int* ConvertPtr = reinterpret_cast<int*>(TypePivotPtr);
				PacketType = *ConvertPtr;
			}

			// 사이즈 알아내고
			{
				unsigned char* SizePivotPtr = &Serializer.GetDataPtr()[4];
				int* ConvertPtr = reinterpret_cast<int*>(SizePivotPtr);
				PacketSize = *ConvertPtr;
			}
		}

		// 패킷사이즈로도 검증할게 최소 최대 패킷이라던가
		if (-1 == PacketSize)
		{
			return;
		}

		// 8바이트 이상 받았지만
		// 그걸 통해서 알아낸 패킷의 크기보다는 덜았어. 
		if (PacketSize > Serializer.GetWriteOffSet())
		{
			continue;
		}

		while (true)
		{
			// ConnectIDPacket
			std::shared_ptr<GameEnginePacket> Packet = _Net->Dispatcher.ConvertPacket(PacketType, Serializer);

			_Net->Dispatcher.ProcessPacket(Packet);

			// 패킷처리를 여기서 하지 않습니다.


			// 그런데

		}
	}
}



void GameEngineNet::SendPacket(std::shared_ptr<GameEnginePacket> _Packet)
{
	GameEngineSerializer Ser;
	_Packet->SerializePacket(Ser);
	Send(reinterpret_cast<const char*>(Ser.GetDataPtr()), Ser.GetWriteOffSet());

}

void GameEngineNet::Send(SOCKET _Socket, const char* Data, unsigned int _Size)
{
	send(_Socket, Data, _Size, 0);
}
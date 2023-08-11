#pragma once
#include "GameEngineDispatcher.h"

// ���� :
// �̳༮�� ������ Ŭ�� ���ÿ� ����ϴ� Ŭ����
class GameEngineNet
{
public:
	// constrcuter destructer
	GameEngineNet();
	~GameEngineNet();

	// delete Function
	GameEngineNet(const GameEngineNet& _Other) = delete;
	GameEngineNet(GameEngineNet&& _Other) noexcept = delete;
	GameEngineNet& operator=(const GameEngineNet& _Other) = delete;
	GameEngineNet& operator=(GameEngineNet&& _Other) noexcept = delete;

	static void Send(SOCKET _Socket, const char* Data, unsigned int _Size);

	virtual void Send(const char* Data, unsigned int _Size) = 0;
	void SendPacket(std::shared_ptr<class GameEnginePacket> _Packet);

	inline bool IsNet() 
	{
		return IsNetValue;
	}

	GameEngineDispatcher Dispatcher;

protected:
	static void RecvThreadFunction(SOCKET _Socket, GameEngineNet* _Net);

private:
	std::atomic<bool> IsNetValue = true;

	std::mutex RecvPacketLock;
	std::list<std::shared_ptr<GameEnginePacket>> RecvPacket;


};


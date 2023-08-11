#pragma once

// �������忡���� ������
// ���� ���� ���͵� ��������� ���ٸ� �ᱹ ������Ʈ�ϻ��̴�.
// ���͵��� 

enum class NetControllType
{
	None,
	UserControll,
	ServerControll,
};

// ���� :
class GameEngineNetObject
{
public:
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

	void InitServerObject();

	void InitClientObject(int _ObjectID);

	void SetControll(NetControllType _ControllType)
	{
		ControllType = _ControllType;
	}

	NetControllType  GetControllType()
	{
		return ControllType;
	}

	int GetNetObjectID()
	{
		return ObjectID;
	}


protected:

private:
	static std::atomic<int> AtomicObjectID;
	static std::mutex ObjectLock;
	static std::map<int, GameEngineNetObject*> AllNetObjects;

	NetControllType ControllType = NetControllType::None;
	int ObjectID = -1;
};


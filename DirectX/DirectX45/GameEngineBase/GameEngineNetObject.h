#pragma once

// 서버입장에서는 유저든
// 내가 가진 몬스터든 결론적으로 본다면 결국 오브젝트일뿐이다.
// 몬스터들은 

enum class NetControllType
{
	None,
	UserControll,
	ServerControll,
};

// 설명 :
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


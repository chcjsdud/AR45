#pragma once

// 설명 : 오브젝트 구조의 가장 기본이 되어주는 클래스.
class GameEngineObject
{
public:
	// constrcuter destructer
	GameEngineObject();
	virtual ~GameEngineObject();

	// delete Function
	GameEngineObject(const GameEngineObject& _Other) = delete;
	GameEngineObject(GameEngineObject&& _Other) noexcept = delete;
	GameEngineObject& operator=(const GameEngineObject& _Other) = delete;
	GameEngineObject& operator=(GameEngineObject&& _Other) noexcept = delete;

	bool IsUpdate() 
	{
		//         조건          ?              true 일때                                      :         false 일때
		// 부모가 있다면
		// ((true == ObjectUpdate && false == IsDeath()) && true == Parent->IsUpdate())
		// 내가 켜져있어야하고 true == ObjectUpdate
		// 내가 죽지도 않았어야 한다. false == IsDeath()
		// 부모도 켜져있어야 한다 true == Parent->IsUpdate()

		return nullptr != Parent ? ((true == ObjectUpdate && false == IsDeath()) && true == Parent->IsUpdate()) : (ObjectUpdate && false == IsDeath());

		// return nullptr != Parent ? 1000 : 200;
	}

	bool IsDeath()
	{
		return nullptr != Parent ? (true == ObjectDeath || Parent->IsDeath()) : (true == ObjectDeath);
	}

	void Death() 
	{
		ObjectDeath = true;
	}

	void On() 
	{
		ObjectUpdate = true;
	}
	void Off() 
	{
		ObjectUpdate = false;
	}

	void OnOffSwtich()
	{
		ObjectUpdate = !ObjectUpdate;
	}


	void SetParent(GameEngineObject* _Parent)
	{
		Parent = _Parent;
	}

protected:

private:
	GameEngineObject* Parent = nullptr;

	bool ObjectDeath = false;
	bool ObjectUpdate = true;

};


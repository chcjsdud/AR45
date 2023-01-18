#pragma once

// ���� : ������Ʈ ������ ���� �⺻�� �Ǿ��ִ� Ŭ����.
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
		//         ����          ?              true �϶�                                      :         false �϶�
		// �θ� �ִٸ�
		// ((true == ObjectUpdate && false == IsDeath()) && true == Parent->IsUpdate())
		// ���� �����־���ϰ� true == ObjectUpdate
		// ���� ������ �ʾҾ�� �Ѵ�. false == IsDeath()
		// �θ� �����־�� �Ѵ� true == Parent->IsUpdate()

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


#pragma once


// 설명 :
class Monster
{
private:
	// 오브젝트에서 분리되어 있고 데이터영역에 만들어진다.
	static int AllMonsterCount;

public:
	static int /*__stdcall*/ GetAllMonsterCount()
	{
		// this가 존재할수 없습니다.
		// this;

		return AllMonsterCount;
	}

public:
	// constrcuter destructer
	Monster();
	~Monster();

	// delete Function
	Monster(const Monster& _Other) = delete;
	Monster(Monster&& _Other) noexcept = delete;
	Monster& operator=(const Monster& _Other) = delete;
	Monster& operator=(Monster&& _Other) noexcept = delete;

	void __thiscall Func() {

	}

protected:

private:
	int Hp;

};


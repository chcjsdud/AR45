#pragma once
#include <ConsoleGameObject.h>

// ���� :
class Part : public ConsoleGameObject
{
public:
	// constrcuter destructer
	Part();
	Part(wchar_t _Renderchar);
	~Part();

	// delete Function
	Part(const Part& _Other) = delete;
	Part(Part&& _Other) noexcept = delete;
	Part& operator=(const Part& _Other) = delete;
	Part& operator=(Part&& _Other) noexcept = delete;

	virtual void Update();

	void SetPrev(Part* _Prev) 
	{
		Prev = _Prev;
		_Prev->Next = this;
	}

	Part* GetPrev()
	{
		return Prev;
	}

	void RecursionPrevUpdate()
	{
		if (nullptr == Prev)
		{
			return;
		}

		Prev->Update();
		Prev->RecursionPrevUpdate();
	}


	void RecursionPrevRender()
	{
		if (nullptr == Prev)
		{
			return;
		}

		Prev->Render();
		Prev->RecursionPrevRender();
	}


	// ����Լ��� ����غ��ڽ��ϴ�.
	Part* GetRecursionLastPrev()
	{
		if (nullptr == Prev)
		{
			return this;
		}

		return Prev->GetRecursionLastPrev();
	}

	Part* GetNext()
	{
		return Next;
	}

protected:
	Part* Next = nullptr;
	Part* Prev = nullptr;

private:

};


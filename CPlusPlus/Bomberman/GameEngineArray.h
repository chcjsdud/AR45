#pragma once
#include "GameEngineDebug.h"

// typedef int DataType;

// ���� :
template<typename DataType>
class GameEngineArray
{
public:
	GameEngineArray() 
		: Count(0)
		, DataPtr(nullptr)
	{

	}

	// constrcuter destructer
	GameEngineArray(size_t _Count)
		: Count(_Count)
		, DataPtr(nullptr)
	{
		ReSize(Count);
	}

	~GameEngineArray()
	{
		if (nullptr != DataPtr)
		{
			delete[] DataPtr;
			DataPtr = nullptr;
		}
	}


	// delete Function
	GameEngineArray(const GameEngineArray& _Other) = delete;
	GameEngineArray(GameEngineArray&& _Other) noexcept = delete;
	GameEngineArray& operator=(const GameEngineArray& _Other) = delete;
	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;

	size_t GetCount() 
	{
		return Count;
	}

	DataType& operator[](size_t _Index) 
	{
		if (Count <= _Index)
		{
			MessageBoxAssert("�迭�� �ε����� �Ѱ���ϴ�");
		}

		return DataPtr[_Index];
	}

	void ReSize(size_t _Count)
	{
		if (0 == _Count)
		{
			MessageBoxAssert("�迭�� ũ�Ⱑ 0�ϼ� �����ϴ�.");
		}

		Count = _Count;

		DataPtr = new DataType[Count];
	}


protected:

private:
	// �迭�� ũ��
	size_t Count = 0;
	DataType* DataPtr = nullptr;
};


// Vector.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <GameEngineDebug.h>

// new와 delete는 c++의 기본연산중에서도 가장 느린 연산입니다.
// 되도록이면 많이 안되게하려고 프로그래머들이 노력한다.

// GameArray 내부에 자료와 배열의 크기는 상관이 있나요.
// Skill을 10개 만든다면

typedef int DataType;

class GameEngineVector 
{
public:
	class iterator 
	{
	public:
		GameEngineVector* ParentPtr;
		int index;

		iterator& operator++() 
		{
			++index;
			return *this;
		}

		DataType& operator*() const noexcept
		{
			return ParentPtr->DataPtr[index];
		}
	};

public:
	GameEngineVector()
	{

	}

	// constrcuter destructer
	GameEngineVector(size_t _Count)
		: MemorySize(_Count)
		, DataSize(_Count)
		, DataPtr(nullptr)
	{
		// 10개짜리를 만들어달라고 한거니까.
		// 할당해서 만들어내야 하니까.
		resize(_Count);
	}

	~GameEngineVector()
	{
		if (nullptr != DataPtr)
		{
			delete[] DataPtr;
			DataPtr = nullptr;
		}
	}


	// delete Function
	GameEngineVector(const GameEngineVector& _Other) = delete;
	GameEngineVector(GameEngineVector&& _Other) noexcept 
	{
		// 최적화때문에 이걸 사용합니다.
	}
	GameEngineVector& operator=(GameEngineVector&& _Other) noexcept = delete;

	// 메모리의 사이즈를 리턴해주는것이 아니라
	// 데이터의 사이즈를 리턴하는 겁니다.
	// 내가 집어넣은 
	size_t size()
	{
		return DataSize;
	}

	size_t capacity()
	{
		return MemorySize;
	}

	iterator begin()
	{
		iterator Return = iterator();
		Return.index = 0;
		Return.ParentPtr = this;
		return Return;
	}

	void erase(const iterator& Iter)
	{
		// Iter.index;
		
		// 0
		// 1 2 2 3 4 5 6 7 8 9

		for (size_t i = Iter.index; i < size(); i++)
		{
			DataPtr[i] = DataPtr[i + 1];
		}

		--DataSize;

		//memcpy_s(&DataPtr[Iter.index], sizeof(DataType) * (size() - Iter.index), &DataPtr[Iter.index + 1], sizeof(DataType) * (size() - Iter.index - 1));

		return;
	}

	void clear()
	{
		DataSize = 0;

	}

	DataType& operator[](size_t _Index)
	{
		if (DataSize <= _Index)
		{
			MessageBoxAssert("배열의 인덱스를 넘겼습니다");
		}

		return DataPtr[_Index];
	}



	void push_back(const DataType& _Data) 
	{
		if (size() + 1 > capacity())
		{
			reserve((size() * 2) + 1);
		}

		DataPtr[DataSize] = _Data;
		++DataSize;
	}

	// 데이터는 넣지 않고 메모리 크기만 확장시키는 함수.
	void reserve(size_t _Count)
	{
		DataType* PrevData = DataPtr;

		DataPtr = new DataType[_Count];

		memset(DataPtr, 0, sizeof(DataType) * _Count);

		MemorySize = _Count;

		if (nullptr == PrevData)
		{
			return;
		}

		for (size_t i = 0; i < DataSize; i++)
		{
			DataPtr[i] = PrevData[i];
		}


		delete PrevData;
		PrevData = nullptr;
	}

	// 데이터는 넣지 않고 메모리 크기만 확장시키는 함수.
	void resize(size_t _Count)
	{
		reserve(_Count);
		DataSize = _Count;
	}


private:
	size_t DataSize = 0;
	size_t MemorySize = 0;
	DataType* DataPtr = nullptr;
};

std::vector<int> Test() 
{
	std::vector<int> ArrReturn;

	ArrReturn.resize(100);

	return ArrReturn;
}

int main()
{
	std::cout << "stdvector" << std::endl;
    {
        // push_back
        // 배열형 시퀸스 자료구조 입니다.
        
        // 크기가 정해져있지 않습니다.
        std::vector<int> IntVector = std::vector<int>();

		IntVector.reserve(10);

        for (size_t i = 0; i < 10; i++)
        {
			// IntVector.pushfront
            IntVector.push_back(i);
            // 내부에 존재하는 배열의 크기입니다.
            std::cout << "Capacity" << IntVector.capacity() << std::endl;
            // 내가 집어넣은 데이터의 크기입니다.
            std::cout << "Size" << IntVector.size() << std::endl;
        }

		//   I
		// 0 2 3 4 5 6 7 8 9
		{
			std::vector<int>::iterator ITER = IntVector.begin();
			ITER.operator++();
			ITER = IntVector.erase(ITER);

			int a = 0;

			//for (size_t i = 0; i < IntVector.size(); i++)
			//{
			//	std::cout << IntVector[i] << std::endl;
			//}
		}

		{
			std::vector<int>::iterator StartIter = IntVector.begin();
			std::vector<int>::iterator EndIter = IntVector.end();
			for (; StartIter != EndIter; ++StartIter)
			{
				std::cout << *StartIter << std::endl;
			}

			int a = 0;
		}

		// IntVector.clear();

		// 내부에 존재하는 배열의 크기입니다.
		std::cout << "Capacity" << IntVector.capacity() << std::endl;
		std::cout << "Size" << IntVector.size() << std::endl;
	}

	return 1;

	//int Arr[10];
	//std::vector<int> ArrVector;
	//ArrVector.reserve(10);

	std::vector<int> ArrVector0 = Test(); // 100 8바이트 복사
	// std::vector<int> ArrVector1; // 100 

	//ArrVector0 = ArrVector1;

	//std::cout << std::endl;
	//std::cout << std::endl;
	//std::cout << std::endl;

	std::cout << "myvector" << std::endl;

    {
        // GameEngineVector
		GameEngineVector IntVector = GameEngineVector();

		// IntVector.resize(10);

		// IntVector.reserve(10);

		for (size_t i = 0; i < 10; i++)
		{
			IntVector.push_back(i);
			// 내부에 존재하는 배열의 크기입니다.
			std::cout << "Capacity" << IntVector.capacity() << std::endl;
			// 내가 집어넣은 데이터의 크기입니다.
			std::cout << "Size" << IntVector.size() << std::endl;
		}

		GameEngineVector::iterator ITER = IntVector.begin();
		ITER.operator++();
		IntVector.erase(ITER);

		// int Arr[100];

		for (size_t i = 0; i < IntVector.size(); i++)
		{
			std::cout << IntVector[i] << std::endl;
		}


		// 내부에 존재하는 배열의 크기입니다.
		std::cout << "Capacity" << IntVector.capacity() << std::endl;
		std::cout << "Size" << IntVector.size() << std::endl;
    }
}

#pragma once
#include <vector>
#include <string>
#include <string_view>

// 데이터를 바이트 단위 char 배열로 만들어주는 녀석
// 직렬화란 클래스를 만들면 c++로 예를 들면 가상함수포인터나 
// 포인터같은 저장해봐야 쓸모없는 데이터들을 다 제외하고 필요한 데이터만
// 바이트 단위로 변경하는것을 의미합니다.


// 설명 :
class GameEngineSerializer
{
public:
	// constrcuter destructer
	GameEngineSerializer();
	GameEngineSerializer(const char* _Data, unsigned int _Size);
	~GameEngineSerializer();

	// delete Function
	//GameEngineSerializer(const GameEngineSerializer& _Other) = delete;
	//GameEngineSerializer(GameEngineSerializer&& _Other) noexcept = delete;
	//GameEngineSerializer& operator=(const GameEngineSerializer& _Other) = delete;
	//GameEngineSerializer& operator=(GameEngineSerializer&& _Other) noexcept = delete;


	unsigned int GetReadOffSet()
	{
		return ReadOffset;
	}

	void ReadOffsetReset()
	{
		ReadOffset = 0;
	}

	unsigned int GetWriteOffSet()
	{
		return WriteOffset;
	}

	void WriteOffsetReset()
	{
		WriteOffset = 0;
	}

	void Reset()
	{
		WriteOffset = 0;
		ReadOffset = 0;
	}

	const std::vector<unsigned char>& GetData() {
		return Data;
	}

	unsigned char* GetDataPtr() {
		return &Data[0];
	}

	const char* GetDataConstPtr() {
		return reinterpret_cast<const char*>(&Data[0]);
	}


	template<typename Type>
	Type GetDataPtrConvert() {
		return reinterpret_cast<Type>(&Data[0]);
	}

	void Write(const void* Data, unsigned int _Size);

	void Read(void* Data, unsigned int _Size);

	void ClearReadData();

	void operator<<(const std::string& _Value);
	void operator<<(const int _Value);
	void operator<<(const unsigned int _Value);
	void operator<<(const uint64_t& _Value);
	void operator<<(const float _Value);

	template<typename T>
	void WriteEnum(const T _Value)
	{
		Write(reinterpret_cast<const void*>(&_Value), static_cast<unsigned int>(sizeof(T)));
	}

	template<typename T>
	void WriteUserData(const T _Value)
	{
		Write(reinterpret_cast<const void*>(&_Value), static_cast<unsigned int>(sizeof(T)));
	}


	void operator>>(std::string& _Value);
	void operator>>(int& _Value);
	void operator>>(unsigned int& _Value);
	void operator>>(uint64_t& _Value);
	void operator>>(float& _Value);

	template<typename T>
	void ReadEnum(T& _Value)
	{
		Read(reinterpret_cast<void*>(&_Value), static_cast<unsigned int>(sizeof(T)));
	}

	template<typename T>
	void ReadUserData(T& _Value)
	{
		Read(reinterpret_cast<void*>(&_Value), static_cast<unsigned int>(sizeof(T)));
	}

protected:

private:
	unsigned int WriteOffset = 0;
	unsigned int ReadOffset = 0;
	std::vector<unsigned char> Data;

};


class GameEngineSerializObject
{
public:
	virtual void Write(GameEngineSerializer& _File) = 0;
	virtual void Read(GameEngineSerializer& _File) = 0;
};

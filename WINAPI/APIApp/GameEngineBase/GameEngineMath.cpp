#include "GameEngineMath.h"

// 변수명은 숫자가 앞에올수가 없습니다.

const float GameEngineMath::PIE = 3.141592653589793238462643383279502884197169399375105820974944f;
const float GameEngineMath::PIE2 = PIE * 2.0f;

const float4 float4::Left	   = {-1.0f, 0.0f, 0.0f, 1.0f};
const float4 float4::Right	   = {1.0f, 0.0f, 0.0f, 1.0f };
const float4 float4::Up		   = { 0.0f, -1.0f, 0.0f, 1.0f };
const float4 float4::Down	   = { 0.0f, 1.0f, 0.0f, 1.0f };

// 2d때는 쓸일이 없을것이다.
const float4 float4::Forward   = { 0.0f, 0.0f, 1.0f, 1.0f };
const float4 float4::Back	   = { 0.0f, 0.0f, -1.0f, 1.0f };

const float4 float4::Zero = { 0.0f, 0.0f, 0.0f, 1.0f };
const float4 float4::Null = { 0.0f, 0.0f, 0.0f, 0.0f };

std::vector<unsigned int> GameEngineMath::GetDigits(unsigned int _Value)
{
	std::vector<unsigned int> ResultValue = std::vector<unsigned int>();

	if (0 == _Value)
	{
		ResultValue.push_back(0);
		return ResultValue;
	}

	int Lenth = GetLenth(_Value);
	ResultValue.resize(Lenth);

	int Value = _Value;
	int HighestDigitValue = 0;
	for (size_t i = 0; i < Lenth; i++)
	{
		HighestDigitValue = Value / pow(10, Lenth - (1 + i));
		ResultValue[i] = HighestDigitValue;
		Value -= HighestDigitValue * pow(10, Lenth - (1 + i));
	}

	return ResultValue;
}

unsigned int GameEngineMath::GetLenth(unsigned int _Value)
{
	int Lenth = 0;
	while (_Value >= pow(10, Lenth))
	{
		++Lenth;
	}
	return Lenth;
}
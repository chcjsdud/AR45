// 33.PlusPlus.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int& FirstPlusePlus(int& _RefPtr) 
{
	_RefPtr += 1;
	return _RefPtr;
}

const int BackPlusePlus(int& _Value)
{
	int Result = _Value;
	_Value += 1;
	return Result;
}

void Function(int& Value) 
{
	Value += 10;
}

int main()
{
	int Arr[10];

	int T = 0;
	FirstPlusePlus(T);

	// const int Value = 10;

	// 정적 배열이라고 했습니다.
	//int Arr[10];

	//{
	//	int Value = 0;

	//	int Result = 0;

	//	// Value += 1;

	//	// 전치 ++
	//	Result = ++Value;
	//	Value = 0;

	//	// 후치 ++
	//	Result = Value++;
	//}

	{
		int Value = 0;
		// (++Value) = 50;

		/*int& 이름없는 =*/ FirstPlusePlus(Value) = 50;

		int a = 0;
	}

	//{
	//	int Value = 0;
	//	// (Value++) = 50;
	//	int Result = BackPlusePlus(Value);
	//	int a = 0;
	//}
 
}

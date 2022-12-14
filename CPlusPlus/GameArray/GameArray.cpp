// GameArray.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "GameEngineArray.h"
int main()
{
	LeckCheck();

	// 형변환이 된겁니다.
	//             int[]
	//int* ArrPtr0;
	//int* ArrPtr1;

	//int ArrPtr1[1];

	//ArrPtr1[1000000];

	// 포인터의 본질은?
	// 8바이트 정수죠?
	// ArrPtr0 = ArrPtr1;

	// Bomb

	GameEngineArray<int*> NewArray(10);

	NewArray.ReSize(20);

	NewArray.ReSize(30);

	NewArray.ReSize(40);

	//for (size_t i = 0; i < NewArray.GetCount(); i++)
	//{
	//	NewArray[i] = nullptr;
	//}

	//// GameEngineArray</*자료형*/> NewArr(10);

	//// GameEngineArray<int>
	//// NewArr[10][10]
	//{
	//	GameEngineArray<GameEngineArray<Bomb*>> NewArr(10);

	//	for (size_t i = 0; i < NewArr.GetCount(); i++)
	//	{
	//		NewArr.ReSize(10);
	//	}

	//	for (size_t y = 0; y < NewArr.GetCount(); y++)
	//	{
	//		NewArr[y].ReSize(10);
	//		for (size_t x = 0; x < NewArr[y].GetCount(); x++)
	//		{
	//			NewArr[y][x] = nullptr;
	//		}
	//	}

	//}
	// NewArr[0][100];


	// NewArray[500] = true;
	
}

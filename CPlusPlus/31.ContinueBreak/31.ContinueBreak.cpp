// 31.ContinueBreak.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

bool IsNumber(int Count, int* Arr, int Number)
{
	bool Result = 0;

	for (int i = 0;  i < Count;  i++)
	{
		if (Arr[i] == Number)
		{
			// 스위치 문에서의 break는 switch문을 바져나가는 용도가 됩니다.
			switch (1)
			{
			default:
				break;
			}

			Result = true;
			// 반복문 내부에 break가 들어있으면
			break; // 자신을 감싸고 있는 가장 가까운 반복문을 정지 시킨다.
		}
	}

	return Result;
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		for (int i = 0; i < 10; i++)
		{
			break;
		}


	}

	int Value[10] = {10, 20, 30, 40};

	if (true == IsNumber(4, Value, 30))
	{
		printf_s("30이 들어있습니다. 숫자가 있습니다.\n");
	}
	;

	// continue와 break는 반복문에서 사용하면 
	// break는 다른 의미가 된다.


	for (
		int i = 0; 
		i < 10; 
		i++
		)
	{
		//if (0 != (i % 2))
		//{
			continue;
		//}

		printf_s("%d\n", i);
	}

    // std::cout << "Hello World!\n";
}

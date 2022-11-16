// 14.Switch.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	// case by case 조건을 칠때
	// 이게 이거라면...

	int Value = 0;

	// 메모리영역이 같냐.
	// 메모리를 만들고 파괴하는 
	// 구조가 달라서 저게 안됩니다.

	// '상수'값과 비교해서 같다면.
	// => 변수와는 switch에서 비교할수 없다.
	int CaseValue = 200;
	switch (Value)
	{
	// case CaseValue: <= 에러가 날 것이다.
	case 0:
	{
		int a = 10;
		printf_s("0입니다");
	}
		break;
	case 1:
		printf_s("1입니다");
		break;
	default:
		printf_s("둘다 아닙니다");
		break;
	}

	if (true)
	{

	}
	else if (true)
	{

	}

	Value = 0;

	switch (Value)
	{
	case 0:
		printf_s("0입니다");
		break;
	case 1:
		printf_s("1입니다");
		break;
	default:
		printf_s("둘다 아닙니다");
		break;
	}

	char InputKey = 'A';

	switch (InputKey)
	{
	case 'a':
	case 'A':
		printf_s("공격합니다");
		break;
	case 'f':
	case 'F':
		printf_s("점프합니다");
		break;
	default:
		break;
	}
}

// 16.While.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

bool Check() 
{
	printf_s("조건문\n");
	return true;
}

int main()
{
	// 내부의 조건이 true라면 
	// {} 내부의 코드를 실행해라.
	// 코드를 실행해라.
	// 무한 반복 코드가 된다.
	// 
	//while (Check())
	//{
	//	char Test = '\n';
	//	// \n모아서 한글자로 봅니다.
	//	printf_s("실행중입니다\n");
	//}

	int Count = 10;

	// 
	while (Count)
	{
		printf_s("실행중입니다\n");
		Count -= 1;
	}

	Count = 0;
	while (10, Count)
	{
		printf_s("실행중입니다2\n");
		Count -= 1;
	}
}

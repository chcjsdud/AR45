// 78.Try.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void Test1() noexcept
{
	throw 1;
}

void Test() noexcept
{
	Test1();

	throw 2;
}

class AClass 
{

};

AClass AAA()
{
	AClass NewA = AClass();

	return NewA;
}

int main()
{
	int* Ptr = nullptr;

	// 
	try
	{
		Test();

		if (nullptr == Ptr)
		{
			throw 3;
		}
	}
	catch (int _ex)
	{
		int a = 0;
	}
}

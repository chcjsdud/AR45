// 101_Thread.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>

int Value = 0;

void Test() 
{
	for (size_t i = 0; i < 10000000; i++)
	{
		Value = Value + 1;
	}

}
void Test1()
{
	// 새로운 실행 흐름을 만들수 있다.

	for (size_t i = 0; i < 10000000; i++)
	{
		Value = Value + 1;
	}
}

int main()
{
	std::thread NewThread0 = std::thread(Test);
	std::thread NewThread1 = std::thread(Test1);


	NewThread1.join();
	NewThread0.join();

    std::cout << Value;
}

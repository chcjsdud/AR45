// 101_Thread.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <mutex>
// 락이나 쓰레드나 내부에서 리눅스 윈도우 관계 없이 돌아갈수 있게 만들어졌다.
// 내부에서 대신 리눅스나 윈도우의 쓰레드 함수를 호출해주고 있다는것을 잊으면 안된다.

// 윈도우에서는 크리티컬 섹션이라고 쓰입니다.

#include <map>


// 1. 쓰레드에서 가장 중요한 공유메모리 수정 문제
//    1-0. 공유만 하는건 문제가 안된다. 수정하려고 하면 문제가 생긴다.
//    1-1. 각자 메모리를 가지면 된다.
//    1-2. 락을 건다. 
// 
// 2. 쓰레드를 많이 만든다고 무조건 빨라지는 건 아니다.
//    2-1. 쓰레드가 많아지면 많아질수록 컨텍스트 스위칭도 늘어난다.
//    2-2. CPU 졸라많으면 해결되는거 아니야? 
//    안된다. 전력소비 까지 생각해보면 결국에는 효율이 떨어지게 된다. 암달의 법칙
// 

std::map<int, int> VVV;

// 메모리를 공유하지 않는것이다. 
//int Value0 = 0;
//int Value1 = 0;
//int Value2 = 100;
// 공유되는 메모리당 1개씩 만듭니다.

int Value = 0;
std::mutex ValueLock;

void Test() 
{

	// 최초의 Value는 얼마일것이다?
	// 0


	for (size_t i = 0; i < 10000000; i++)
	{
		// Value는 얼마지?
		
		// Value를 준비한다. 0
		// Value에 +1을 한 메모리를 만든다. 1
		// 3 = 1
		// Value에 Value +1한 메모리를 복사한다.

		// 락을 쓴다는건 컨텍스트 스위칭을 일부러 일으키겠다는 이야기가 된다.
		ValueLock.lock();
		Value = Value + 1;
		ValueLock.unlock();

		// 자료구조의 함수를 사용하는 언제나 위험할수 있다.
		// VVV[10]
		// VVV.operator[](10);
	}

}
void Test1()
{

	for (size_t i = 0; i < 10000000; i++)
	{
		// Value는 얼마지?

		// Value를 준비한다. 0
		// Value에 +1을 한 메모리를 만든다. 1
		// Value에 Value +1한 메모리를 복사한다. 3
		ValueLock.lock();

		Value = Value + 1;
		ValueLock.unlock();

	}

}

int main()
{
	// 디스 어셈블리는 이걸 기계어로 보는것이다.
	// Value를 준비한다. 
	// Value에 +1을 한 메모리를 만든다.
	// Value에 Value +1한 메모리를 복사한다.
	// Value = Value + 1;

	// 쓰레드를 가장 잘 이용하는 법.
	// 필요할때만 쓰레드를 깨우는 이용법이 최고의 이용법입니다.
	std::thread NewThread0 = std::thread(Test);
	std::thread NewThread1 = std::thread(Test1);

	// 리눅스에서는 
	// 내부에서 _beginthreadex를 사용하는 모습을 볼수가 있다.

	NewThread0.join();
	NewThread1.join();


	std::cout << Value;
    // std::cout << Value0 + Value1;
}

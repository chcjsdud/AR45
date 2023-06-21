// 101_Thread.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <atomic> // 운영체제의 함수를 사용하고 있을겁니다.
				  // 인터락 함수라는걸 쓰고 있다. CPU의 특정 메모리를 사용해서 
			      // 특정 메모리의 최소한의 락을 걸어주는 기계어수준의 로직이 들어가있는 메모리 관리 클래스
				  // 어마어마하게 속력이 좋은 락. 8바이트정도

#include <mutex>
// 락이나 쓰레드나 내부에서 리눅스 윈도우 관계 없이 돌아갈수 있게 만들어졌다.
// 내부에서 대신 리눅스나 윈도우의 쓰레드 함수를 호출해주고 있다는것을 잊으면 안된다.

// 윈도우에서는 크리티컬 섹션이라고 쓰입니다.

#include <map>


// 1. 쓰레드에서 가장 중요한 공유메모리 수정 문제
//    // 쓰레드는 스택만 서로 다른걸 사용하지
//    // 코드 데이터 힙은 공유하기 때문에 공유메모리 문제가 생길수밖에 없다.   
// 
//    1-0. 공유만 하는건 문제가 안된다. 수정하려고 하면 문제가 생긴다.
//    1-1. 각자 메모리를 가지면 된다.
//	  1-2. 아토믹을 사용한다. 
//    1-3. 락을 건다. 
// 
// 2. 쓰레드를 많이 만든다고 무조건 빨라지는 건 아니다.
//    2-1. 쓰레드가 많아지면 많아질수록 컨텍스트 스위칭도 늘어난다.
//    2-2. CPU 졸라많으면 해결되는거 아니야? 
//    안된다. 전력소비 까지 생각해보면 결국에는 효율이 떨어지게 된다. 암달의 법칙
// 
// 3. 대부분의 일반적인 연산에서
//    누가 먼저 되야해. <= 이런게 있으면 쓰레드를 쓸 이유가 없다.



std::map<int, int> VVV;

// 메모리를 공유하지 않는것이다. 
//int Value0 = 0;
//int Value1 = 0;
//int Value2 = 100;
// 공유되는 메모리당 1개씩 만듭니다.

int Value = 0;
// 락도 걸지 않으면 걸지 않을수록 좋다.
std::mutex ValueLock;

std::atomic<int> AtomicValue = 0;

int Value0 = 0;
int Value1 = 0;

std::atomic_bool Thread1 = false;
std::atomic_bool Thread2 = false;

void Test() 
{

	// 최초의 Value는 얼마일것이다?
	// 0


	// 0.01
	// 0.10
	// ValueLock.lock();
	for (size_t i = 0; i < 100000000; i++)
	{
		// Value는 얼마지?
		
		// Value를 준비한다. 0
		// Value에 +1을 한 메모리를 만든다. 1
		// 3 = 1
		// Value에 Value +1한 메모리를 복사한다.

		// 락을 쓴다는건 컨텍스트 스위칭을 일부러 일으키겠다는 이야기가 된다.
		// Value0 = Value0 + 1;
		// AtomicValue = AtomicValue + 1;
		// 
		++AtomicValue;
		// 열심히 텍스처 로딩

		// 자료구조의 함수를 사용하는 언제나 위험할수 있다.
		// VVV[10]
		// VVV.operator[](10);
	}
	// ValueLock.unlock();

	Thread1 = true;

	// 쓰레드의 끝
}


void Test1()
{


		// ValueLock.lock();
	for (size_t i = 0; i < 100000000; i++)
	{
		// Value는 얼마지?

		// Value를 준비한다. 0
		// Value에 +1을 한 메모리를 만든다. 1
		// Value에 Value +1한 메모리를 복사한다. 3

		// Value1 = Value1 + 1;

		// AtomicValue = AtomicValue + 1;
		// 그나마 대안이 될수 있다.
		++AtomicValue;

	}
		// ValueLock.unlock();

	Thread2 = true;
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
	// 일반적인 함수의 실행은 이 함수가 끝나기 전까지는 Test
	// 동기함수

	// Test();

	// Test가 끝날때까지 기다린다.
	// 그런데 기다리면 안된다.
	// NewThread0.join();
	
	// 이런걸 동기 함수라고 한다.
	// _getch();


	std::thread NewThread1 = std::thread(Test1);


	// 리눅스에서는 
	// 내부에서 _beginthreadex를 사용하는 모습을 볼수가 있다.



	// std::cout << Value;

	while (true)
	{
		// 게임의 프레임
		// std::cout << Value0 + Value1;

		std::cout << "게임은 계속 되고 있다 프레임" << std::endl;
		
		// 이게 쓰레드를 사용하는 가장 이상적인 기본형
		// 텍스처 로딩 끝났나?
		if (true == Thread1 && true == Thread2)
		{
			// LevelChange()
			// std::cout << Value0 + Value1 << std::endl;

			std::cout << AtomicValue << std::endl;
		}

	}


	// 연산이 끝날때까지 기다리면 안된다.
	NewThread0.join();
	NewThread1.join();

}

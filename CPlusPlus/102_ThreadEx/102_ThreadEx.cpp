// 102_ThreadEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <Windows.h>
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>
#include <conio.h>
#include <functional>

// 이건 쓰레드마다 생기는 전역 변수가 됩니다.
// 17부터 사용이 가능하다.
thread_local int Value = 0;
int ResultValue = 0;

std::mutex Lock;

HANDLE IOCPHandle = 0;

class Job
{
public:
	std::function<void()> Function;
};


enum class ThreadWork
{
	Job,
	Destroy,
};


std::atomic_int ThreadIndex = 0;

void Test() 
{
	std::wstring Text = L"IOCPWorkThread ";

	Text += std::to_wstring(++ThreadIndex);

	SetThreadDescription(GetCurrentThread(), Text.c_str());

	DWORD Byte;
	ULONG_PTR PtrKey;

	// 서버할때만 의미가 있다.
	LPOVERLAPPED OverLapped = nullptr;


	while (true)
	{
		// 윈도우가 강제로 이 쓰레드를 정지시켜준것.
		// GetQueuedCompletionStatusEx <= 이것은 좀더 상위
		// 30개 쓰레드를 만들었다고 칠께요. 1000 텍스처 로딩
		// 그런데. 

		// 윈도우는 iocp를 지원해주고.
		// 윈도우는 RIO라는 것까지 지원하고 
		
		// 리눅스는 epoll을 지원합니다.

		GetQueuedCompletionStatus(IOCPHandle, &Byte, &PtrKey, &OverLapped, INFINITE);

		ThreadWork WorkType = static_cast<ThreadWork>(Byte);

		if (WorkType == ThreadWork::Destroy)
		{
			break;
		}

		if (WorkType == ThreadWork::Job)
		{
			 Job* JobPtr = reinterpret_cast<Job*>(PtrKey);

			 if (nullptr != JobPtr->Function)
			 {
				 JobPtr->Function();
			 }

			 delete JobPtr;
		}

		// 일을 처리하는 로직을 만들겁니다.
		// 일처리끝.

		// 여기로 내려올때가 있어야 합니다.
		// 우리가 쓰레드에게 
		int a = 0;

		std::wcout << Text << " to Work" << std::endl;

		// 특정 쓰레드나 프로세스를 강제로 n초간 Cpu에 요청을 아무것도 안하게 만드는 함수가 

		// 강제 컨텍스트 
		// 단순히 슬립을 하나 걸어놓는것 만으로
		// 비지쓰레드 문제를 해결할수 있다.
		// busy thread
		// Sleep(1);

		// 진짜 일이 있으면 깨어나게 만드는 것이다.
		// 윈도우는 이걸 하기위해서 Iocp라고 하는 쓰레드 핸들링 인터페이스를 지원합니다.
		
		// 일이 없는거야.

		// 멈춘다 => 일이 생길때까지

	}

	//for (size_t i = 0; i < 100000; i++)
	//{
	//	++Value;
	//}

	//// 이게 락을 최소한으로 사용하는 방법중 하나 입니다.
	//Lock.lock();
	//ResultValue += Value;
	//Lock.unlock();
}

void TextureLoading(std::string _Path) 
{
	// aaa.png
	// bbb.png
	// ccc.png
	std::cout << _Path << std::endl;
}

void SoundLoading()
{
	std::cout << "사운드를 로딩합니다" << std::endl;
}

int main()
{
	// CreateIoCompletionPort는 2가지 용도로 사용되는데 윈도우에게 IOCP기능을 이용하겠다고 하고
	// IOCP핸드를 받는 용도가 첫번째.
	// 그 개수만큼의 쓰레드 관리를 하겠다고 하는것.
	// 2번째 용도는 특정 통신회전을 담당하는 핸들을 관리해달라? => 서버할때
	// 2번째 용도는 우리에게 의미가 없다.

	IOCPHandle = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, 30);

	if (nullptr == IOCPHandle)
	{
		int a = 0;
		return 1;
	}


	std::vector<std::thread> AllThread;
	for (size_t i = 0; i < 30; i++)
	{
		AllThread.push_back(std::thread(Test));
	}


	
	while (true)
	{

		int Select = _getch();

		// 날아온 패킷의 크기
		// 아무숫자나 넣어줘도 상관 없다.
		// 4바이트 정수와
		// 8바이트 정수를 쓰레드에게 안전하게 
		// 포인터 => 8바이트 정수니까.

		// 서버쪽과 파일입출력 쪽에서 사용된다.
		// 파일을 n바이트까지 읽었습니다.


		//for (size_t i = 0; i < 10; i++)
		//{
			Job* NewJob = new Job();

			switch (Select)
			{
			case 'a':
			case 'A':
			{
				std::string Path = "aaaaaaaaaaaaaaaaaaaaaaa";
				NewJob->Function = std::bind(TextureLoading, Path);
				break;
			}
			case 's':
			case 'S':
				NewJob->Function = SoundLoading;
				break;
			default:
				break;
			}


			PostQueuedCompletionStatus(IOCPHandle, static_cast<DWORD>(ThreadWork::Job), reinterpret_cast<unsigned __int64>(NewJob), nullptr);

			//if (FALSE == PostQueuedCompletionStatus(IOCPHandle, static_cast<DWORD>(ThreadWork::Job), reinterpret_cast<unsigned __int64>(NewJob), nullptr))
			//{
			//	int a = 0;
			//}
		//}

	}

	// 쓰레드를 만드는것 자체가 비용이 크기 때문에
	// 필요할때마다 만드는 방법보다는
	// 미리 많이 만들어 놓고
	// 필요할때 깨우는 방법을 선호합니다.
	// 쓰레드 풀이라고 합니다.

	// std::cout << ResultValue << std::endl;

	for (size_t i = 0; i < AllThread.size(); i++)
	{
		AllThread[i].join();
	}
}

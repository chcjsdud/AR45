// 83.MainParameter.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 메인파라미터는 인자를 받을수 있습니다.

// 내 프로그램 경로는 무조건 1개는 들어옵니다.

int main(int Count, const char** _Arg)
{
    // const char* Text = _Arg[0];

	// 내가 실행한 위치
	std::cout << "main para count" << Count << std::endl;

	for (size_t i = 0; i < Count; i++)
	{
		std::cout << _Arg[i] << std::endl;

		std::string Str = _Arg[i];

		if (Str == "cheatmode")
		{
			std::cout << "게임을 치트모드로 켭니다" << std::endl;
		}
	}
}

// 76RangeFor.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <list>
#include <vector>

int main()
{
	{
		std::vector<int> Vec;

		for (size_t i = 0; i < 10; i++)
		{
			Vec.push_back(10);
		}

		for (int& Value : Vec)
		{
			// range for에서는 절대로 삭제연산을 하면 안된다.
			// 오로지 전체 원소를 순회하기 위한 문법입니다.
			std::cout << Value << std::endl;
		}
	}

	{
		std::list<int> Vec;

		for (size_t i = 0; i < 10; i++)
		{
			Vec.push_back(10);
		}

		for (int& Value : Vec)
		{
			// Vec.erase(); <= 이런걸 하면 안된다.
			// range for에서는 절대로 삭제연산을 하면 안된다.
			// 오로지 전체 원소를 순회하기 위한 문법입니다.
			std::cout << Value << std::endl;
		}
	}

    std::cout << "Hello World!\n";
}

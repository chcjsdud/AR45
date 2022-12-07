// 54.FunctionDelete.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Test 
{
public:
	Test() 
	{

	}

	~Test()
	{

	}

	// 아래쪽에 있는애들이 내가 인지 하지 안않았을때 
	// 실행되는걸 정말 싫어 합닏
		// 옛날에는 이렇게 막았습니다.
	Test(const Test& _Other) = delete;
	Test(Test&& _Other) noexcept = delete;
	Test& operator=(Test&& _Other) = delete;
	Test& operator=(const Test& _Other) = delete;

private:

};

int main()
{
	Test NewTest0;
	Test NewTest1 = NewTest0;
}

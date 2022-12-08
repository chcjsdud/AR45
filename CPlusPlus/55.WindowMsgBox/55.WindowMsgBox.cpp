// 55.WindowMsgBox.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>

// 이 헤더는 리눅스에서는 없다.
#include <Windows.h>
#include <assert.h>

// 윈도우라는 엔진이 우리에게 제공해주는 함수들을 사용할수 있는것.

// #define MessageBoxAssert MessageBoxA(nullptr, "뭐시기 때문에 터졌습니다", "Error", MB_OK);	assert(false);

#define MessageBoxAssert(MsgText) MessageBoxA(nullptr, MsgText, "Error", MB_OK);	assert(false);

int main()
{
	// MessageBoxA(nullptr, ("두번 초기화했습니다"), "Error", MB_OK);	assert(false);

	// MessageBoxAssert("두번 초기화했습니다");



	while (true)
	{

	}
}

#include "Boom.h"
#include <conio.h>
#include "ConsoleGameScreen.h"
#include "player.h"
#include <Windows.h>
Boom::Boom()
{
	SetRenderChar(L'◎');
}

Boom::~Boom()
{

}

void Boom::Update()
{
	if (0 > --Time)
	{
		return;
	}

	//   ★
	//   ★
	//★★◎★★
	//   ★
	//   ★

	// 1. 쾅쾅쾅쾅을 만들어 오세요.
	// 1-1. 왼쪽 오른쪽 위 아래에 1개만이라도 보이게 해라.
	// 1-2. 그냥 범위크기 전체로 보이게 만들어라.
	// 1-3. 시간차로 범위가 보이게 만들어라.
	// 
	// 십자가 표시로 먼저 나오게 하세요.


	// 2. 쾅쾅쾅쾅범위에 다른 폭탄이 있으면 개도 쾅쾅쾅쾅.


	ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());
}



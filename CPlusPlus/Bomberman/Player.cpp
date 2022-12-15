#include "Player.h"
#include <conio.h>
#include "ConsoleGameScreen.h"
#include "GameEngineDebug.h"
#include "Boom.h"
#include "Wall.h"

Player::Player()
	: ArrBoomObject(100)
{
	// 대입
	// ArrBoomObject = GameEngineArray<Boom>(100);
	SetRenderChar(L'＠');
}

Player::~Player()
	// ArrBoomObject()
{
	// 클래스의 소멸자가 알아서 호출된다.
}

bool Player::Update()
{
	if (0 == ArrBoomObject.GetCount())
	{
		MessageBoxAssert("폭탄이 만들어지지 않았습니다.");
		return false;
	}

	for (size_t i = 0; i < BoomUseCount; i++)
	{
		ArrBoomObject[i].Update();
	}

	if (0 == _kbhit())
	{
		ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());

		return true;
	}

	// 프로그램 입력이 올때까지 멈추죠?
	int Input = _getch();

	int4 NextPos = GetPos();

	switch (Input)
	{

	case 'a':
	case 'A':
	{
		NextPos += {-1, 0};
		break;
	case 'd':
	case 'D':
	{
		NextPos += {1, 0 };
	}
	break;
	case 's':
	case 'S':
	{
		NextPos += { 0, 1 };
	}
	break;
	case 'w':
	case 'W':
	{
		NextPos += { 0, -1 };
	}
	break;
	case 'f':
	case 'F':
	{
		Boom& NewBoomObject = ArrBoomObject[BoomUseCount];
		NewBoomObject.SetPos(GetPos());
		++BoomUseCount;

	}
	break;
	case 'q':
	case 'Q':
		return false;
	default:
		break;
	}
	}

	bool IsMove = true;

	// 플레이어가 화면 바깥으로 나갔다면 이동하지 못하게 한다.
	// 화면 바깥으로 나갔다면
	if (true == ConsoleGameScreen::GetMainScreen()->IsOver(NextPos))
	{
		// 이동불가
		IsMove = false;
	}

	// 폭탄들을 전부다 검사해서 만약 나의 이동위치에 폭탄이 있다면 이동하지 않는다.
	// 공간적 최적화와
	// 연산적 최적화가 있습니다.
	// 근래의 트랜드는
	// 연산적 최적화를 하는겁니다.

	if (nullptr != Boom::GetBoom(NextPos))
	{
		IsMove = false;
	}
	if (true == Wall::GetIsWall(NextPos))
	{
		IsMove = false;
	}

	
	if (true == IsMove)
	{
		SetPos(NextPos);
	}

	ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());


	return true;
}
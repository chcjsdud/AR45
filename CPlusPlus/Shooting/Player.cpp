#include "Player.h"
#include <conio.h>

void Player::Update()
{
	// 숙제 1. 화면 바깥으로 못나가게 만드세요.
	// 숙제 2. 잔상 지우세요.

	// 이건 안해도 됩니다.
	// 이것도 다했다.
	// 숙제 3. 몬스터를 1마리 만드세요.
	// 숙제 4. 총알을 1개 만드세요
	// 숙제 5. 총알이 몬스터를 만나면 둘다 사라지게 하세요.

	// 누르고 나서 뭘 눌렀는지 알려주는 함수.
	// 진짜 뭔가를 눌
	
	if (0 == _kbhit())
	{
		return;
	}

	// 프로그램 입력이 올때까지 멈추죠?
	int Input = _getch();

	Int4 NextPos = GetPos();

	switch (Input)
	{
	case 'a':
	case 'A':
		NextPos += {-1, 0};
		break;
	case 'd':
	case 'D':
		NextPos += {1, 0 };
		break;
	case 's':
	case 'S':
		NextPos += { 0, 1 };
		break;
	case 'w':
	case 'W':
		NextPos += { 0, -1 };
		break;
	default:
		break;
	}

	// [][][][][]
	// [][][][][]
	// [][][][][]
	// [][][][][]
	// [][][][][]

	// 나가지 않았다면
	if (
		(NextPos.X >= 0) &&
		(NextPos.X < 5) &&
		(NextPos.Y >= 0) &&
		(NextPos.Y < 5) 
		)
	{
		SetPos(NextPos);
	}

}
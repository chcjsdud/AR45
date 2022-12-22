#include "Head.h"
#include <ConsoleGameScreen.h>
#include <GameEngineInput.h>
#include "Body.h"

#include <conio.h>

// 1. 새로운 몸통이 빈공간에만 생기게 만들어라.
// 2. 머리가 몸통에 닿으면 게임 오버가 되게 만들어라.
// 3. q를 눌러서 종료했을때 릭도 전부다 없애오세요/

Head::Head()
	: Part(L'◆')
{
}

Head::~Head() 
{
}

void Head::Update() 
{
	if (true == GameEngineInput::GetIsInput())
	{
		int a = 0;
	}

	if (true == GameEngineInput::GetIsInput())
	{
		int Input = GameEngineInput::GetKey();
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
		break;
		case 'q':
		case 'Q':
			return;
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

		// 최초 1, 1
		// 최초 2, 1

		if (true == IsMove)
		{
			// 내가 이동했으니까 모든애들이 따라와야해.
			Part* LastPart = GetLastPart();
			int4 PrevPos = LastPart->GetPos();

			LastPart->RecursionFrontMove();

			SetPos(NextPos);


			if (GetPos() == Body::GetCurBody()->GetPos())
			{
				Body::GetCurBody()->SetPos(PrevPos);
				Body::GetCurBody()->SetRenderChar(L'●');
				LastPart->SetBack(Body::GetCurBody());
				Body::CreateBody();
			}
		}
	}



}
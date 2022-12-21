#include "Head.h"
#include <ConsoleGameScreen.h>
#include <GameEngineInput.h>
#include "Body.h"

#include <conio.h>

Head::Head()
	: Part(L'��')
{
}

Head::~Head() 
{
}

void Head::Update() 
{
	if (nullptr != GetPrev())
	{
		RecursionPrevUpdate();
		RecursionPrevRender();
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

		// �÷��̾ ȭ�� �ٱ����� �����ٸ� �̵����� ���ϰ� �Ѵ�.
		// ȭ�� �ٱ����� �����ٸ�
		if (true == ConsoleGameScreen::GetMainScreen()->IsOver(NextPos))
		{
			// �̵��Ұ�
			IsMove = false;
		}

		if (true == IsMove)
		{
			Part* PrevPart = GetRecursionLastPrev();
			int4 CurPos = PrevPart->GetPos();

			SetPos(NextPos);

			if (Body::GetCurBody()->GetPos() == GetPos())
			{
				

				Body::GetCurBody()->SetPos(CurPos);
				PrevPart->SetPrev(Body::GetCurBody());
				Body::CreateBody();
			}
		}
	}



}
#include "Monster.h"
#include "ConsoleGameScreen.h"
#include "Wall.h"

/*static */GameEngineArray<Monster> Monster::AllMonster(10);

size_t Monster::MonsterUpdateCount = 0;

void Monster::AllMonsterInit(wchar_t _BaseChar)
{
	for (size_t i = 0; i < AllMonster.GetCount(); i++)
	{
		AllMonster[i].Off();
		AllMonster[i].SetRenderChar(_BaseChar);
	}
}

Monster* Monster::CreateMonster(int4 _Pos, int4 _Dir)
{
	Monster* ReturnMonster = &AllMonster[MonsterUpdateCount];
	AllMonster[MonsterUpdateCount].SetPos(_Pos);
	AllMonster[MonsterUpdateCount].SetDir(_Dir);
	AllMonster[MonsterUpdateCount++].On();
	return ReturnMonster;
}

void Monster::AllMonsterUpdate()
{
	for (size_t i = 0; i < AllMonster.GetCount(); i++)
	{
		if (false == AllMonster[i].GetIsUpdate())
		{
			continue;
		}

		AllMonster[i].Update();
	}
}

Monster::Monster() 
{
}

Monster::~Monster() 
{
}

void Monster::Init() 
{
	//int4 LeftPos = GetPos() + int4::LEFT;
	//int4 RightPos = GetPos() + int4::RIHGT;
	//int4 UpPos = GetPos() + int4::UP;
	//int4 DownPos = GetPos() + int4::DOWN;

	//// 왼쪽이든 오른쪽이든 한곳이 뚤렸어.
	//if (
	//	ConsoleGameScreen::GetMainScreen()->IsOver(LeftPos) ||
	//	ConsoleGameScreen::GetMainScreen()->IsOver(RightPos)
	//	)
	//{
	//	// 왼쪽이든 오른쪽이든 한곳이 벽이 없어.
	//	if (
	//		false == Wall::GetIsWall(LeftPos) ||
	//		false == Wall::GetIsWall(RightPos)
	//		)
	//	{
	//		Dir = int4::LEFT;
	//		return;
	//	}
	//}

	//if (ConsoleGameScreen::GetMainScreen()->IsOver(UpPos)
	//	&& ConsoleGameScreen::GetMainScreen()->IsOver(DownPos))
	//{
	//	Dir = int4::LEFT;
	//	return;
	//}

}


void Monster::Update()
{
	int4 Pos = GetPos();
	int4 MovePos = Pos + Dir;

	if (ConsoleGameScreen::GetMainScreen()->IsOver(MovePos))
	{
		Dir.X *= -1;
		Dir.Y *= -1;
	}

	SetPos(Pos + Dir);

	Render();
}
#include "StudyGameCore.h"
#include "PlayLevel.h"
#include "TitleLevel.h"

// StudyGameCore StudyGameCore::Core = new StudyGameCore();

// �߰��� ����� �������� �����ָ� ������������ ���� �����Ҵ��ؼ� ����Ѵٴ°�
// �������⿡�� ��??? �׷�������?
StudyGameCore StudyGameCore::Core;

StudyGameCore::StudyGameCore() 
{
}

StudyGameCore::~StudyGameCore() 
{
}

void StudyGameCore::Start()
{
	new int();

	CreateLevel<PlayLevel>("Play");
	CreateLevel<TitleLevel>("Title");
	ChangeLevel("Title");
}

void StudyGameCore::Update()
{
	
}
void StudyGameCore::End() 
{
	
}
#include "PlayLevel.h"
#include "Player.h"

PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::Loading() 
{
	// �������� �͵��� ����� ������ Loading�����Դϴ�.
	CreateActor<Player>();
}

void PlayLevel::Update() 
{

}

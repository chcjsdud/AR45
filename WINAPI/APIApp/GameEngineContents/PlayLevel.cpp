#include "PlayLevel.h"
#include "Player.h"
#include <GameEngineBase/GameEngineDirectory.h>

PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::Loading() 
{
	// �̷� ��θ� ���� ���.
	// "D:\Project\AR45\WINAPI\APIApp\ContentsResources\Iamge\Heros.bmp";

	GameEngineDirectory Dir;


	// �������� �͵��� ����� ������ Loading�����Դϴ�.
	CreateActor<Player>();
}

void PlayLevel::Update() 
{

}

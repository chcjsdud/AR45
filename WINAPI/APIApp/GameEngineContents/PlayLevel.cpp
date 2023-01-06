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
	// 이런 경로를 절대 경로.
	// "D:\Project\AR45\WINAPI\APIApp\ContentsResources\Iamge\Heros.bmp";

	GameEngineDirectory Dir;


	// 만들어야할 것들을 만드는 시점이 Loading시점입니다.
	CreateActor<Player>();
}

void PlayLevel::Update() 
{

}

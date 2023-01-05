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
	// 만들어야할 것들을 만드는 시점이 Loading시점입니다.
	CreateActor<Player>();
}

void PlayLevel::Update() 
{

}

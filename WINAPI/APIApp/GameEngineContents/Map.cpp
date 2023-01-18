#include "Map.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"

Map::Map() 
{
}

Map::~Map() 
{
}


void Map::Start()
{
	{
		GameEngineRender* AnimationRender = CreateRender(BubbleRenderOrder::Map);
		AnimationRender->SetPosition(GameEngineWindow::GetScreenSize().half());
		AnimationRender->SetScale(GameEngineWindow::GetScreenSize());
		AnimationRender->SetImage("Map.Bmp");
		// AnimationRender->ChangeAnimation("Loop");
	}

}
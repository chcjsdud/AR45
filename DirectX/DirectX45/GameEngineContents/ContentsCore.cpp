#include "PrecompileHeader.h"
#include "ContentsCore.h"
#include <GameEngineCore\GameEngineCore.h>
#include "PlayLevel.h"
#include "ServerWindow.h"
#include <GameEngineCore/GameEngineCoreWindow.h>



ContentsCore::ContentsCore() 
{
}

ContentsCore::~ContentsCore() 
{
}


void ContentsCore::GameStart() 
{


	new int();

	GameEngineGUI::GUIWindowCreate<ServerWindow>("ServerWindow");
	ContentsResourcesCreate();
	GameEngineCore::CreateLevel<PlayLevel>();
	GameEngineCore::ChangeLevel("PlayLevel");
}

void ContentsCore::GameEnd() 
{

}
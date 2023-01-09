#include "GameEngineResources.h"
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEngineBase/GameEngineString.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineBase/GameEngineDebug.h>

GameEngineResources GameEngineResources::Inst;

GameEngineResources::GameEngineResources() 
{
}

GameEngineResources::~GameEngineResources() 
{
}

bool GameEngineResources::ImageLoad(const GameEnginePath& _Path)
{
	return ImageLoad(_Path.GetPathToString().c_str(), _Path.GetFileName().c_str());
}

bool GameEngineResources::ImageLoad(const std::string_view& _Path, const std::string_view& _Name)
{
	// D:\\Project\\AR45\\WINAPI\\APIApp\\ContentsResources\\Image\\Heros.BmP

	std::string UpperName = GameEngineString::ToUpper(_Name);

	if (AllImage.end() != AllImage.find(UpperName))
	{
		MsgAssert("이미 로드한 이미지를 또 로드하려고 했습니다." + UpperName);
		return false;
	}

	GameEngineImage* NewImage = new GameEngineImage();
	NewImage->ImageLoad(_Path);
	AllImage.insert(std::make_pair(UpperName, NewImage));
	return true;
}
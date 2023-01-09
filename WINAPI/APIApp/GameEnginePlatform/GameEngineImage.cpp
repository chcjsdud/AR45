#include "GameEngineImage.h"
#include <GameEngineBase/GameEnginePath.h>

GameEngineImage::GameEngineImage() 
{
}

GameEngineImage::~GameEngineImage() 
{
}

bool GameEngineImage::ImageLoad(const GameEnginePath& _Path)
{
	return ImageLoad(_Path.GetPathToString().c_str());
}

bool GameEngineImage::ImageLoad(const std::string_view& _Path) 
{


	return true;
}
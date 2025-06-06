#include "PrecompileHeader.h"
#include "GameEngineDirectory.h"
#include "GameEngineFile.h"
#include "GameEngineDebug.h"
#include "GameEngineString.h"


GameEngineDirectory::GameEngineDirectory() 
{
}

GameEngineDirectory::GameEngineDirectory(std::string_view Path)
	: GameEnginePath(Path)
{

}

GameEngineDirectory::GameEngineDirectory(std::filesystem::path Path)
	: GameEnginePath(Path)
{

}

GameEngineDirectory::~GameEngineDirectory() 
{
}
void GameEngineDirectory::MoveParentToDirectory(const std::string_view& _String)
{
	std::string MovePath = "\\";
	MovePath += _String;

	MoveParentToChildPath(MovePath.c_str());
}

bool GameEngineDirectory::Move(const std::string_view& _String)
{
	Path += "\\";
	Path += _String;
	return IsExists();
}

GameEnginePath GameEngineDirectory::GetPlusFileName(const std::string_view& _String)
{

	std::string PathString = GetFullPath();
	PathString += "\\";
	PathString += _String;

	return GameEnginePath(PathString);
}

bool GameEngineDirectory::MoveParent()
{
	if (true == IsRoot())
	{
		MsgAssert("루트 디렉토리는 부모디렉토리로 이동할수 없습니다.");
		return false;
	}

	MoveParent();

	return true;
}

// .png
// png

std::vector<GameEngineFile> GameEngineDirectory::GetAllFile(std::vector<std::string_view> _Ext)
{
	std::filesystem::directory_iterator DirIter(Path);

	// std::string Ext = _Ext.data();

	std::vector<std::string> UpperExts;
	UpperExts.reserve(_Ext.size());
	for (size_t i = 0; i < _Ext.size(); i++)
	{
		std::string OtherUpperExt = GameEngineString::ToUpper(_Ext[i]);
		UpperExts.push_back(OtherUpperExt);
	}

	std::vector<GameEngineFile> Files;

	for (const std::filesystem::directory_entry& Entry : DirIter)
	{
		if (true == Entry.is_directory())
		{
			GameEngineDirectory ChildDir(Entry.path());

			std::vector<GameEngineFile> ChildFiles = ChildDir.GetAllFile(_Ext);


			for (size_t i = 0; i < ChildFiles.size(); i++)
			{
				Files.push_back(ChildFiles[i]);
			}
			continue;
		}

		std::string Path = Entry.path().string();
		std::string Ext = Entry.path().extension().string();
		std::string UpperExt = GameEngineString::ToUpper(Ext);
		
		bool Check = false;

		if (0 != UpperExts.size())
		{
			for (size_t i = 0; i < UpperExts.size(); i++)
			{
				const std::string& ExtText = UpperExts[i];

				if (ExtText == UpperExt)
				{
					Check = true;
					break;
				}
			}
		} else 
		{
			Check = true;
		}


		if (false == Check)
		{
			continue;
		}

		Files.push_back(GameEngineFile(Entry.path()));
	}

	return Files;
}
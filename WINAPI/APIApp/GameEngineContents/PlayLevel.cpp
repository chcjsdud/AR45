#include "PlayLevel.h"
#include "Player.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineBase/GameEngineTime.h>

PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::Loading() 
{
	GameEngineTime NewTime;

	// �̷� ��θ� ���� ���.
	// "D:\Project\AR45\WINAPI\APIApp\ContentsResources\Iamge\Heros.bmp";

	// std::string Text = "D:\Project\AR45\WINAPI\APIApp\ContentsResources\Iamge\Heros.bmp";

	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");

	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Heros.BMP"));
		Image->Cut({ 2, 12 }, {949,38}, 32, 1);
	}

	//if (true == Path.IsExistsToPlusString("\\Heros.bmp"))
	//{
	//	int a = 0;
	//}

	//bool Result = false;
	//Result = Path.IsExistsToPlusString("\\ContentsResources");
	//Path.MoveParent();
	//Result = Path.IsExistsToPlusString("\\ContentsResources");
	//Path.MoveParent();
	//Result = Path.IsExistsToPlusString("\\ContentsResources");
	//Path.MoveParent();
	//Result = Path.IsExistsToPlusString("\\ContentsResources");
	//Path.MoveParent();


	// �������� �͵��� ����� ������ Loading�����Դϴ�.
	CreateActor<Player>();
}

void PlayLevel::Update() 
{

}

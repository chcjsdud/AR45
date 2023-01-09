#include "PlayLevel.h"
#include "Player.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>

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

	// std::string Text = "D:\Project\AR45\WINAPI\APIApp\ContentsResources\Iamge\Heros.bmp";

	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Heros.BMP"));

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

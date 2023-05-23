#include "PrecompileHeader.h"
#include "ContentsCore.h"
#include <GameEngineCore\GameEngineCore.h>
#include "PlayLevel.h"
#include "TitleLevel.h"
#include <GameEngineCore/GameEngineCoreWindow.h>
#include <GameEngineCore/GameEngineVertexShader.h>
#include <GameEngineCore/GameEnginePixelShader.h>
#include <GameEngineCore/GameEngineRenderingPipeLine.h>


ContentsCore::ContentsCore() 
{
}

ContentsCore::~ContentsCore() 
{
}

void ContentsCore::ContentsResourcesCreate()
{
	// �ؽ�ó �ε常 �� �������� �ϰ� �����ϴ� ������ ���̼���.

	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("ContentsShader");

		std::vector<GameEngineFile> Files = NewDir.GetAllFile({ ".hlsl", ".fx" });

		// ���̴� �ڵ�������
		GameEngineVertexShader::Load(Files[0].GetFullPath(), "MyShader_VS");
		GameEnginePixelShader::Load(Files[0].GetFullPath(), "MyShader_PS");
	}

	{
		std::shared_ptr<GameEngineRenderingPipeLine> Pipe = GameEngineRenderingPipeLine::Create("My2DTexture");

		Pipe->SetVertexBuffer("Rect");
		Pipe->SetIndexBuffer("Rect");
		Pipe->SetVertexShader("MyShader.fx");
		Pipe->SetRasterizer("Engine2DBase");
		Pipe->SetPixelShader("MyShader.fx");
		Pipe->SetBlendState("AlphaBlend");
		Pipe->SetDepthState("EngineDepth");
	}



}

void ContentsCore::GameStart() 
{


	new int();

	GameEngineGUI::GUIWindowCreate<GameEngineCoreWindow>("CoreWindow");


	ContentsResourcesCreate();

	GameEngineCore::CreateLevel<TitleLevel>();
	GameEngineCore::CreateLevel<PlayLevel>();
	GameEngineCore::ChangeLevel("TitleLevel");
}

void ContentsCore::GameEnd() 
{

}
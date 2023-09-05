#include "PrecompileHeader.h"
#include "PlayLevel.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineVideo.h>
#include <GameEngineCore/GameEngineCoreWindow.h>
#include <GameEngineCore/GameEngineButton.h>
#include "FadeEffect.h"
#include "Player.h"
#include "ServerWindow.h"
#include <GameEngineCore/EngineGrid.h>

#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineSprite.h>

std::shared_ptr<TestObject> Object1 = nullptr;
std::shared_ptr<GameEngineSpriteRenderer> RenderTest = nullptr;

PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("LevelMoveKey"))
	{
		GameEngineCore::ChangeLevel("TitleLevel");
	}

	if (nullptr != ServerWindow::NetInst)
	{
		ServerWindow::NetInst->UpdatePacket();
	}

}

void PlayLevel::Start()
{
	if (false == GameEngineInput::IsKey("LevelMoveKey"))
	{
		GameEngineInput::CreateKey("LevelMoveKey", 'Y');
	}

	// Col = std::make_shared<JPSCollision>();
	// GetMainCamera()->GetCamTarget()->DepthSettingOff();

	GetMainCamera()->SetProjectionType(CameraType::Perspective);
	GetMainCamera()->GetTransform()->SetLocalPosition({0, 0, -500.0f});


	// GameEngineRenderTarget::Create();

	GameEngineCoreWindow::AddDebugRenderTarget(0, "MainCameraForwardTarget", GetMainCamera()->GetCamForwardTarget());
	GameEngineCoreWindow::AddDebugRenderTarget(0, "AllRenderTarget", GetMainCamera()->GetCamAllRenderTarget());


	{
		std::shared_ptr<GameEngineLight> Light = CreateActor<GameEngineLight>();
	}


	std::shared_ptr<EngineGrid> Grid = CreateActor<EngineGrid>();

	{
		std::shared_ptr<Player> NewPlayer = CreateActor<Player>();
		NewPlayer->SetUserControllType();
	}

}
void PlayLevel::LevelChangeStart()
{
	GameEngineLevel::LevelChangeStart();
	int a = 0;
}

void PlayLevel::LevelChangeEnd() 
{
	GameEngineLevel::LevelChangeEnd();
	int a = 0;
}
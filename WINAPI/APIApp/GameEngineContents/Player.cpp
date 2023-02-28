#include "Player.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>

#include "ContentsEnums.h"
#include "ContentsValue.h"

#include "Map.h"
#include "STLevel.h"

Player* Player::MainPlayer;

static bool IsStop = false; 

Player::Player() 
{
}

Player::~Player() 
{
}

void Player::Start()
{
	ContentsValue::CameraScale;

	// ContentsValue::CameraScale = { 1000, 2000 };

	MainPlayer = this;

	TestNumber.SetOwner(this);
	TestNumber.SetImage("Number.BMp", {40, 40}, 10, RGB(255, 255, 255), "Hover.bmp");
	TestNumber.SetValue(Value);
	TestNumber.SetAlign(Align::Right);

	//STLevel* Level = GetOwner<STLevel>();
	//Level->GetCameraScale();


	if (false == GameEngineInput::IsKey("LeftMove"))
	{
		GameEngineInput::CreateKey("LeftMove", 'A');
		GameEngineInput::CreateKey("RightMove", 'D');
		GameEngineInput::CreateKey("DownMove", 'S');
		GameEngineInput::CreateKey("UpMove", 'W');

		GameEngineInput::CreateKey("FreeMoveSwitch", '1');
		GameEngineInput::CreateKey("StageClear", '2');
	}

	{
		AnimationRender = CreateRender(BubbleRenderOrder::Player);
		AnimationRender->SetScale({ 200, 200 });
		AnimationRender->SetAlpha(100);

		AnimationRender->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "Right_Player.bmp",.FilterName = "Right_Roll_Back.bmp",.Start = 0, .End = 2, .InterTime = 0.3f});
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "Right_Player.bmp",.FilterName = "Right_Roll_Back.bmp",.Start = 3, .End = 7 });

		AnimationRender->CreateAnimation({ .AnimationName = "Left_Idle", .ImageName = "Left_Player.bmp", .FilterName = "Left_Roll_Back.bmp", .Start = 0, .End = 2, .InterTime = 0.3f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Move", .ImageName = "Left_Player.bmp", .FilterName = "Left_Roll_Back.bmp", .Start = 3, .End = 7 });
		AnimationRender->SetAngle(-45);
	}

	//{
	//	GameEngineRender* Render = CreateRender(BubbleRenderOrder::Player);
	//	Render->SetText("かいしかいしかいしかいしかいしかいしかいし");
	//}

	// NumbersRender NewRender;
	// NewRender.SetActor(this);
	// NewRender.SetValue(10000);

	{
		BodyCollision = CreateCollision(BubbleCollisionOrder::Player);
		BodyCollision->SetScale({ 50, 50 });
	}

	ChangeState(PlayerState::IDLE);
}



void Player::Movecalculation(float _DeltaTime)
{
	MoveDir += float4::Down * 200.0f * _DeltaTime;

	if (100.0f <= abs(MoveDir.x))
	{
		if (0 > MoveDir.x)
		{
			MoveDir.x = -100.0f;
		}
		else {
			MoveDir.x = 100.0f;
		}
	}

	if (false == GameEngineInput::IsPress("LeftMove") && false == GameEngineInput::IsPress("RightMove"))
	{
		MoveDir.x *= 0.01f;
	}

	// ColMap.BMP 戚杏 痕呪稽馬檎 
	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("ColMap.BMP");
	if (nullptr == ColImage)
	{
		MsgAssert("中宜遂 己 戚耕走亜 蒸柔艦陥.");
	}


	// 鎧 耕掘税 是帖澗 食奄昔汽/.

	bool Check = true;
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;

	if (RGB(0, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 0, 0)))
	{
		Check = false;
		// MoveDir = float4::Zero;
	}

	if (false == Check)
	{
		while (true)
		{
			MoveDir.y -= 1;

			float4 NextPos = GetPos() + MoveDir * _DeltaTime;

			if (RGB(0, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 0, 0)))
			{
				continue;
			}

			break;
		}
	}

	SetMove(MoveDir * _DeltaTime);
}

void Player::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	MainPlayer = this;
	int a = 0;
}

bool FreeMove = false;

bool Player::FreeMoveState(float _DeltaTime)
{
	if (true == GameEngineInput::IsPress("FreeMoveSwitch"))
	{
		FreeMove = true;
	}

	if (true == FreeMove)
	{
		if (GameEngineInput::IsPress("LeftMove"))
		{
			SetMove(float4::Left * 1000.0f * _DeltaTime);
			GetLevel()->SetCameraMove(float4::Left * 1000.0f * _DeltaTime);
		}
		else if (GameEngineInput::IsPress("RightMove"))
		{
			SetMove(float4::Right * 1000.0f * _DeltaTime);
			GetLevel()->SetCameraMove(float4::Right * 1000.0f * _DeltaTime);
		}
		else if (GameEngineInput::IsPress("UpMove"))
		{
			SetMove(float4::Up * 1000.0f * _DeltaTime);
			GetLevel()->SetCameraMove(float4::Up * 1000.0f * _DeltaTime);
		}
		else if (GameEngineInput::IsPress("DownMove"))
		{
			SetMove(float4::Down * 1000.0f * _DeltaTime);
			GetLevel()->SetCameraMove(float4::Down * 1000.0f * _DeltaTime);
		}
	}

	if (true == FreeMove)
	{
		return true;
	}

	return false;
}

void Player::Update(float _DeltaTime) 
{
	AnimationRender->SetAngleAdd(_DeltaTime * 360.0f);

	TestNumber.SetValue(--Value);

	if (nullptr != BodyCollision)
	{
		std::vector<GameEngineCollision*> Collision;
		if (true == BodyCollision->Collision({ .TargetGroup = static_cast<int>(BubbleCollisionOrder::Monster), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, Collision))
		{
			for (size_t i = 0; i < Collision.size(); i++)
			{
				GameEngineActor* ColActor = Collision[i]->GetActor();
				ColActor->Death();
			}
		}
	}

	if (true == FreeMoveState(_DeltaTime))
	{
		return;
	}

	if (GameEngineInput::IsDown("StageClear"))
	{
		Map::MainMap->StageClearOn();
	}

	UpdateState(_DeltaTime);
	Movecalculation(_DeltaTime);
}

void Player::DirCheck(const std::string_view& _AnimationName)
{
	std::string PrevDirString = DirString;
	AnimationRender->ChangeAnimation(DirString + _AnimationName.data());

	if (GameEngineInput::IsPress("LeftMove"))
	{
		DirString = "Left_";
	}
	else if(GameEngineInput::IsPress("RightMove"))
	{
		DirString = "Right_";
	}

	if (PrevDirString != DirString)
	{
		AnimationRender->ChangeAnimation(DirString + _AnimationName.data());
	}
}

void Player::Render(float _DeltaTime)
{
	HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	float4 ActorPos = GetPos() - GetLevel()->GetCameraPos();;

	Rectangle(DoubleDC, 
		ActorPos.ix() - 5,
		ActorPos.iy() - 5,
		ActorPos.ix() + 5,
		ActorPos.iy() + 5
		);


	float4 Angle = GetLevel()->GetMousePos() - GetPos();
	float Deg = Angle.GetAnagleDeg();

	std::string AngleText = "Angle : ";
	AngleText += std::to_string(Deg);
	GameEngineLevel::DebugTextPush(AngleText);

	std::string MouseText = "MousePosition : ";
	MouseText += GetLevel()->GetMousePos().ToString();

	std::string CameraMouseText = "MousePositionCamera : ";
	CameraMouseText += GetLevel()->GetMousePosToCamera().ToString();

	GameEngineLevel::DebugTextPush(MouseText);
	// GameEngineLevel::DebugTextPush(CameraMouseText);

	//std::string Text = "窒径";
	//SetBkMode(DoubleDC, TRANSPARENT);
	//TextOut(DoubleDC, 0, 0, Text.c_str(), Text.size());

	// 巨獄焔遂.
}
#include "PrecompileHeader.h"
#include "GameEngineLight.h"
#include "GameEngineLevel.h"

// ���̴����� Light.fx�� �̿��ϴ� ��� �̳༮�� ���� ����ϴ� �༮�̴�
// �ڵ����� 

GameEngineLight::GameEngineLight() 
{
}

GameEngineLight::~GameEngineLight() 
{
}


void GameEngineLight::Update(float _DeltaTime)
{
	//LightDataValue.LightPos = GetTransform()->GetWorldPosition();
	//LightDataValue.LightDir = GetTransform()->GetLocalForwardVector();
}

void GameEngineLight::Start()
{
	GetLevel()->PushLight(DynamicThis<GameEngineLight>());
}

void GameEngineLight::LightUpdate(GameEngineCamera* _Camera, float _DeltaTime) 
{
	// GetTransform()->SetCameraMatrix(_Camera->GetView(), _Camera->GetProjection());

	LightDataValue.LightPos = GetTransform()->GetWorldPosition();
	LightDataValue.LightDir = GetTransform()->GetLocalForwardVector();
	LightDataValue.ViewLightPos = LightDataValue.LightPos * _Camera->GetView();
	LightDataValue.ViewLightDir = LightDataValue.LightDir * _Camera->GetView();
	LightDataValue.ViewLightRevDir = -LightDataValue.ViewLightDir;
}
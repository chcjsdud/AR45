#include "PrecompileHeader.h"
#include "GameEngineLight.h"
#include "GameEngineLevel.h"

// ���̴����� Light.fx�� �̿��ϴ� ��� �̳༮�� ���� ����ϴ� �༮�̴�
// �ڵ����� 

GameEngineLight::GameEngineLight() 
{
	LightDataValue.ShadowTargetSizeX = 4096;
	LightDataValue.ShadowTargetSizeY = 4096;
	LightDataValue.LightNear = 0.1f;
	LightDataValue.LightFar = 3000.0f;
	ShadowRange.x = 1024.0f;
	ShadowRange.y = 1024.0f;
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

	
	// ũ�Ⱑ �� �׸��ڰ� ������ ������ �������� �ǹ��ϰ� �˴ϴ�.
	ShadowTarget = GameEngineRenderTarget::Create(DXGI_FORMAT_R32_FLOAT, { LightDataValue.ShadowTargetSizeX, LightDataValue.ShadowTargetSizeY }, float4::RED);
	ShadowTarget->CreateDepthTexture();
}

void GameEngineLight::LightUpdate(GameEngineCamera* _Camera, float _DeltaTime) 
{
	// GetTransform()->SetCameraMatrix(_Camera->GetView(), _Camera->GetProjection());

	LightDataValue.CameraViewInverseMatrix = _Camera->GetView().InverseReturn();

	LightDataValue.LightPos = GetTransform()->GetWorldPosition();
	LightDataValue.LightDir = GetTransform()->GetLocalForwardVector();
	LightDataValue.ViewLightPos = LightDataValue.LightPos * _Camera->GetView();
	LightDataValue.ViewLightDir = LightDataValue.LightDir * _Camera->GetView();
	LightDataValue.ViewLightRevDir = -LightDataValue.ViewLightDir;
	LightDataValue.CameraPosition = _Camera->GetTransform()->GetWorldPosition() * _Camera->GetView();

	LightDataValue.LightViewMatrix.LookToLH(
		GetTransform()->GetWorldPosition(),
		GetTransform()->GetWorldForwardVector(),
		GetTransform()->GetWorldUpVector());

	LightDataValue.LightProjectionMatrix.OrthographicLH(
		ShadowRange.x,
		ShadowRange.y,
		LightDataValue.LightNear,
		LightDataValue.LightFar);

	LightDataValue.LightProjectionInverseMatrix = LightDataValue.LightProjectionMatrix.InverseReturn();

	LightDataValue.LightViewProjectionMatrix = LightDataValue.LightViewMatrix * LightDataValue.LightProjectionMatrix;
}
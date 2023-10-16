#include "PrecompileHeader.h"
#include "GameEngineParticleRenderer.h"
#include "GameEngineVertexBuffer.h"
#include "GameEngineStructuredBuffer.h"

GameEngineParticleRenderer::GameEngineParticleRenderer() 
{
	ComUnit.SetComputeShader("ParticleUpdate.hlsl");


	ComUnit.ShaderResHelper.SetConstantBufferLink("RenderBaseValue", BaseValue);
	ComUnit.ShaderResHelper.SetTexture("EngineNoise", "noise_03.jpg");
	ComUnit.ShaderResHelper.SetConstantBufferLink("ParticleUpdateInfo", ParticleUpdateInfoValue);
}

GameEngineParticleRenderer::~GameEngineParticleRenderer() 
{
}

void GameEngineParticleRenderer::SetTexture(std::string_view _Name)
{
	ParticleUnit->ShaderResHelper.SetTexture("DiffuseTexture", _Name);
}

void GameEngineParticleRenderer::Start()
{
	GameEngineRenderer::Start();

	{
		std::shared_ptr<GameEngineRenderUnit> Unit = CreateRenderUnit();
		Unit->SetMesh("PointMesh");
		Unit->SetMaterial("Particle", RenderPath::Alpha);

		ParticleInfoValue.StartColor = float4::ONE;
		ParticleInfoValue.EndColor = float4::ONE;

		ParticleInfoValue.StartScale = float4::ONE * 50.0f;
		ParticleInfoValue.EndScale = float4::ONE * 300.0f;

		Unit->ShaderResHelper.SetConstantBufferLink("ParticleInfo", ParticleInfoValue);
		MaxCount = 1000;

		Unit->RenderModeValue = RenderMode::Particle;
		Unit->InstanceCount = MaxCount;
		ParticleUnit = Unit;
	}


	// Buffer = GameEngineVertexBuffer::Create(Particle);

	{
		// 1000���� ������ ����ü

		//RWStructuredBuffer<ParticleComputeData> ParticleBuffer : register(u0);

		std::shared_ptr<class GameEngineStructuredBuffer> FindBuffer = GameEngineStructuredBuffer::Find("ParticleBuffer", sizeof(ParticleData));

		// ParticleBuffer = std::make_shared<GameEngineStructuredBuffer>();
		ParticleBuffer = FindBuffer;
		ParticleBuffer->CreateResize(sizeof(ParticleData), MaxCount, StructuredBufferType::UAV_INC, nullptr);
	}

	{
		//RWStructuredBuffer<ParticleShareData> ParticleShare : register(u1);
		
		// ���� ��ƼŬ�� ���� ����
		// ���̴� ���ο��� ���ڸ� ���ְ� �װ� cpu���� Ȯ���Ҽ� �ִ� �뵵�� ����Ϸ��� ���̴�.

		// ResDesc.Name = 0x000001a99fc61670 "ParticleShare"

		std::shared_ptr<class GameEngineStructuredBuffer> FindBuffer = GameEngineStructuredBuffer::Find("ParticleShare", sizeof(ParticleShareData));

		// ParticleShareBuffer = std::make_shared<GameEngineStructuredBuffer>();
		ParticleShareBuffer = FindBuffer;
		ParticleShareBuffer->CreateResize(sizeof(ParticleShareData), 1, StructuredBufferType::UAV_INC, nullptr, true);
	}

}

void GameEngineParticleRenderer::Update(float _DeltaTime) 
{
	// �ʴ� ��ƼŬ ������ 
	float fAliveTime = 1.f / Frequency;


	// �츰 RenderBaseValue���� �̹� ����ϰ� �����Ƿ� �ʿ䰡 ����. �����ð�
	// m_fAccTime += _DeltaTime;

	// �����ð��� ��ƼŬ ���� �ð��� �Ѿ��
	if (fAliveTime < BaseValue.SumDeltaTime)
	{
		float f = (BaseValue.SumDeltaTime / fAliveTime);
		UINT iAliveCount = (UINT)f;
		BaseValue.SumDeltaTime = f - floorf(f);

		//tParticleShare share = { iAliveCount, };
		ParticleShareData share = { 10, };
		ParticleShareBuffer->SetData(&share, 1);
	}
	else
	{
		ParticleShareData share = {};
		ParticleShareBuffer->SetData(&share, 1);
	}

	ParticleUpdateInfoValue.ObjectWorldPos = GetTransform()->GetWorldPosition();


	ComUnit.m_iGroupX = 128;

	ComUnit.Execute();

	BaseValue;
}

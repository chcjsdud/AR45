#pragma once
#include "GameEngineRenderer.h"

struct ParticleInfo
{
	float4 StartScale;
	float4 EndScale;
	float4 StartColor;
	float4 EndColor;
};

struct ParticleData
{
	float4 vRelativePos;
	float4 vDir;

	float fMaxTime;
	float fCurTime;
	float fSpeed;
	UINT  iActive;
};

struct ParticleUpdateInfo 
{
	int PARTICLE_MAX = 1000;
	int IsWorldSpawn = 1;
	float SpawnRange = 300.0f;
	float MinSpeed = 0.0f;
	float MaxSpeed = 0.0f;
	float MinLife = 1.0f;
	float MaxLife = 5.0f;
	float Temp1;
	float4 ObjectWorldPos; // ���ͳ� �������� ���� �������� 

	//m_UpdateCS->SetWorldSpawn(m_WorldSpawn);
	//m_UpdateCS->SetObjectWorldPos(Transform()->GetWorldPos());
	//m_UpdateCS->SetSpawnRange(m_fSpawnRange);
	//m_UpdateCS->SetMinMaxSpeed(m_vMinMaxSpeed);
	//m_UpdateCS->SetMinMaxLifeTime(m_vMinMaxLifeTime);

};


struct ParticleComputeData
{
	// ���� ��ġ
	float4 vRelativePos;
	// ��ƼŬ�� ����
	float4 vDir;

	// �ð� ������½ð�
	float fMaxTime;
	// ���� �ð�
	float fCurTime;
	// �̵��Ҷ��� ���ǵ�
	float fSpeed;
	// ����ֳ� �׾��ֳ�.
	uint iActive;
};

struct ParticleShareData
{
	uint iAliveCount;
	uint iPadding0;
	uint iPadding1;
	uint iPadding2;
};


// ���� :
class GameEngineParticleRenderer : public GameEngineRenderer
{
public:
	// constrcuter destructer
	GameEngineParticleRenderer();
	~GameEngineParticleRenderer();

	// delete Function
	GameEngineParticleRenderer(const GameEngineParticleRenderer& _Other) = delete;
	GameEngineParticleRenderer(GameEngineParticleRenderer&& _Other) noexcept = delete;
	GameEngineParticleRenderer& operator=(const GameEngineParticleRenderer& _Other) = delete;
	GameEngineParticleRenderer& operator=(GameEngineParticleRenderer&& _Other) noexcept = delete;

	void SetTexture(std::string_view _Name);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	GameEngineComputeUnit ComUnit;
	ParticleUpdateInfo ParticleUpdateInfoValue;
	ParticleInfo ParticleInfoValue;

private:
	std::shared_ptr<class GameEngineVertexBuffer> Buffer;
	std::shared_ptr<class GameEngineStructuredBuffer> ParticleBuffer;
	std::shared_ptr<class GameEngineStructuredBuffer> ParticleShareBuffer;

	std::shared_ptr<GameEngineRenderUnit> ParticleUnit = nullptr;
	
	int MaxCount = 1000;
	float Frequency = 5.0f;
};


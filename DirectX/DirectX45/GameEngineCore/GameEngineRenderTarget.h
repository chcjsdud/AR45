#pragma once
#include "GameEngineRenderer.h"
#include "GameEngineCore.h"



class GameEngineRenderTarget;
class GameEnginePostProcess
	: std::enable_shared_from_this<GameEnginePostProcess>
{
	friend GameEngineRenderTarget;

public:
	std::shared_ptr<GameEngineRenderTarget> ResultTarget;

protected:
	virtual void Start(GameEngineRenderTarget* _Target) = 0;
	virtual void Effect(GameEngineRenderTarget* _Target, float _DeltaTime) = 0;
};

// 설명 :
class GameEngineTexture;
class GameEngineRenderTarget : public GameEngineResource<GameEngineRenderTarget>,
	std::enable_shared_from_this<GameEngineRenderTarget>
{

	friend class GameEngineCoreWindow;
	friend class GameEngineCore;
public:
	static void AllTargetReset();

	// constrcuter destructer
	GameEngineRenderTarget();
	~GameEngineRenderTarget();

	// delete Function
	GameEngineRenderTarget(const GameEngineRenderTarget& _Other) = delete;
	GameEngineRenderTarget(GameEngineRenderTarget&& _Other) noexcept = delete;
	GameEngineRenderTarget& operator=(const GameEngineRenderTarget& _Other) = delete;
	GameEngineRenderTarget& operator=(GameEngineRenderTarget&& _Other) noexcept = delete;

	static std::shared_ptr<GameEngineRenderTarget> Create(const std::string_view& _Name, std::shared_ptr<GameEngineTexture> _Texture, float4 _Color)
	{
		std::shared_ptr<GameEngineRenderTarget> NewRenderTarget = GameEngineResource::Create(_Name);

		NewRenderTarget->ResCreate(_Texture, _Color);

		return NewRenderTarget;
	}

	static std::shared_ptr<GameEngineRenderTarget> Create(DXGI_FORMAT _Format, float4 _Scale, float4 _Color)
	{
		std::shared_ptr<GameEngineRenderTarget> NewRenderTarget = GameEngineResource::CreateUnNamed();

		NewRenderTarget->ResCreate(_Format, _Scale, _Color);

		return NewRenderTarget;
	}

	void Clear();

	void Setting() override;

	static void Reset();

	std::shared_ptr<GameEngineTexture> GetDepthTexture()
	{
		return DepthTexture;
	}

	void SetDepthTexture(std::shared_ptr<GameEngineTexture> _DepthTex)
	{
		DepthTexture = _DepthTex;
	}

	void CreateDepthTexture(int _Index = 0);

	void Merge(std::shared_ptr<GameEngineRenderTarget> _Other, size_t _Index = 0);

	// 랜더타겟에다가 effect를 준다는 개념이 됩니다.


	template<typename EffectType>
	std::shared_ptr<EffectType> CreateEffect()
	{
		std::shared_ptr<EffectType> Effect = std::make_shared<EffectType>();

		EffectInit(Effect);

		// std::shared_ptr<GameEnginePostProcess> UpCast = std::dynamic_pointer_cast<GameEnginePostProcess>(Effect);
		Effects.push_back(Effect);
		return Effect;
	}

	void ReleaseEffect(std::shared_ptr<GameEnginePostProcess> _Effect);

	void Effect(float _DeltaTime);

	std::shared_ptr<GameEngineTexture> GetTexture(int _Index)
	{
		return Textures[_Index];
	}

	void DepthSettingOn() 
	{
		DepthSetting = true;
	}

	void DepthSettingOff()
	{
		DepthSetting = false;
	}

	void AddNewTexture(DXGI_FORMAT _Format, float4 _Scale, float4 _Color)
	{
		ResCreate(_Format, _Scale, _Color);
	}

	void ChangeViewPort(float4 _Scale, int _Index = 0);

protected:

private:
	static void RenderTargetUnitInit();
	static GameEngineRenderUnit MergeUnit;

	bool DepthSetting = true;

	std::vector<float4> Color;

	std::vector<std::shared_ptr<GameEnginePostProcess>> Effects;

	std::vector<std::shared_ptr<GameEngineTexture>> Textures;
	std::vector<D3D11_VIEWPORT> ViewPortDatas;
	std::vector<ID3D11RenderTargetView*> RTVs;
	std::vector<ID3D11ShaderResourceView*> SRVs;

	std::shared_ptr<GameEngineTexture> DepthTexture;

	void ResCreate(std::shared_ptr<GameEngineTexture> _Texture, float4 _Color);

	void ResCreate(DXGI_FORMAT _Format, float4 _Scale, float4 _Color);

	void EffectInit(std::shared_ptr<GameEnginePostProcess> _PostProcess);

};

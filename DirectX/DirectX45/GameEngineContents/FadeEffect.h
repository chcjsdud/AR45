#pragma once
#include <GameEngineCore/GameEngineRenderTarget.h>

// Ό³Έν :
class FadeEffect : public GameEnginePostProcess
{
public:
	// constrcuter destructer
	FadeEffect();
	~FadeEffect();

	// delete Function
	FadeEffect(const FadeEffect& _Other) = delete;
	FadeEffect(FadeEffect&& _Other) noexcept = delete;
	FadeEffect& operator=(const FadeEffect& _Other) = delete;
	FadeEffect& operator=(FadeEffect&& _Other) noexcept = delete;

protected:
	void Start(std::shared_ptr<GameEngineRenderTarget> _Target) override;
	void Effect(std::shared_ptr<GameEngineRenderTarget> _Target) override;

private:

};


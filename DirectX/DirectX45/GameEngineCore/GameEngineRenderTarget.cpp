#include "PrecompileHeader.h"
#include "GameEngineRenderTarget.h"

GameEngineRenderUnit GameEngineRenderTarget::MergeUnit;

void GameEngineRenderTarget::RenderTargetUnitInit() 
{
	MergeUnit.SetMesh("FullRect");
	MergeUnit.SetMaterial("Merge");
}


GameEngineRenderTarget::GameEngineRenderTarget() 
{
}

GameEngineRenderTarget::~GameEngineRenderTarget() 
{
	DepthTexture = nullptr;
}


void GameEngineRenderTarget::ResCreate(std::shared_ptr<GameEngineTexture> _Texture, float4 _Color)
{
	Textures.push_back(_Texture);
	SRVs.push_back(_Texture->GetSRV());
	RTVs.push_back(_Texture->GetRTV());
	Color.push_back(_Color);

	D3D11_VIEWPORT ViewPortData;

	ViewPortData.TopLeftX = 0;
	ViewPortData.TopLeftY = 0;
	ViewPortData.Width = static_cast<float>(_Texture->GetScale().uix());
	ViewPortData.Height = static_cast<float>(_Texture->GetScale().uiy());
	ViewPortData.MinDepth = 0.0f;
	ViewPortData.MaxDepth = 1.0f;

	ViewPortDatas.push_back(ViewPortData);


}

void GameEngineRenderTarget::ResCreate(DXGI_FORMAT _Format, float4 _Scale, float4 _Color)
{
	D3D11_TEXTURE2D_DESC Desc = {0};
	Desc.ArraySize = 1;
	Desc.Width = _Scale.uix();
	Desc.Height = _Scale.uiy();
	Desc.Format = _Format;
	Desc.SampleDesc.Count = 1;
	Desc.SampleDesc.Quality = 0;
	Desc.MipLevels = 1;
	Desc.Usage = D3D11_USAGE_DEFAULT;
	Desc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_RENDER_TARGET | D3D11_BIND_FLAG::D3D11_BIND_SHADER_RESOURCE;
	// Desc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_READ;
	// Desc.MiscFlags = 0;

	std::shared_ptr<GameEngineTexture> Tex = GameEngineTexture::Create(Desc);
	Textures.push_back(Tex);

	D3D11_VIEWPORT ViewPortData;
	ViewPortData.TopLeftX = 0;
	ViewPortData.TopLeftY = 0;
	ViewPortData.Width = static_cast<float>(_Scale.uix());
	ViewPortData.Height = static_cast<float>(_Scale.uiy());
	ViewPortData.MinDepth = 0.0f;
	ViewPortData.MaxDepth = 1.0f;

	ViewPortDatas.push_back(ViewPortData);

	SRVs.push_back(Tex->GetSRV());
	RTVs.push_back(Tex->GetRTV());
	Color.push_back(_Color);

}

void GameEngineRenderTarget::Clear()
{
	for (size_t i = 0; i < Textures.size(); i++)
	{
		ID3D11RenderTargetView* RTV = Textures[i]->GetRTV();

		if (nullptr == RTV)
		{
			MsgAssert("����Ÿ�� �䰡 �������� �ʾƼ� Ŭ��� �Ұ����մϴ�.");
			return;
		}

		GameEngineDevice::GetContext()->ClearRenderTargetView(RTV, Color[i].Arr1D);
	}

	ID3D11DepthStencilView* DSV
		= DepthTexture != nullptr ? DepthTexture->GetDSV() : nullptr;

	if (nullptr != DSV)
	{
		GameEngineDevice::GetContext()->ClearDepthStencilView(DSV, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
	}
}

void GameEngineRenderTarget::Setting() 
{
   // https://learn.microsoft.com/en-us/windows/win32/direct3d11/overviews-direct3d-11-resources-limits

	ID3D11RenderTargetView** RTV = &RTVs[0];

	if (nullptr == RTV)
	{
		MsgAssert("����Ÿ�� �䰡 �������� �ʾƼ� Ŭ��� �Ұ����մϴ�.");
	}

	ID3D11DepthStencilView* DSV 
		= DepthTexture != nullptr ? DepthTexture->GetDSV() : nullptr;

	if (false == DepthSetting)
	{
		DSV = nullptr;
	}

	// ���� ������ z���� ���� �ʰڽ��ϴ�.
	GameEngineDevice::GetContext()->OMSetRenderTargets(static_cast<UINT>(RTVs.size()), RTV, DSV);
	GameEngineDevice::GetContext()->RSSetViewports(static_cast<unsigned int>(ViewPortDatas.size()), &ViewPortDatas[0]);
}

void GameEngineRenderTarget::Reset()
{
	ID3D11RenderTargetView* RTV[8] = {nullptr};

	GameEngineDevice::GetContext()->OMSetRenderTargets(8, RTV, nullptr);
}

void GameEngineRenderTarget::CreateDepthTexture(int _Index)
{
	D3D11_TEXTURE2D_DESC Desc = {0,};

	Desc.ArraySize = 1;
	Desc.Width = Textures[_Index]->GetWidth();
	Desc.Height = Textures[_Index]->GetHeight();

	//            4����Ʈ�� 3����Ʈ�� 0~1.0f ǥ���ϴµ� ����ϰ�
	//            ������ �ڿ��ִ� 1����Ʈ�� ���ٽ� ���̶�� �ϴ� �ɷ� ����Ҽ� �ְ� �ϴ� ����.
	Desc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;

	Desc.SampleDesc.Count = 1;
	Desc.SampleDesc.Quality = 0;

	Desc.MipLevels = 1;
	Desc.Usage = D3D11_USAGE_DEFAULT;

	Desc.CPUAccessFlags = 0;
	Desc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_DEPTH_STENCIL;
	DepthTexture = GameEngineTexture::Create(Desc);
}


// ������ ������������ ����� �Ѵ�.
// ����������


void GameEngineRenderTarget::Merge(std::shared_ptr<GameEngineRenderTarget> _Other, size_t _Index)
{
	Setting();

	MergeUnit.ShaderResHelper.SetTexture("DiffuseTex", _Other->Textures[_Index]);
	MergeUnit.Render(0.0f);
	MergeUnit.ShaderResHelper.AllResourcesReset();

}

void GameEngineRenderTarget::ReleaseEffect(std::shared_ptr<GameEnginePostProcess> _Effect)
{
	std::vector<std::shared_ptr<GameEnginePostProcess>>::iterator LoopIter = Effects.begin();
	std::vector<std::shared_ptr<GameEnginePostProcess>>::iterator EndIter = Effects.end();

	for (; LoopIter != EndIter; ++LoopIter)
	{
		if ((*LoopIter) == _Effect)
		{
			LoopIter = Effects.erase(LoopIter);
			break;
		}
	}
}

void GameEngineRenderTarget::Effect(float _DeltaTime)
{
	for (size_t i = 0; i < Effects.size(); i++)
	{
		Effects[i]->Effect(this, _DeltaTime);
	}
}


void GameEngineRenderTarget::EffectInit(std::shared_ptr<GameEnginePostProcess> _PostProcess)
{
	_PostProcess->Start(this);
}

void GameEngineRenderTarget::ChangeViewPort(float4 _Scale, int _Index)
{
	D3D11_VIEWPORT ViewPortData;
	ViewPortData.TopLeftX = 0;
	ViewPortData.TopLeftY = 0;
	ViewPortData.Width = static_cast<float>(_Scale.uix());
	ViewPortData.Height = static_cast<float>(_Scale.uiy());
	ViewPortData.MinDepth = 0.0f;
	ViewPortData.MaxDepth = 1.0f;

	ViewPortDatas[_Index] = ViewPortData;
}
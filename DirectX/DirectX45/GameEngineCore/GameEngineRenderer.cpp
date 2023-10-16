#include "PrecompileHeader.h"
#include "GameEngineRenderer.h"
#include <GameEnginePlatform/GameEngineWindow.h>


#include "GameEngineLevel.h"
#include "GameEngineCamera.h"
#include "GameEngineMaterial.h"
#include "GameEngineVertexShader.h"
#include "GameEnginePixelShader.h"
#include "GameEngineComputeShader.h"
#include "GameEngineGeometryShader.h"
#include "GameEngineShaderResHelper.h"
#include "GameEngineMesh.h"
#include "GameEngineInputLayOut.h"

void GameEngineComputeUnit::Execute()
{
	// ��ƼŬ ������
	// ��ƼŬ ������ 
	ShaderResHelper.ComputeSetting();

	// ShaderResHelper.Setting();
	ComputeShader->Setting();
	GameEngineDevice::GetContext()->Dispatch(m_iGroupX, m_iGroupY, m_iGroupZ);
	ShaderResHelper.AllResourcesReset();
}

void GameEngineComputeUnit::SetComputeShader(const std::string_view& _Name)
{
	ComputeShader = GameEngineComputeShader::Find(_Name);

	if (nullptr == ComputeShader)
	{
		MsgAssert(std::string(_Name) + "�������� �ʴ� ��ǻƮ ���̴��� �����Ϸ��� �߽��ϴ�");
	}

	const GameEngineShaderResHelper& Res = ComputeShader->GetShaderResHelper();
	ShaderResHelper.Copy(Res);
}

GameEngineRenderUnit::GameEngineRenderUnit()
{
	InputLayOutPtr = std::make_shared<GameEngineInputLayOut>();
}

void GameEngineRenderUnit::SetRenderer(GameEngineRenderer* _Renderer)
{
	ParentRenderer = _Renderer;
}

void GameEngineRenderUnit::SetMesh(const std::string_view& _Name) 
{
	Mesh = GameEngineMesh::Find(_Name);

	if (nullptr == Mesh)
	{
		MsgAssert("�������� �ʴ� �Ž��� �����Ϸ��� �߽��ϴ�.")
	}

	if (false == InputLayOutPtr->IsCreate() && nullptr != Material)
	{
		InputLayOutPtr->ResCreate(Mesh->GetVertexBuffer(), Material->GetVertexShader());
	}
}

void GameEngineRenderUnit::SetMesh(std::shared_ptr<GameEngineMesh> _Mesh)
{
	Mesh = _Mesh;

	if (false == InputLayOutPtr->IsCreate() && nullptr != Material)
	{
		InputLayOutPtr->ResCreate(Mesh->GetVertexBuffer(), Material->GetVertexShader());
	}
}

void GameEngineRenderUnit::SetMaterial(const std::string_view& _Name, RenderPath _Path /*= RenderPath::None*/)
{
	// GetCamera()->Units[0];

	Material = GameEngineMaterial::Find(_Name);

	if (nullptr == Material)
	{
		MsgAssert("�������� �ʴ� ��Ƽ������ ����߽��ϴ�.");
		return;
	}

	{
		const GameEngineShaderResHelper& Res = Material->GetVertexShader()->GetShaderResHelper();
		ShaderResHelper.Copy(Res);
	}

	{
		const GameEngineShaderResHelper& Res = Material->GetPixelShader()->GetShaderResHelper();
		ShaderResHelper.Copy(Res);
	}

	{
		if (nullptr != Material->GetGeometryShader())
		{
			const GameEngineShaderResHelper& Res = Material->GetGeometryShader()->GetShaderResHelper();
			ShaderResHelper.Copy(Res);
		}
	}


	if (false == InputLayOutPtr->IsCreate() && nullptr != Mesh)
	{
		InputLayOutPtr->ResCreate(Mesh->GetVertexBuffer(), Material->GetVertexShader());
	}


	// ī�޶� ���� �ϴ¼���.


	if (true == ShaderResHelper.IsConstantBuffer("TransformData"))
	{
		const TransformData& Data = ParentRenderer->GetTransform()->GetTransDataRef();
		ShaderResHelper.SetConstantBufferLink("TransformData", Data);
	}

	if (true == ShaderResHelper.IsConstantBuffer("RenderBaseValue"))
	{
		ShaderResHelper.SetConstantBufferLink("RenderBaseValue", ParentRenderer->BaseValue);
	}

	if (true == ShaderResHelper.IsConstantBuffer("LightDatas") && nullptr != ParentRenderer)
	{
		LightDatas& Data = ParentRenderer->GetActor()->GetLevel()->LightDataObject;
		ShaderResHelper.SetConstantBufferLink("LightDatas", Data);
	}

	if (nullptr != GetRenderer())
	{
		GetRenderer()->GetCamera()->PushRenderUnit(shared_from_this(), _Path);
	}
}

void GameEngineRenderUnit::Setting()
{
	if (nullptr == Mesh)
	{
		MsgAssert("�Ž��� �������� �ʴ� ����Ʈ �Դϴ�");
	}

	if (nullptr == Material)
	{
		MsgAssert("������������ �������� �ʴ� ����Ʈ �Դϴ�");
	}

	InputLayOutPtr->Setting();

	Mesh->Setting();
	Material->Setting();
	ShaderResHelper.Setting();
}

void GameEngineRenderUnit::ShadowSetting()
{
	if (nullptr == Mesh)
	{
		MsgAssert("�Ž��� �������� �ʴ� ����Ʈ �Դϴ�");
	}

	if (nullptr == Material)
	{
		MsgAssert("������������ �������� �ʴ� ����Ʈ �Դϴ�");
	}

	ShadowInputLayOutPtr->Setting();

	Mesh->Setting();
	Material->Setting();
	ShaderResHelper.Setting();
}

void GameEngineRenderUnit::Draw()
{
	UINT IndexCount = Mesh->IndexBufferPtr->GetIndexCount();
	GameEngineDevice::GetContext()->DrawIndexed(IndexCount, 0, 0);
	// GameEngineDevice::GetContext()->Draw
}

void GameEngineRenderUnit::DrawParticle(int _Count)
{
	UINT IndexCount = Mesh->IndexBufferPtr->GetIndexCount();
	GameEngineDevice::GetContext()->DrawIndexedInstanced(IndexCount, _Count, 0, 0, 0);
}

void GameEngineRenderUnit::ShadowOn()
{
	IsShadow = true;

	std::shared_ptr<GameEngineVertexShader> ShadowPtr = GameEngineVertexShader::Find("Shadow.hlsl");
	if (nullptr == ShadowInputLayOutPtr)
	{
		ShadowInputLayOutPtr = std::make_shared<GameEngineInputLayOut>();
		ShadowInputLayOutPtr->ResCreate(Mesh->GetVertexBuffer(), ShadowPtr);
	}
}

void GameEngineRenderUnit::Render(float _DeltaTime)
{
	if (nullptr != RenderFunction)
	{
		RenderFunction(_DeltaTime);
		return;
	}

	switch (RenderModeValue)
	{
	case RenderMode::Base:
		Setting();
		Draw();
		break;
	case RenderMode::Particle:
		Setting();
		DrawParticle(InstanceCount);
		GameEngineDevice::GetContext()->GSSetShader(nullptr, nullptr, 0);
		break;
	default:
		break;
	}

	ShaderResHelper.AllResourcesReset();
}

GameEngineRenderer::GameEngineRenderer() 
{
	BaseValue.ScreenScale = GameEngineWindow::GetScreenSize();
	BaseValue.NoiseResolution = {1024, 1024};
}

GameEngineRenderer::~GameEngineRenderer() 
{
}

void GameEngineRenderer::Start()
{
	PushCameraRender(0);
}

void GameEngineRenderer::RenderTransformUpdate(GameEngineCamera* _Camera)
{
	if (nullptr == _Camera)
	{
		assert(false);
		return;
	}

	// RenderCamera = _Camera;

	GetTransform()->SetCameraMatrix(_Camera->GetView(), _Camera->GetProjection());
}

void GameEngineRenderer::RenderBaseValueUpdate(float _Delta)
{
	BaseValue.SumDeltaTime += _Delta;
	BaseValue.DeltaTime = _Delta;
}

void GameEngineRenderer::Render(float _Delta) 
{
	RenderBaseValueUpdate(_Delta);
	// GameEngineDevice::GetContext()->VSSetConstantBuffers();
	// GameEngineDevice::GetContext()->PSSetConstantBuffers();

	// ���� ����Ʈ�� 1���� �Ž� 1���� ��Ƽ������ ������ �ϴ� �뵵�Դϴ�.
	// 3D�����ԵǸ� �̰� �ȵǿ�.
	// ĳ���Ͱ� �Ž��� 1���� �ƴϾ�.
	// �ٸ� �� ����
	
	// �ؽ�ó ���� ������� ���� �̷��͵��� ���δ� ó�� �ȴ�.
	//for (size_t i = 0; i < Units.size(); i++)
	//{
	//	Units[i]->Render(_Delta);
	//}

}

std::shared_ptr<GameEngineMaterial> GameEngineRenderer::GetMaterial(int _index/* = 0*/)
{
	if (Units.size() <= _index)
	{
		MsgAssert("�������� �ʴ� ���� ����Ʈ�� ����Ϸ��� �߽��ϴ�.");
	}

	return Units[_index]->Material;
}

void GameEngineRenderer::PushCameraRender(int _CameraOrder)
{
	GetLevel()->PushCameraRenderer(DynamicThis<GameEngineRenderer>(), _CameraOrder);
}

void GameEngineRenderer::CalSortZ(GameEngineCamera* _Camera)
{
	// View��ķ� �ؾ� ī�޶� ������ ���� �� ������ �������� ī�޶� ��ġ�Ѱ��� z�� ó���Ѵ�.

	switch (_Camera->ProjectionType)
	{
	case CameraType::Orthogonal:
	{
		// ���� �����̱� ������ ī�޶��� View����� ���ؼ� ������ �������� 
		// ��ġ�� ī�޶��� ������ ���������� ��ġ�� �ٲٰ� �� z�� ����ϸ� Ȯ����
		// ���������� ī�޶���� z�Ÿ��� �ȴ�.
		float4 View = GetTransform()->GetWorldPosition() * _Camera->View;
		CalZ = View.z;
		break;
	}
	case CameraType::Perspective:
	{
		float4 View = GetTransform()->GetWorldPosition() * _Camera->View;
		CalZ = View.Size();
		break;
	}
	default:
		break;
	}

}


std::shared_ptr<GameEngineRenderUnit> GameEngineRenderer::CreateRenderUnit(std::string_view _Mesh, std::string_view _Material)
{
	std::shared_ptr<GameEngineRenderUnit> Unit = CreateRenderUnit();

	Unit->SetMesh(_Mesh);
	Unit->SetMaterial(_Material);
	return Unit;
}

std::shared_ptr<GameEngineRenderUnit> GameEngineRenderer::CreateRenderUnit()
{
	std::shared_ptr<GameEngineRenderUnit> Unit = std::make_shared<GameEngineRenderUnit>();

	Unit->SetRenderer(this);
	Units.push_back(Unit);

	return Unit;
}

std::shared_ptr<GameEngineRenderUnit> GameEngineRenderer::CreateRenderUnitToIndex(unsigned int _Index)
{
	if (_Index >= Units.size())
	{
		Units.resize(_Index + 1);
	}

	std::shared_ptr<GameEngineRenderUnit> Unit = std::make_shared<GameEngineRenderUnit>();
	Unit->SetRenderer(this);
	Units[_Index] = Unit;

	return Unit;
}


void GameEngineRenderer::SetMaterial(const std::string_view& _Name, int _index /*= 0*/)
{
	std::shared_ptr<GameEngineRenderUnit> Unit = GetUnit(_index);

	if (nullptr == Unit)
	{
		Unit = CreateRenderUnitToIndex(_index);
	}

	Unit->SetMaterial(_Name);
}


void GameEngineRenderer::SetMesh(const std::string_view& _Name, int _index /*= 0*/)
{
	std::shared_ptr<GameEngineRenderUnit> Unit = GetUnit(_index);

	if (nullptr == Unit)
	{
		Unit = CreateRenderUnitToIndex(_index);
	}

	Unit->SetMesh(_Name);
}
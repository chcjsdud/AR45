#include "PrecompileHeader.h"
#include "ContentsCore.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineVertexShader.h>
#include <GameEngineCore/GameEnginePixelShader.h>
#include <GameEngineCore/GameEngineMaterial.h>
#include <GameEngineCore/GameEngineBlend.h>
#include <GameEngineCore/GameEngineFBXMesh.h>
#include <GameEngineCore/GameEngineFBXAnimation.h>

void ContentsCore::ContentsResourcesCreate()
{
	// �ؽ�ó �ε常 �� �������� �ϰ� �����ϴ� ������ ���̼���.

	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("ContentsShader");

		std::vector<GameEngineFile> Files = NewDir.GetAllFile({ ".hlsl", ".fx" });

		for (size_t i = 0; i < Files.size(); i++)
		{
			GameEngineShader::AutoCompile(Files[i]);
		}

		//GameEngineVertexShader::Load(Files[0].GetFullPath(), "MyShader_VS");
		//GameEnginePixelShader::Load(Files[0].GetFullPath(), "MyShader_PS");
	}


	{
		D3D11_SAMPLER_DESC SamperData = {};
		SamperData.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
		SamperData.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
		SamperData.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
		SamperData.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
		// �ؽ�ó�� �ָ������� ��������
		// �ȹ�����.
		SamperData.MipLODBias = 0.0f;
		SamperData.MaxAnisotropy = 1;
		SamperData.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
		SamperData.MinLOD = -FLT_MAX;
		SamperData.MaxLOD = FLT_MAX;

		GameEngineSampler::ReSetting("ENGINEBASE", SamperData);
	}

	{
		D3D11_SAMPLER_DESC SamperData = {};
		SamperData.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
		SamperData.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
		SamperData.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
		SamperData.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
		// �ؽ�ó�� �ָ������� ��������
		// �ȹ�����.
		SamperData.MipLODBias = 0.0f;
		SamperData.MaxAnisotropy = 1;
		SamperData.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
		SamperData.MinLOD = -FLT_MAX;
		SamperData.MaxLOD = FLT_MAX;

		GameEngineSampler::Create("WRAP", SamperData);
	}


	{
		std::shared_ptr<GameEngineMaterial> Pipe = GameEngineMaterial::Create("My2DTexture");

		//Pipe->SetVertexBuffer("Rect");
		//Pipe->SetIndexBuffer("Rect");
		Pipe->SetVertexShader("MyShader.fx");
		Pipe->SetRasterizer("Engine2DBase");
		Pipe->SetPixelShader("MyShader.fx");
		Pipe->SetBlendState("AlphaBlend");
		Pipe->SetDepthState("EngineDepth");
	}


	{
		std::shared_ptr<GameEngineMaterial> Pipe = GameEngineMaterial::Create("Fade");

		//Pipe->SetVertexBuffer("FullRect");
		//Pipe->SetIndexBuffer("FullRect");
		Pipe->SetVertexShader("FadeShader.hlsl");
		Pipe->SetRasterizer("Engine2DBase");
		Pipe->SetPixelShader("FadeShader.hlsl");
		Pipe->SetBlendState("AlphaBlend");
		Pipe->SetDepthState("EngineDepth");
	}

	{
		// ������
		D3D11_BLEND_DESC Desc = { 0, };
		Desc.AlphaToCoverageEnable = false;
		Desc.IndependentBlendEnable = false;

		Desc.RenderTarget[0].BlendEnable = true;
		Desc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
		Desc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
		Desc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
		Desc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;

		Desc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
		Desc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
		Desc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ONE;

		GameEngineBlend::Create("OldFilm", Desc);
	}

	{
		std::shared_ptr<GameEngineMaterial> Pipe = GameEngineMaterial::Create("OldFilm");

		//Pipe->SetVertexBuffer("FullRect");
		//Pipe->SetIndexBuffer("FullRect");
		Pipe->SetVertexShader("OldFilmShader.hlsl");
		Pipe->SetRasterizer("Engine2DBase");
		Pipe->SetPixelShader("OldFilmShader.hlsl");
		Pipe->SetBlendState("OldFilm");
		Pipe->SetDepthState("EngineDepth");
	}


	{
		std::shared_ptr<GameEngineMaterial> Pipe = GameEngineMaterial::Create("OldTV");

		Pipe->SetVertexShader("OldTVShader.hlsl");
		Pipe->SetRasterizer("Engine2DBase");
		Pipe->SetPixelShader("OldTVShader.hlsl");
		Pipe->SetBlendState("OldFilm");
		Pipe->SetDepthState("EngineDepth");
	}


	{
		std::shared_ptr<GameEngineMaterial> Pipe = GameEngineMaterial::Create("DebugRect");
		Pipe->SetVertexShader("DebugMeshRender.hlsl");
		Pipe->SetRasterizer("Engine2DBase");
		Pipe->SetPixelShader("DebugMeshRender.hlsl");
		Pipe->SetBlendState("AlphaBlend");
		Pipe->SetDepthState("EngineDepth");
	}



	{
		{
			//GameEngineDirectory NewDir;
			//NewDir.MoveParentToDirectory("ContentResources");
			//NewDir.Move("ContentResources");
			//NewDir.Move("Mesh");
			//NewDir.Move("TestMesh");

			//std::vector<GameEngineFile> Files = NewDir.GetAllFile({ ".FBX" });

			//for (size_t i = 0; i < Files.size(); i++)
			//{
			//	if (true == GameEngineFBXMesh::IsCheckAnimationFBX(Files[i].GetFullPath()))
			//	{
			//		std::string Out = Files[i].GetFullPath();
			//		Out += " to AnimationMesh \n";
			//		OutputDebugStringA(Out.c_str());
			//	} else 
			//	{
			//		std::string Out = Files[i].GetFullPath();
			//		Out += " to BoneMesh \n";
			//		OutputDebugStringA(Out.c_str());
			//	}

			//	// bool Check = GameEngineFBX::IsCheckAnimationFBX(View);
			//	// GameEngineFBXMesh::Load(Files[i].GetFullPath());
			//}
		}



		{
			GameEngineDirectory NewDir;
			NewDir.MoveParentToDirectory("ContentResources");
			NewDir.Move("ContentResources");
			NewDir.Move("Mesh");
			NewDir.Move("AnimationTest");
			NewDir.Move("Mesh");

			std::vector<GameEngineFile> Files = NewDir.GetAllFile({ ".FBX" });

			for (size_t i = 0; i < Files.size(); i++)
			{
				// bool Check = GameEngineFBX::IsCheckAnimationFBX(View);
				GameEngineFBXMesh::Load(Files[i].GetFullPath());
			}
		}

		{
			GameEngineDirectory NewDir;
			NewDir.MoveParentToDirectory("ContentResources");
			NewDir.Move("ContentResources");
			NewDir.Move("Mesh");
			NewDir.Move("AnimationTest");
			NewDir.Move("Animation");

			std::vector<GameEngineFile> Files = NewDir.GetAllFile({ ".FBX" });

			for (size_t i = 0; i < Files.size(); i++)
			{
				// bool Check = GameEngineFBX::IsCheckAnimationFBX(View);
				GameEngineFBXAnimation::Load(Files[i].GetFullPath());
			}
		}
	}



	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("Test");

		std::vector<GameEngineFile> File = NewDir.GetAllFile({ ".Png", });

		for (size_t i = 0; i < File.size(); i++)
		{
			GameEngineTexture::Load(File[i].GetFullPath());
		}
	}

}

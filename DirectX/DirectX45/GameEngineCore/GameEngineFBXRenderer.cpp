#include "PrecompileHeader.h"
#include "GameEngineFBXRenderer.h"
#include "GameEngineFBXAnimation.h"
#include "GameEngineMaterial.h"


void GameEngineFBXAnimationInfo::Init(std::shared_ptr<GameEngineFBXMesh> _Mesh, std::shared_ptr<GameEngineFBXAnimation> _Animation, const std::string_view& _Name, int _Index)
{
	// GameENgineFBXAnimation의 행렬 정보가 완전해지는것은 
	// CalFbxExBoneFrameTransMatrix가 호출되고 난 후입니다.
	// 애니메이션의 행렬이 계산되는겁니다.

	_Animation->AnimationMatrixLoad(_Mesh, _Name, _Index);
	Aniamtion = _Animation;
	FBXAnimationData = Aniamtion->GetAnimationData(_Index);
	Start = static_cast<UINT>(FBXAnimationData->TimeStartCount);
	End = static_cast<UINT>(FBXAnimationData->TimeEndCount);
	Mesh = _Mesh;
	Aniamtion = _Animation;


	Start = 0;
	End = static_cast<unsigned int>(FBXAnimationData->TimeEndCount);
}


// 이걸 통해서 애니메이션을 진행시키고.
void GameEngineFBXAnimationInfo::Update(float _DeltaTime)
{
	// 0~24진행이죠?
	if (false == ParentRenderer->Pause)
	{
		CurFrameTime += _DeltaTime;
		PlayTime += _DeltaTime;
		//                      0.1
		// 1
		while (CurFrameTime >= Inter)
		{
			// 여분의 시간이 남게되죠?
			// 여분의 시간이 중요합니다.
			CurFrameTime -= Inter;
			++CurFrame;

			if (false == bOnceStart && CurFrame == 0)
			{
				bOnceStart = true;
				bOnceEnd = false;
			}

			if (CurFrame == (Frames.size() - 1)
				&& false == bOnceEnd)
			{
				bOnceEnd = true;
				bOnceStart = false;
				break;
			}

			if (CurFrame >= Frames.size() - 1)
			{
				if (true == Loop)
				{
					CurFrame = Start;
				}
				else
				{
					CurFrame = static_cast<unsigned int>(Frames.size()) - 1;
				}
			}
		}
	}

	unsigned int NextFrame = CurFrame;

	++NextFrame;

	if (NextFrame >= End)
	{
		NextFrame = 0;
	}

	if (CurFrame >= End)
	{
		CurFrame = 0;
	}

	// mesh      subset
	std::vector<std::vector< std::shared_ptr<GameEngineRenderUnit>>>& Units = ParentRenderer->GetAllRenderUnit();
	std::vector<float4x4>& AnimationBoneMatrix = ParentRenderer->AnimationBoneMatrixs;

	std::vector<AnimationBoneData>& AnimationBoneData = ParentRenderer->AnimationBoneDatas;

	for (int i = 0; i < AnimationBoneMatrix.size(); i++)
	{
		if (0 == FBXAnimationData->AniFrameData.size())
		{
			continue;
		}

		Bone* BoneData = ParentRenderer->GetFBXMesh()->FindBone(i);

		if (true == FBXAnimationData->AniFrameData[i].BoneMatData.empty())
		{
			AnimationBoneMatrix[i] = float4x4::Affine(BoneData->BonePos.GlobalScale, BoneData->BonePos.GlobalRotation, BoneData->BonePos.GlobalTranslation);
			return;
		}

		// 애니메이션 블랜드 등은 하나도 안들어가 있다.

		// CurFrame + 1

		FbxExBoneFrameData& CurData = FBXAnimationData->AniFrameData[i].BoneMatData[CurFrame];
		FbxExBoneFrameData& NextData = FBXAnimationData->AniFrameData[i].BoneMatData[NextFrame];

		AnimationBoneData[i].Scale = float4::Lerp(CurData.S, NextData.S, CurFrameTime);
		AnimationBoneData[i].RotQuaternion = float4::SLerpQuaternion(CurData.Q, NextData.Q, CurFrameTime);
		AnimationBoneData[i].Pos = float4::Lerp(CurData.T, NextData.T, CurFrameTime);

		//// 블랜드 change animation을 했고 그 이후로 0.2초가 지나지 않았다면
		//if (/*블랜드중이라면*/false)
		//{
		//	// 0.2초를 0~1초 바꿔야 합니다.

		//	
		//	// 0~0.2
		//	// 0~1로 바꾼 값을 
		//	float BlendRatio = 0.0f;


		//	AnimationBoneData[i].Scale = float4::Lerp(ParentRenderer->PrevAnimationBoneDatas[i].Scale, AnimationBoneData[i].Scale, BlendRatio);
		//	AnimationBoneData[i].RotQuaternion = float4::SLerpQuaternion(CurData.Q, NextData.Q, CurFrameTime);
		//	AnimationBoneData[i].Pos = float4::Lerp(CurData.T, NextData.T, CurFrameTime);
		//}

		size_t Size = sizeof(float4x4);

		float4x4 Mat = float4x4::Affine(AnimationBoneData[i].Scale, AnimationBoneData[i].RotQuaternion, AnimationBoneData[i].Pos);

		// 오프셋을 곱하지 않은 본행렬의 부모가 진짜 우리가 생각하는 월드이고
		ParentRenderer->AnimationBoneMatrixsNotOffset[i] = Mat;

		// 오프셋을 곱해주는 녀석은 버텍스에 곱해지기 위한 녀석이 된다.
		AnimationBoneMatrix[i] = BoneData->BonePos.Offset * Mat;
	}

}

void GameEngineFBXAnimationInfo::Reset()
{
	CurFrameTime = 0.0f;
	CurFrame = 0;
	PlayTime = 0.0f;
	// Start = 0;
}



GameEngineFBXRenderer::GameEngineFBXRenderer()
{
}

GameEngineFBXRenderer::~GameEngineFBXRenderer()
{
}


void GameEngineFBXRenderer::SetFBXMesh(const std::string& _Name, std::string _Material)
{
	std::shared_ptr<GameEngineFBXMesh> FindFBXMesh = GameEngineFBXMesh::Find(_Name);

	if (nullptr == FindFBXMesh)
	{
		MsgAssert("로드하지 않은 FBX 매쉬를 사용하려고 했습니다.");
	}

	FindFBXMesh->Initialize();

	const std::vector<Bone>& Bones = FindFBXMesh->GetAllBone();

	if (Bones.size() != AnimationBoneDatas.size())
	{
		AnimationBoneDatas.resize(Bones.size());

		for (size_t i = 0; i < Bones.size(); i++)
		{
			float4x4 Offset = Bones[i].BonePos.Offset;

			Offset.Decompose(AnimationBoneDatas[i].Scale, AnimationBoneDatas[i].RotQuaternion,AnimationBoneDatas[i].Pos);

			AnimationBoneDatas[i].RotEuler = AnimationBoneDatas[i].RotQuaternion.QuaternionToEulerDeg();
		}
	}


	// 너 몇개 가지고 있어.
	for (size_t UnitCount = 0; UnitCount < FindFBXMesh->GetRenderUnitCount(); UnitCount++)
	{
		SetFBXMesh(_Name, _Material, UnitCount);
	}
}

void GameEngineFBXRenderer::SetFBXMesh(const std::string& _Name, std::string _Material, size_t MeshIndex)
{
	std::shared_ptr<GameEngineFBXMesh> FindFBXMesh = GameEngineFBXMesh::Find(_Name);

	for (size_t SubSetCount = 0; SubSetCount < FindFBXMesh->GetSubSetCount(MeshIndex); SubSetCount++)
	{
		size_t SubSet = FindFBXMesh->GetSubSetCount(MeshIndex);

		SetFBXMesh(_Name, _Material, MeshIndex, SubSetCount);
	}
}

// SetFbxMesh를 해서 만들어진 랜더 유니트를 사용하게 하기 위해서 리턴해준다.
std::shared_ptr<GameEngineRenderUnit> GameEngineFBXRenderer::SetFBXMesh(const std::string& _Name,
	std::string _Material,
	size_t _MeshIndex,
	size_t _SubSetIndex /*= 0*/)
{
	std::shared_ptr<GameEngineFBXMesh> FindFBXMesh = GameEngineFBXMesh::Find(_Name);

	if (nullptr == FindFBXMesh)
	{
		MsgAssert("존재하지 않는 FBXMesh를 세팅했습니다.");
		return nullptr;
	}


	if (nullptr == FBXMesh && nullptr != FindFBXMesh)
	{
		FBXMesh = FindFBXMesh;
	}
	else if (nullptr != FBXMesh && FBXMesh != FindFBXMesh)
	{
		// 지금까지 만든거 다 날립니다.
	}

	FindFBXMesh->Initialize();

	// return nullptr;

	if (Unit.empty())
	{
		Unit.resize(FBXMesh->GetRenderUnitCount());
		for (size_t i = 0; i < Unit.size(); i++)
		{
			size_t Count = FBXMesh->GetSubSetCount(i);

			Unit[i].resize(Count);
			for (size_t j = 0; j < Count; j++)
			{
				Unit[i][j] = CreateRenderUnit();
			}
		}
	}

	std::shared_ptr<GameEngineRenderUnit> RenderUnit = Unit[_MeshIndex][_SubSetIndex];
	std::shared_ptr <GameEngineMesh> GetFBXMesh = FBXMesh->GetGameEngineMesh(_MeshIndex, _SubSetIndex);

	RenderUnit->SetMesh(GetFBXMesh);
	RenderUnit->SetMaterial(_Material);

	if (0 == AnimationBoneMatrixs.size())
	{
		size_t Count = FBXMesh->GetBoneCount();

		if (nullptr == FBXMesh)
		{
			MsgAssert("본이 존재하지 않는 매쉬에 애니메이션을 넣으려고 했습니다.");
		}

		AnimationBoneMatrixs.resize(Count);
		AnimationBoneMatrixsNotOffset.resize(Count);
		AnimationBoneDatas.resize(Count);
	}


	if (RenderUnit->ShaderResHelper.IsStructuredBuffer("ArrAniMationMatrix"))
	{
		GameEngineStructuredBufferSetter* AnimationBuffer = RenderUnit->ShaderResHelper.GetStructuredBufferSetter("ArrAniMationMatrix");

		AnimationBuffer->Res = FBXMesh->GetAnimationStructuredBuffer();

		if (nullptr == AnimationBuffer->Res)
		{
			MsgAssert("애니메이션용 스트럭처드 버퍼가 존재하지 않습니다.");
			return RenderUnit;
		}

		if (0 == AnimationBoneMatrixs.size())
		{
			return RenderUnit;
		}

		// 링크를 걸어준것.
		AnimationBuffer->SetData = &AnimationBoneMatrixs[0];
		AnimationBuffer->Size = sizeof(float4x4);
		AnimationBuffer->Count = AnimationBoneMatrixs.size();
	}


	if (RenderUnit->ShaderResHelper.IsTexture("DiffuseTexture"))
	{
		const FbxExMaterialSettingData& MatData = FBXMesh->GetMaterialSettingData(_MeshIndex, _SubSetIndex);

		if (nullptr != GameEngineTexture::Find(MatData.DifTextureName))
		{
			RenderUnit->ShaderResHelper.SetTexture("DiffuseTexture", MatData.DifTextureName);
		}
	}


	if (RenderUnit->ShaderResHelper.IsTexture("NormalTexture"))
	{
		const FbxExMaterialSettingData& MatData = FBXMesh->GetMaterialSettingData(_MeshIndex, _SubSetIndex);

		if (nullptr != GameEngineTexture::Find(MatData.NorTextureName))
		{
			RenderUnit->ShaderResHelper.SetTexture("NormalTexture", MatData.NorTextureName);
		}

		BaseValue.IsNormal = 1;
	}


	return RenderUnit;
}

void GameEngineFBXRenderer::CreateFBXAnimation(const std::string& _AnimationName, const std::string& _AnimationFBXName, const AnimationCreateParams& _Params, int _Index)
{
	// 애니메이션 방식은 무조건 1개일것이라고 보고.
	std::string UpperName = GameEngineString::ToUpper(_AnimationName);

	// 본을 가진 fbx가 세팅되어 있는지 검사한다.
	if (nullptr == GetFBXMesh())
	{
		MsgAssert("골격 FBX가 세팅되어 있지 않습니다.");
		return;
	}

	// 여기있는 함수를 외부에서 호출하면 됩니다.

	if (Animations.end() != Animations.find(UpperName))
	{
		MsgAssert("이미 존재하는 이름의 애니메이션입니다." + UpperName);
		return;
	}

	std::shared_ptr<GameEngineFBXAnimation> Animation = GameEngineFBXAnimation::Find(_AnimationFBXName);

	if (nullptr == Animation)
	{
		MsgAssert("GameEngineFBXAnimation이 존재하지 않습니다. " + std::string(_AnimationFBXName));
		return;
	}

	//GameEngineFile File;
	//File.SetPath(Animation->GetPath());
	//File.ChangeExtension(".AnimationFBX");

	//if (false == File.IsExists())
	//{
	//	Animation->Initialize();
	//}

	std::shared_ptr<GameEngineFBXAnimationInfo> NewAnimation = std::make_shared<GameEngineFBXAnimationInfo>();
	NewAnimation->Init(FBXMesh, Animation,_AnimationName, _Index);
	NewAnimation->ParentRenderer = this;
	NewAnimation->Inter = _Params.Inter;
	NewAnimation->Loop = _Params.Loop;
	NewAnimation->Reset();

	BaseValue.IsAnimation = 1;
	Animations.insert(std::make_pair(UpperName, NewAnimation));

	Animation;
}



void GameEngineFBXRenderer::PauseSwtich()
{
	Pause = !Pause;
}

void GameEngineFBXRenderer::ChangeAnimation(const std::string& _AnimationName, bool _Force /*= false*/)
{
	std::string UpperName = GameEngineString::ToUpper(_AnimationName);

	std::map<std::string, std::shared_ptr<GameEngineFBXAnimationInfo>>::iterator FindIter = Animations.find(UpperName);

	if (Animations.end() == FindIter)
	{
		MsgAssert("존재하지 않는 애니메이션으로 체인지 하려고 했습니다.");
		return;
	}

	if (false == _Force && CurAnimation == FindIter->second)
	{
		return;
	}

	CurAnimation = FindIter->second;
}


void GameEngineFBXRenderer::Update(float _DeltaTime)
{
	if (nullptr == CurAnimation)
	{
		return;
	}

	CurAnimation->Update(_DeltaTime);


	const TransformData& TransFormData = GetTransform()->GetTransDataRef();

	for (size_t i = 0; i < AttachTransformValue.size(); i++)
	{
		AttachTransformInfo& Data = AttachTransformValue[i];

		// 오프셋이 곱해지지 않은 행렬이 실제 본의 위치를 담고 있는 행렬이다.
		// 버텍스는 오프셋을 기반으로 만들어져있기 때문이다.
		float4x4 Mat = AnimationBoneMatrixsNotOffset[Data.Index];
		Mat *= TransFormData.WorldMatrix;

		float4 Scale;
		float4 Rot;
		float4 Pos;

		Mat.Decompose(Scale, Rot, Pos);

		// 세팅할때 월드로 해줘야 한다. 
		// 정말 너무 다양한 상황이 있을수 있기 때문에 월드로 변경해서 넣어줘야 한다.
		Data.Transform->SetWorldRotation(Rot.QuaternionToEulerDeg() + Data.OffsetRot);
		Data.Transform->SetWorldPosition(Pos + Data.OffsetPos);
	}
}

AnimationBoneData GameEngineFBXRenderer::GetBoneData(std::string _Name)
{
	Bone* BoneData = FBXMesh->FindBone(_Name);

	AnimationBoneData Data;

	if (nullptr == BoneData)
	{
		MsgAssert(std::string(_Name) + "존재하지 않는 본의 데이터를 찾으려고 했습니다.");
		return Data;
	}


	Data = GetBoneData(BoneData->Index);

	const TransformData& TransFormData = GetTransform()->GetTransDataRef();
	Data.Pos += TransFormData.LocalPosition;
	Data.RotEuler = Data.RotQuaternion.QuaternionToEulerDeg();

	return Data;
}

void GameEngineFBXRenderer::SetAttachTransform(std::string_view _Name, GameEngineTransform* _Transform, float4 _OffsetPos, float4 _OffsetRot)
{
	std::string UpperName = GameEngineString::ToUpper(_Name);

	Bone* BoneData = FBXMesh->FindBone(UpperName);

	if (nullptr == BoneData)
	{
		MsgAssert(std::string(_Name) + "존재하지 않는 본의 데이터를 찾으려고 했습니다.");
		return;
	}

	SetAttachTransform(BoneData->Index, _Transform, _OffsetPos, _OffsetRot);
}

void GameEngineFBXRenderer::SetAttachTransform(int Index, GameEngineTransform* _Transform, float4 _OffsetPos, float4 _OffsetRot)
{
	float4x4 Rot;
	float4x4 Pos;

	Rot.RotationDeg(_OffsetRot);
	Pos.Pos(_OffsetPos);

	// OffsetMat.Affine(float4(1.0f, 1.0f, 1.0f), _OffsetRot.EulerDegToQuaternion(), _OffsetPos);


	AttachTransformValue.push_back({ Index, _Transform, _OffsetPos, _OffsetRot, Rot * Pos });
}
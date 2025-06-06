#pragma once
#include <GameEngineBase/GameEngineMath.h>



// D3D11_INPUT_ELEMENT_DESC

class GameEngineInputLayOutInfo
{
public:
	static UINT FormatSize(DXGI_FORMAT _Format);

	inline const std::vector<D3D11_INPUT_ELEMENT_DESC>& GetDescs() 
	{
		return Descs;
	}

private:
	std::vector<D3D11_INPUT_ELEMENT_DESC> Descs;
	int Offset0 = 0;
	int Offset1 = 0;

public:
	void AddInputLayOut(
			LPCSTR SemanticName, // 내가 포지션이다 내가 컬러다.
			DXGI_FORMAT Format, // 내가 n바이트 짜리 정보다 자료형
			D3D11_INPUT_CLASSIFICATION InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA, // 버텍스 데이터가 인스턴싱 데이터다 라는걸 표현
			UINT InstanceDataStepRate = 0, // 나중에 나중에 인스턴싱이라는 구조를 배울때 쓸때가 있을것이다.
			UINT AlignedByteOffset = -1, // 0번째 바이트부터 
			UINT InputSlot = 0, // n개의 버텍스 버퍼를 세팅할때 n번째 버텍스 버퍼의 인풋 레이아웃이다 라는걸 표현하는것
			UINT SemanticIndex = 0
	);

};

// 설명 :
class GameEngineVertex
{
public:
	static GameEngineInputLayOutInfo LayOut;

public:
	float4 POSITION;
	float4 TEXCOORD;
	float4 COLOR;
	float4 NORMAL;
	float4 BINORMAL;
	float4 TANGENT;
	float4 WEIGHT; // 애니메이션 가중치
	int BLENDINDICES[4];
};

class GameEngineVertexParticle
{
public:
	static GameEngineInputLayOutInfo LayOut;

public:
	float4 POSITION;
	int PINDEX[4]; // x에 그냥 내가 0번이다 1번이다 2번이다
};


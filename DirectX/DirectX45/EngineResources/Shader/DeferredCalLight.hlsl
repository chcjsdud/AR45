#include "Transform.fx"
#include "Light.fx"
#include "RenderBaseValue.fx"

struct Input
{
    float4 POSITION : POSITION;
    float4 TEXCOORD : TEXCOORD;
};

struct Output
{
    float4 POSITION : POSITION;
    float4 TEXCOORD : TEXCOORD;
};

// ������� ���ؼ� ���� �ݻ縦 �����ϰ� ����
// �� ���� ����ϴ� ������ ���� �������� ������ �ߴ�.
// ������ ������ ���� �ǹ̰� ����.
// ���̶�� �÷��� ���س��� ���� �ȴ�.

// �װ� ���ؽ� ���̴������ϸ� �װ� �������� �ϸ� �÷����̵�
// �װ� ���ؽ� ���̴������ϸ� �װ� ��ν��̵�
// �װ� �ȼ� ���̴������ϸ� �װ� �����̵�

// �׷���ī�忡�� �̷����°�.
Output MeshAniTexture_VS(Input _Input)
{
    Output NewOutPut = (Output)0;
    NewOutPut.POSITION = _Input.POSITION;
    NewOutPut.TEXCOORD = _Input.TEXCOORD;
    return NewOutPut;
}

struct LightOutPut
{
    float4 DifLight : SV_Target0;
    float4 SpcLight : SV_Target1;
    float4 AmbLight : SV_Target2;
};

Texture2D PositionTex : register(t0);
Texture2D NormalTex : register(t1);
SamplerState POINTWRAP : register(s0);

LightOutPut MeshAniTexture_PS(Output _Input)
{
 
    LightOutPut NewOutPut = (LightOutPut) 0;
    
    float4 Position = PositionTex.Sample(POINTWRAP, _Input.TEXCOORD.xy);
    
    if (0 >= Position.a)
    {
        clip(-1);
    }
    
    float4 Normal = NormalTex.Sample(POINTWRAP, _Input.TEXCOORD.xy);
    
    float4 DiffuseRatio = (float4)0.0f;
    float4 SpacularRatio = (float4) 0.0f;
    float4 AmbientRatio = (float4) 0.0f;
    
    for (int i = 0; i < LightCount; ++i)
    {
        DiffuseRatio += CalDiffuseLight(Position, Normal, AllLight[i]);
        SpacularRatio += CalSpacularLight(Position, Normal, AllLight[i]);;
        AmbientRatio += CalAmbientLight(AllLight[i]);
    }
    
    return NewOutPut;
}


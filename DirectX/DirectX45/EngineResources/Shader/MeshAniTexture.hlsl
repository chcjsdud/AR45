#include "Transform.fx"
#include "Animation.fx"
#include "Light.fx"
#include "RenderBaseValue.fx"

struct Input
{
    float4 POSITION : POSITION;
    float4 TEXCOORD : TEXCOORD;
    float4 NORMAL : NORMAL;
    float4 TANGENT : TANGENT;
    float4 BINORMAL : BINORMAL;
    float4 BLENDWEIGHT : BLENDWEIGHT;
    int4 BLENDINDICES : BLENDINDICES;
};

struct Output
{
    // w������ ���ְ�
    // viewport ��ı��� �����Ͷ��������� �����ش�.
    float4 POSITION : SV_POSITION;
    float4 VIEWPOSITION : POSITION;
    float4 TEXCOORD : TEXCOORD;
    float4 NORMAL : NORMAL;
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
    
    float4 InputPos = _Input.POSITION;
    InputPos.w = 1.0f;
    
    float4 InputNormal = _Input.NORMAL;
    InputNormal.w = 0.0f;
    
    if (IsAnimation != 0)
    {
        Skinning(InputPos, _Input.BLENDWEIGHT, _Input.BLENDINDICES, ArrAniMationMatrix);
        // SkinningNormal(InputNormal, _Input.BLENDWEIGHT, _Input.BLENDINDICES, ArrAniMationMatrix);
        InputPos.w = 1.0f;
        InputNormal.w = 0.0f;
    }
    
    
    // �ڽ��� ���ð������� �ִϸ��̼��� ��Ű��
    // NewOutPut.POSITION = mul(_Input.POSITION, ArrAniMationMatrix[_Input.BLENDINDICES[0]].Mat);
    
    // �� 
    
    // ��ũ����ǥ�� �̴�.
    NewOutPut.POSITION = mul(InputPos, WorldViewProjectionMatrix);
    NewOutPut.TEXCOORD = _Input.TEXCOORD;
    
    // ������� �ϱ� ���� �������̹Ƿ� �̳༮�� ������� �־�� �Ѵ�.
    NewOutPut.VIEWPOSITION = mul(InputPos, WorldView);
    _Input.NORMAL.w = 0.0f;
    NewOutPut.NORMAL = mul(InputNormal, WorldView);
    
    return NewOutPut;
}

Texture2D DiffuseTexture : register(t0);
SamplerState ENGINEBASE : register(s0);

struct OutTarget
{
    float4 CamForwardTarget : SV_Target0;
    float4 TestTarget : SV_Target5;
};

OutTarget MeshAniTexture_PS(Output _Input)
{
    OutTarget NewOutPut = (OutTarget) 0;
    
    // ��ǻ���÷�
    float4 Color = DiffuseTexture.Sample(ENGINEBASE, _Input.TEXCOORD.xy);
    
    // ��ǻ�� ����Ʈ
    
    if (Color.a <= 0.0f)
    {
        clip(-1);
    }
    
    float4 DiffuseRatio = (float4) 0.0f;
    float4 SpacularRatio = (float4) 0.0f;
    float4 AmbientRatio = (float4) 0.0f;
    
    for (int i = 0; i < LightCount; ++i)
    {
        DiffuseRatio += CalDiffuseLight(_Input.VIEWPOSITION, _Input.NORMAL, AllLight[i]);
        SpacularRatio += CalSpacularLight(_Input.VIEWPOSITION, _Input.NORMAL, AllLight[i]);;
        AmbientRatio += CalAmbientLight(AllLight[i]);
    }
    
    float A = Color.w;
    float4 ResultColor = (float4) 0.0f;
    ResultColor.xyz = Color.xyz * (DiffuseRatio.xyz + SpacularRatio.xyz + AmbientRatio.xyz);
    ResultColor.a = A;
    Color += AllLight[0].LightColor;
    
    NewOutPut.CamForwardTarget = ResultColor;
    NewOutPut.TestTarget = ResultColor;
    
    return NewOutPut;
}


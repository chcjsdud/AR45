#include "Light.fx"

struct Input
{
    float4 POSITION : POSITION;
    float4 TEXCOORD : TEXCOORD;
};

struct Output
{
    float4 POSITION : SV_Position;
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
Output DeferredPostLight_VS(Input _Input)
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

Texture2D DifLightTex : register(t0);
Texture2D SpcLightTex : register(t1);
Texture2D AmbLightTex : register(t2);
Texture2D ShadowTestTex : register(t4);
SamplerState POINTWRAP : register(s0);

LightOutPut DeferredPostLight_PS(Output _Input) 
{
    LightOutPut NewOutPut = (LightOutPut) 0;
    
    float4 Shadow = ShadowTestTex.Sample(POINTWRAP, _Input.TEXCOORD.xy);
    
    NewOutPut.DifLight = DifLightTex.Sample(POINTWRAP, _Input.TEXCOORD.xy);
    NewOutPut.SpcLight = SpcLightTex.Sample(POINTWRAP, _Input.TEXCOORD.xy);
    NewOutPut.AmbLight = AmbLightTex.Sample(POINTWRAP, _Input.TEXCOORD.xy);
    
    if (0 != Shadow.x)
    {
        NewOutPut.DifLight = 0.2f / Shadow.x;
        NewOutPut.SpcLight = 0.2f / Shadow.x;
    }
    
    return NewOutPut;
}


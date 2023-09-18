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
Output DeferredCalLight_VS(Input _Input)
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
    float4 ResultLight : SV_Target3;
};

Texture2D PositionTex : register(t0);
Texture2D NormalTex : register(t1);
Texture2D ShadowTex : register(t2);
SamplerState POINTWRAP : register(s0);

LightOutPut DeferredCalLight_PS(Output _Input) : SV_Target0
{
    LightOutPut NewOutPut = (LightOutPut) 0;
    
    // ���� => ���� => �� => �������� => ����Ʈ
    // Position
    float4 Position = PositionTex.Sample(POINTWRAP, _Input.TEXCOORD.xy);
    
    if (0 >= Position.a)
    {
        clip(-1);
    }
    
    float4 Normal = NormalTex.Sample(POINTWRAP, _Input.TEXCOORD.xy);
    
    float4 DiffuseRatio = (float4) 0.0f;
    float4 SpacularRatio = (float4) 0.0f;
    float4 AmbientRatio = (float4) 0.0f;
    
    for (int i = 0; i < LightCount; ++i)
    {
        DiffuseRatio += CalDiffuseLight(Position, Normal, AllLight[i]);
        SpacularRatio += CalSpacularLight(Position, Normal, AllLight[i]);;
        AmbientRatio += CalAmbientLight(AllLight[i]);
    }
    
    // ����� ����Ʈ�� ������ ���̶��
    if (DiffuseRatio.x > 0.0f)
    {
        float4 WorldViewPos = Position;
        WorldViewPos.a = 1.0f;
        // ���������ϹǷ�
        // �׸��ڵ� �����ؾ����� �Ǵ��Ѵ�.
        // ��� world 
        float4 WorldPos = mul(WorldViewPos, AllLight[0].CameraViewInverseMatrix);
        
        // ���� ���������� ���������� �ٲ��.
        float4 LightPos = mul(WorldPos, AllLight[0].LightViewProjectionMatrix);
        
        // worldviewprojection 
        // �� �������� �װ� -1~1������ �����Դϱ�?
        // w�� ������������ z���� ������ ���� ���� �˴ϴ�.
        float3 LightProjection = LightPos.xyz / LightPos.w;
        // ��� ���� -1~1������ ���� �˴ϴ�.
        
        float2 ShadowUV = float2(LightProjection.x * 0.5f + 0.5f, LightProjection.y * -0.5f + 0.5f);
        float fShadowDepth = ShadowTex.Sample(POINTWRAP, float2(ShadowUV.x, ShadowUV.y)).r;
        
        // ���� �ܰ��� �ణ ��Ƴ��� 
        if (
            0.001f < ShadowUV.x && 0.999f > ShadowUV.x
            && 0.001f < ShadowUV.y && 0.999f > ShadowUV.y
            && LightProjection.z >= (fShadowDepth + 0.001f)
            )
        {
            DiffuseRatio *= 0.01f;
            SpacularRatio *= 0.01f;
        }
        
    }
    
    NewOutPut.DifLight = DiffuseRatio;
    NewOutPut.SpcLight = SpacularRatio;
    NewOutPut.AmbLight = AmbientRatio;
    NewOutPut.ResultLight = DiffuseRatio + SpacularRatio + AmbientRatio;
    
    // ī�޶� ���
    // ���� ��ġ
    // �׷����ִ� ���� ��������� ���� ���� �ؽ�ó.

    
    return NewOutPut;

    //NewOutPut.DifLight = float4(1.0f, 0.0f, 0.0f, 1.0f);
    //NewOutPut.SpcLight = float4(0.0f, 1.0f, 0.0f, 1.0f);
    //NewOutPut.AmbLight = float4(0.0f, 0.0f, 1.0f, 1.0f);
    
    // return NewOutPut;

}


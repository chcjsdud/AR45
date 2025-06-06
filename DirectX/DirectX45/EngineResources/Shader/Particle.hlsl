#include "Transform.fx"
#include "ParticleHeader.fx"

cbuffer ParticleInfo : register(b7)
{
    float4 StartScale;
    float4 EndScale;
    float4 StartColor;
    float4 EndColor;
};

// 스트럭처드 버퍼를 만듭니다.
// 개수만큼의 버퍼가 필요하다.
StructuredBuffer<ParticleData> ParticleBuffer : register(t12);

struct VS_IN
{
    float4 vPos : POSITION;
    // 이녀석은 내가 몇번째 버텍스 버퍼인지 들어옵니다.
    uint iInstance : SV_InstanceID;
};

struct VS_OUT
{
    float4 vLocalPos : POSITION;
    uint iInstance : SV_InstanceID;
};

VS_OUT ParticleRender_VS(VS_IN _in)
{
    VS_OUT output = (VS_OUT) 0.f;
    output.vLocalPos = _in.vPos;
    output.iInstance = _in.iInstance;
    return output;
}

struct GS_OUT
{
    float4 vPosition : SV_Position;
    float4 vUV : TEXCOORD;
    uint iInstance : SV_InstanceID;
};

[maxvertexcount(6)]
void ParticleRender_GS(point VS_OUT _in[1], inout TriangleStream<GS_OUT> _OutStream)
{
    GS_OUT output[4] = { (GS_OUT) 0.f, (GS_OUT) 0.f, (GS_OUT) 0.f, (GS_OUT) 0.f };
    
    if (0 == ParticleBuffer[_in[0].iInstance].iActive)
        return;
   
    float3 vWorldPos = _in[0].vLocalPos.xyz + ParticleBuffer[_in[0].iInstance].vRelativePos.xyz;
    
    // 파티클 쉐이더를 만들었을때 기준인데. 
    //if (0 == IsWorldSpawn)
    //{
    //    vWorldPos += g_matWorld._41_42_43;
    //}
    
    float3 vViewPos = mul(float4(vWorldPos, 1.f), View).xyz;

    
    // 수명 비율
    float fRatio = ParticleBuffer[_in[0].iInstance].fCurTime / ParticleBuffer[_in[0].iInstance].fMaxTime;
    float3 vScale = lerp(StartScale.xyz, EndScale.xyz, fRatio);
    
    // float3 vScale = float3(100.0f, 100.0f, 1.0f);
    
    float3 NewPos[4] =
    {
        vViewPos - float3(-0.5f, 0.5f, 0.f) * vScale,
        vViewPos - float3(0.5f, 0.5f, 0.f) * vScale,
        vViewPos - float3(0.5f, -0.5f, 0.f) * vScale,
        vViewPos - float3(-0.5f, -0.5f, 0.f) * vScale
    };
    
    for (int i = 0; i < 4; ++i)
    {
        output[i].vPosition = mul(float4(NewPos[i], 1.f), Projection);
        output[i].iInstance = _in[0].iInstance;
    }
    
    
    output[3].vUV.xy = float2(0.f, 0.f);
    output[2].vUV.xy = float2(1.f, 0.f);
    output[1].vUV.xy = float2(1.f, 1.f);
    output[0].vUV.xy = float2(0.f, 1.f);
       
    
    // 0 -- 1
    // | \  |
    // 3 -- 2
    _OutStream.Append(output[0]);
    _OutStream.Append(output[1]);
    _OutStream.Append(output[2]);
    _OutStream.RestartStrip();
    
    _OutStream.Append(output[0]);
    _OutStream.Append(output[2]);
    _OutStream.Append(output[3]);
    _OutStream.RestartStrip();
}

Texture2D DiffuseTexture : register(t0);
SamplerState ENGINEBASE : register(s0);

float4 ParticleRender_PS(GS_OUT _in) : SV_Target
{
    float4 vColor = (float4) 0.f;
        
    vColor = DiffuseTexture.Sample(ENGINEBASE, _in.vUV.xy);
    
    // float fRatio = ParticleBuffer[_in.iInstance].fCurTime / ParticleBuffer[_in.iInstance].fMaxTime;
    vColor.rgb *= lerp(StartColor, EndColor, 1.0f).rgb;
    
    
    return vColor;

}
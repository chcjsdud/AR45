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

// 빛계산을 통해서 빛의 반사를 구현하고 나면
// 그 빛을 계산하는 시점에 따라서 예전에는 구분을 했다.
// 이제는 구분이 거의 의미가 없다.
// 빛이라는 컬러를 구해내는 것이 된다.

// 그걸 버텍스 쉐이더에서하면 그걸 점단위로 하면 플랫쉐이딩
// 그걸 버텍스 쉐이더에서하면 그걸 고로쉐이딩
// 그걸 픽셀 쉐이더에서하면 그걸 퐁쉐이딩

// 그래픽카드에서 이뤄지는것.
Output DeferredMerge_VS(Input _Input)
{
    Output NewOutPut = (Output)0;
    NewOutPut.POSITION = _Input.POSITION;
    NewOutPut.TEXCOORD = _Input.TEXCOORD;
    return NewOutPut;
}

struct OutPutColor
{
    float4 Result : SV_Target0;
};

Texture2D DifColor : register(t0);
Texture2D DifLight : register(t1);
Texture2D SpcLight : register(t2);
Texture2D AmbLight : register(t3);
SamplerState POINTWRAP : register(s0);

OutPutColor DeferredMerge_PS(Output _Input) : SV_Target0
{
 
    OutPutColor NewOutPut = (OutPutColor) 0;
    
    float4 Color = DifColor.Sample(POINTWRAP, _Input.TEXCOORD.xy);
    
    //if (0 >= Color.a)
    //{
    //    clip(-1);
    //}
    
    float4 DiffuseRatio = DifLight.Sample(POINTWRAP, _Input.TEXCOORD.xy);
    float4 SpacularRatio = SpcLight.Sample(POINTWRAP, _Input.TEXCOORD.xy);
    float4 AmbientRatio = AmbLight.Sample(POINTWRAP, _Input.TEXCOORD.xy);
    
    
    //if (내 앞에 물체가 있다면)
    //{
    //     DiffuseRatio.xyz *= 0.01f;
    //     SpacularRatio.xyz *= 0.01f;
    //     AmbientRatio.xyz *= 0.01f;
    //    나의 빛은 약해져야 한다.
    //}
        
    
        if (Color.a)
        {
        //      0.1f
            NewOutPut.Result.xyz = Color.xyz * (DiffuseRatio.xyz + SpacularRatio.xyz + AmbientRatio.xyz);
            NewOutPut.Result.a = saturate(Color.a + (DiffuseRatio.w + SpacularRatio.w + AmbientRatio.w));
            NewOutPut.Result.a = 1.0f;
        }
        else
        {
            NewOutPut.Result.xyz = (DiffuseRatio.xyz + SpacularRatio.xyz + AmbientRatio.xyz);
            NewOutPut.Result.a = saturate(NewOutPut.Result.x);
        }
    // NewOutPut.Result.a = saturate(NewOutPut.Result.a);
    
    return NewOutPut;

    //NewOutPut.DifLight = float4(1.0f, 0.0f, 0.0f, 1.0f);
    //NewOutPut.SpcLight = float4(0.0f, 1.0f, 0.0f, 1.0f);
    //NewOutPut.AmbLight = float4(0.0f, 0.0f, 1.0f, 1.0f);
    
    // return NewOutPut;

}


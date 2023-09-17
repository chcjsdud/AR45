#include "Transform.fx"

struct Input
{
    float4 POSITION : POSITION;
};

struct Output
{
    float4 POSITION : SV_POSITION;
    float4 Pos5 : POSITION5;
};

Output Shadow_VS(Input _Value)
{
    Output NewOutPut = (Output) 0;
    float4 InputPos = _Value.POSITION;
    InputPos.w = 1.0f;
    NewOutPut.POSITION = mul(InputPos, WorldViewProjectionMatrix);
    NewOutPut.Pos5 = NewOutPut.POSITION;
    
    return NewOutPut;
}

float4 Shadow_PS(Output _Value) : SV_Target0
{
    // 깊이값이 완성된
    return float4(abs(_Value.Pos5.z / _Value.Pos5.w), 0.0f, 0.0f, 1.0f);
}
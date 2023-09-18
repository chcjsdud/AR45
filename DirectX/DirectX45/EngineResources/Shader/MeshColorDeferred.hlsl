#include "Transform.fx"
#include "Animation.fx"
#include "Light.fx"
#include "RenderBaseValue.fx"

struct Input
{
    float4 POSITION : POSITION;
    float4 TEXCOORD : TEXCOORD;
    float4 NORMAL : NORMAL;
};

struct Output
{
    // w������ ���ְ�
    // viewport ��ı��� �����Ͷ��������� �����ش�.
    float4 POSITION : SV_POSITION;
    float4 VIEWPOSITION : POSITION0;
    float4 WVPPOSITION : POSITION5;
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
Output MeshColorDeferred_VS(Input _Input)
{
    Output NewOutPut = (Output)0;
    
    float4 InputPos = _Input.POSITION;
    InputPos.w = 1.0f;
    
    float4 InputNormal = _Input.NORMAL;
    InputNormal.w = 0.0f;
    
    // ��ũ����ǥ�� �̴�.
    NewOutPut.POSITION = mul(InputPos, WorldViewProjectionMatrix);
    NewOutPut.VIEWPOSITION = mul(InputPos, WorldView);
    NewOutPut.WVPPOSITION = NewOutPut.POSITION;
    _Input.NORMAL.w = 0.0f;
    NewOutPut.NORMAL = mul(InputNormal, WorldView);
    
    return NewOutPut;
}

struct DeferredOutPut
{
    // float4 CamForwardTarget : SV_Target0;
    float4 DifTarget : SV_Target1;
    float4 PosTarget : SV_Target2;
    float4 NorTarget : SV_Target3;
};

DeferredOutPut MeshColorDeferred_PS(Output _Input)
{
    DeferredOutPut NewOutPut = (DeferredOutPut) 0;
    
    // ��ǻ���÷�
    NewOutPut.DifTarget = BaseColor;
    NewOutPut.PosTarget = _Input.VIEWPOSITION;
    _Input.NORMAL.a = 1.0f;
    NewOutPut.NorTarget = _Input.NORMAL;
    
    return NewOutPut;

}


struct ParticleData
{
    // ���� ��ġ
    float4 vRelativePos;
    // ��ƼŬ�� ����
    float4 vDir;
		
    // �ð� ������½ð�
    float fMaxTime;
    // ���� �ð�
    float fCurTime;
    // �̵��Ҷ��� ���ǵ�
    float fSpeed;
    // ����ֳ� �׾��ֳ�.
    uint iActive;
};

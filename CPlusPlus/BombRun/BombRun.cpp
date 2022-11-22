// BombRun.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    char Arr[24][20] = {
        "민경운(MKU)",
        "허동석(HDS)",
        "김정민(KJM)",
        "황승민(HSM)",
        "김태민(KTM)",
        "서범진(SBJ)",
        "유동민(YDM)",
        "윤주익(YJK)",
        "전연호(JYH)",
        "엄태건(UTG)",
        "김경식(KKS)",
        "최상진(CSJ)",
        "신원석(SWS)",
        "오지원(OJW)",
        "김예영(KYY)",
        "최지혜(CJH)",
        "김유경(KYK)",
        "황동찬(HDC)",
        "이광섭(LKS)",
        "오재원(WON)",
        "오의현(OEH)",
        "김경학(KKH)",
        "이수정(LSJ)",
    };

    srand(time(0));

    char* SelectName = Arr[rand() % 24];

    printf_s("축하드립니다!!!! %s 가 선택되었습니다.", SelectName);
}

// 25.MultiDimensionArray.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    {
        // int[] 형
        // int* == int[] 똑같다
        // 그냥 완전히 틀렸다.
        int Arr[2];
        // 100번지
        // Arr[0] 100번지
        // Arr[1] 104번지

        int* Ptr = Arr;

        Ptr[0];
        *(Ptr + 0) = 20;
    }

    {
        int Arr[2][2];

        Arr[0][0] = 0;
        Arr[0][1] = 1;
        Arr[1][0] = 2;
        Arr[1][1] = 3;

        __int64 Address00 = (__int64)&Arr[0][0];
        __int64 Address01 = (__int64)&Arr[0][1];
        __int64 Address10 = (__int64)&Arr[1][0];
        __int64 Address11 = (__int64)&Arr[1][1];

        // [Arr[0]][Arr[1]]

        // [00][01][10][11]

        int* Ptr = &Arr[0][0];

        int Value0 = Ptr[0];
        int Value1 = Ptr[1];
        int Value2 = Ptr[2];
        int Value3 = Ptr[3];

        int a = 0;

        // 100번지
        // Arr[0] 100번지
        // Arr[1] 104번지

        // 0, 0, 0, 0

        // 0, 0,
        // 0, 0
    }

    // char Arr[20] = "민경운(MKU)";

    // 최초에 한번만 가능합니다.
    int ArrInt[10][10] = {1, 2, 3, 4, 5};

    // ArrInt == int[]
    // ArrInt[0] == int

    // int* Ptr;
    // *Ptr == int


    // ArrInt = { 1, 2, 3, 4, 5 };

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

    char* NamePtr0 = Arr[0];
    char* NamePtr1 = Arr[1];

    // printf_s(NamePtr0);

    printf_s("이름 %s", NamePtr0);

    //char ArrName[20] = "민경운(MKU)";
    //char* Name = ArrName;

    // Arr[0] == char[]

    // char[]
    // Arr[0] == char[]

    //       25명의 이름
    // char Arr[24][20]
}

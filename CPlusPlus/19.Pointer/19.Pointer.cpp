// 19.Pointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void Test1() 
{
    int Value0;
    int Value1;
    int Value2;

    unsigned __int64 Address0 = (__int64)&Value0;
    unsigned __int64 Address1 = (__int64)&Value1;
    unsigned __int64 Address2 = (__int64)&Value2;
}

void Test() 
{
    int Value0;
    int Value1;
    int Value2;

    unsigned __int64 Address0 = (__int64)&Value0;
    unsigned __int64 Address1 = (__int64)&Value1;
    unsigned __int64 Address2 = (__int64)&Value2;

    int a = 0;

    Test1();
}

int main()
{
    {
        // 100번지
        int Value0 = 10;
        // 0b100010000000000000000000000000001

        // 200번지
        int Value1 = 20;

        // 변수의 앞에 & 연산자를 사용하면
        // 그 변수의 위치를 리턴해달라는 단항 연산자가 된다.

        // 300번지
        int* Ptr0 = &Value0;

        // 
        bool* Ptr;

        // int*형입니다.
        // 인트 포인터 형

        int PointerSize = sizeof(bool*);

        // char aaa = 'a';


        // 어느위치에 간섭하겠다.
        // Value = 20;


        // 64비트 정수형
        // signed __int64;
        // 이걸로 바꾸겠다.
        unsigned __int64 AAA = (__int64)Ptr0;
    }
 
    {
        // 포인터를 통해서 실제 진짜 주소의 위치를 눈으로 볼수있게 됩니다.

        int Value0;
        int Value1;
        int Value2;

        unsigned __int64 Address0 = (__int64)&Value0;
        unsigned __int64 Address1 = (__int64)&Value1;
        unsigned __int64 Address2 = (__int64)&Value2;

        Test();

        int a = 0;
    }

}
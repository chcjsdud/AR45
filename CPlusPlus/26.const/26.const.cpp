// 26.const.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void Damage(const int* Att, int* Hp)
{
    *Hp -= *Att;

    // *Att += 10;
}

void MyPrint(const char* Ptr) 
{
    // Ptr[0] = 'c';

    printf_s(Ptr);
}

void ChangeInt(int* Ptr)
{
    *Ptr = 3000;
}

int main()
{
    {
        const int Value = 100;
        // int* Ptr = &Value;
        // *Ptr = 200;

        int Value0 = 100;
        int Value1 = 100;
        const int* const Ptr0 = &Value1;
        // Ptr0 = &Value0;
        int* Ptr1 = &Value1;

    }

    {
        char Ptr[20] = { "abcdefg" };
        MyPrint(Ptr);
    }

    {
        int Att = 10;
        int Hp = 100;

        Damage(&Att, &Hp);
    }

    // 특정 메모리 영역의 비트를 상수화 시키는 문법입니다.
    // 자료형 앞에 const 를 붙여주면 됩니다.

    // 초기화를 하지 않으면 어떤 숫자가 될지 알수가 없다.
    const int Value = 1;
    // 000....1

    if (Value == 0)
    {

    }

    int Value0 = 0;
    int Value1 = 0;
    int Value2 = 0;
    const int Value3 = 0;

    __int64 AddRess0 = (__int64)&Value0;
    __int64 AddRess1 = (__int64)&Value1;
    __int64 AddRess2 = (__int64)&Value2;
    __int64 AddRess3 = (__int64)&Value3;

    __int64 AddRess4 = (__int64)&Value;

    int a = 0;

    // 뒤에 붙이는 짓은 하지 않겠습니다.
    int const BackConst = 20;

    // BackConst = 20;

    // const int const

    {
        const int;
        const int* Ptr = &Value2;
        // 위치 : 200번지
        // 크기 : 8바이트
        // 형태 : const int의 주소값
        // 값 : 100번지

        Ptr = &Value3;

        // const int
        // *Ptr = 20;
    }

    {
        const int;
        const int* const Ptr = &Value2;
        // 위치 : 200번지
        // 크기 : 8바이트
        // 형태 : const int의 주소값
        // 값 : 100번지

        // 주소값을 못바꾸니까.
        // Ptr = &Value3;
    }

    {
        const int;
        int* const Ptr = &Value2;
        // 위치 : 200번지
        // 크기 : 8바이트
        // 형태 : const int의 주소값
        // 값 : 100번지

        // 주소값을 못바꾸니까.
        // Ptr = &Value3;

        // int
        *Ptr = 20;
    }

    {
        const int;
        // int* const * const * const Ptr = &Value2;
        // 위치 : 200번지
        // 크기 : 8바이트
        // 형태 : const int의 주소값
        // 값 : 100번지

        // 주소값을 못바꾸니까.
        // Ptr = &Value3;

        // int
        // *Ptr = 20;
    }

    // 어디에 존재하는 
    // 코드영역에 있는 const char[]
    // char* != char[] 절대로 안됀다고 했죠.
    // char* = char[] 대입은 

    //           const char[]
    const char* Test = "aaaaa";

    //printf_s(Test);

}

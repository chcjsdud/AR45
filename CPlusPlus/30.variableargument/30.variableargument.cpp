// 30.variableargument.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//        100         108  116
void Test(int Value0, int, const char*)
{
    // 100
    int* StartAddress = &Value0;

    printf_s("%d, %d, %d\n", StartAddress[0], StartAddress[2], StartAddress[4]);

    return;

    printf_s("%lld\n", (__int64)&Value0);
    //printf_s("%lld\n", (__int64)&Value1);
    //printf_s("%lld\n", (__int64)&Value2);

}

void PrintNumber(int Count, ...)
{
    // 100
    int* StartAddress = &Count;
    StartAddress += 2;

    for (unsigned int i = 0; i < Count; i++)
    {
        printf_s("%d\n", StartAddress[i * 2]);
    }
}

//void PrintNumber(int Count, int, int)
//{
//    // 100
//    int* StartAddress = &Count;
//    StartAddress += 2;
//
//    for (unsigned int i = 0; i < Count; i++)
//    {
//        printf_s("%d\n", StartAddress[i * 2]);
//    }
//}

int StringCount() 
{

}

int Test(const char* const Text, ...) 
{

}


int main()
{
    char arr[10] = "aaabbccc";

    PrintNumber(5, 10, 20);

    // Test(1000, 200, 300);

    // 64비트 정수를 출력한다.

    //__int64 aaa = 378912378921738921;
    printf_s("%d, %d", 10, 'a');


}

// MyPrintf.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

// int MyPrintF(const char* const _Text, ...)

int MyPrintF(const char* const _Text, ...) 
{
    char* CurParameter = (char*)&_Text;
    CurParameter += 8;

    // 012345678 
    // Text : %s

    int Count = 0;
    while (0 != _Text[Count])
    {
        char CurChar = _Text[Count];
        if ('%' == _Text[Count])
        {
            char NextChar = _Text[Count + 1];

            switch (NextChar)
            {
            case 's':
            {
                const char** NextValue = (const char**)CurParameter;
                const char* Value = *NextValue;

                int StringCount = 0;
                while (0 != Value[StringCount])
                {
                    char StringChar = Value[StringCount];

                    _putch(Value[StringCount]);
                    StringCount += 1;
                }

                Count += 2;
                break;
            }
            default:
                break;
            }
            
            
        }
        else
        {
            _putch(_Text[Count]);
            Count += 1;
        }
    }

    return 0;
}

//            100         108
int TestValue(int _Text, ...)
{
    //    100번지
    char* Ptr = (char*)&_Text;
    Ptr += 8;

    *Ptr;

    int* NextValue = (int*)Ptr;

    int Value = *NextValue;


    int a = 0;

    return 0;
}

int main()
{
    TestValue(9, 20, 20, 30, 40, 50, 60);

    // MyPrintF(20);

    // _putch('a');

    // printf_s("fadsfasd");

    char Arr[10] = { "aaaaaaaaa" };
    // Arr[9] = 'a';
    MyPrintF("Text : %s\n", "aa");
    printf_s("Text : %s\n", "aa");

}

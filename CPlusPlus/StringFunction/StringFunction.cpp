// StringFunction.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int StringCount(const char* _String) 
{
    int Count = 0;

    while(0 != _String[Count])
    {
        ++Count;
    }

    return Count;
}

bool StringCompair(const char* _Text0, const char* _Text1)
{
    return false;// 둘이 같다면 true, 둘이 틀리면 false
}

void StringMerge(char* _Realut, const char* _Text1, const char* _Text0)
{
    return;// 둘이 같다면 true, 둘이 틀리면 false
}


void StringChange(char* _Text, const char* Old, const char* New) 
{

}

void StringChangeEx(char* _Text, const char* Old, const char* New)
{

}

int NumberCount(int Number)
{
    return 0;
}

void NumberToString(char* Arr, int ArrSize, int Number)
{

}

int main()
{
    // 글자수 새기
    {
        char Arr[10] = { "aaaaaa" };
        // Arr[9] = 'a';
        Arr[5] = 0;

        int Len0 = StringCount(Arr);

        printf_s(Arr);
    }

    {
        // 내일꼭 continue break

        char Arr[20] = "aaa";
        {
            bool result = StringCompair(Arr, "bbb");

            int a = 0;
        }

        {
            bool result = StringCompair(Arr, "aaa");

            int a = 0;
        }


    }

    {
        char Arr[100] = "";
        StringMerge(Arr, "test", " Game");
        // Arr = "test Game"
    }

    {
        // 알파뱃
        char Arr[20] = "aaa bbb ccc";
        StringChange(Arr, "bbb", "qqq");
    }

    {
        // 알파뱃
        char Arr[20] = "aaa bbb ccc";
        StringChangeEx(Arr, "bbb", "q");
    }


    {
        int Count = NumberCount(122);
        int Value = 0;
    }

    {
        char Arr[50];
        NumberToString(Arr, 50, 321312);
        // '3''2''1''3''1''2'0
        printf_s(Arr);

        // Arr;

        // [1][2][3][4][1][2][3]

    }

}

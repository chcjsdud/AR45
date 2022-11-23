// StringFunction.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int StringCount(const char* _String) 
{
    char Value0 = _String[0];
    char Value1 = _String[1];
    char Value2 = _String[2];
    char Value3 = _String[3];
    char Value4 = _String[4];

}

int main()
{
    int Len0 = StringCount("aaaaa");
    int Len1 = StringCount("fasdjklfasd");
    int Len2 = StringCount("wew00000");
    int Len3 = StringCount("gnvmkv");

    std::cout << "Hello World!\n";
}

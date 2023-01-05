// 85.StringEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <Windows.h>
#include <string_view>


#define MsgAssert(MsgText) std::string ErrorText = MsgText; MessageBoxA(nullptr, ErrorText.c_str(), "Error", MB_OK);

int main()
{
    std::string_view Text0 = "aaa";
    std::string_view Text1 = "bbb";

    std::string ErrorText = Text0.data();

    Text0 + "aaaaa";


    // std::string Result = Text0 + " : " + 1;

    MsgAssert(Text0 + " : " + 1);

    // char*
    // MsgAssert(Text0 + "aaaaaa");
    // std::string ErrorText = MsgText; MessageBoxA(nullptr, ErrorText.c_str(), "Error", MB_OK);


    // "adfasdfas" + "ffff";

    // std::cout << "Hello World!\n" + "aaaaa";
}

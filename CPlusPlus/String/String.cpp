// String.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <string_view>

void TextFunctionBad(std::string _Text)
{

}

void TextFunction(const std::string& _Text) 
{

}

// 값형으로 넘겨도 8바이트 복사이다.
// 이녀석이 내부에 들고 있는것은 
// 8바이트 const char*를 들고 있습니다.
void TextFunctionView(const std::string_view& _Text)
{

}

class MyString 
{
    char* StringPtr;

public:
    MyString(const char* Text) 
    {
        int Size = strlen(Text);

        StringPtr = new char[Size];

        strcpy_s(StringPtr, Size, Text);
    }
};

class MyStringView
{
    const char* StringPtr;

public:
    MyStringView(const char* Text)
    {
        StringPtr = Text;
    }
};


void TextFunctionMy(const MyStringView& _Text)
{

}

//"철검 강화 1단계"
//"철검 강화 1단계"
//"철검 강화 1단계"
//"철검 강화 1단계"
//"철검 강화 1단계"
//"철검 강화 1단계"
//"철검 강화 1단계"

int main()
{
    //char* NewChar = new char[256] {"철검 강화 1단계"};

    //NewChar[8] = '2';
    // TextFunctionMy("aaaaaa");

    // 자기만의 6개의 std::vector<char>
    std::string FirstText = "ㄻㅇㄴㄹ몬어ㅏㅣㄻㄴ오허ㅏㅣㄻㄴ오ㅓㅏㅣㄻㄴ오ㅓㅏㅣㄻㄴ오ㅓㅏ림ㄴ오ㅓㅏㅣㄻㄴ오ㅓㅏㅣㄻㄴ오ㅓㅏㅣㄻㄴㅇ";
    std::string SecondText = "Weapon";

    // const char* Ptr = "abcde";

    std::string Result = FirstText + SecondText;

    std::string ThText = SecondText;

    TextFunction(FirstText);

    TextFunction("로머ㅏㅇㄴ로마ㅓㄴ;이로머ㅏ니롬ㄴ어ㅏㅣ론ㅁ어ㅏㅣ론어마ㅣ롬나어ㅣ로마너이롬너아ㅣ");

    TextFunctionView("Test");

    std::string WeaponName = "철검";

    WeaponName += "강화";

    int Weaponupgrade = 4;

    WeaponName += Weaponupgrade + '0';


    if (std::string::npos == WeaponName.find("fasdfasdfasd"))
    {
        int a = 0;

    }
}



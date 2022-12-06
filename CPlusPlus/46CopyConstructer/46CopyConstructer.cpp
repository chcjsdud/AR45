// 46CopyConstructer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Test 
{
private: // 디폴트 접근제한 지정자

public:
    // 디폴트 대입 연산자
    Test& operator=(const Test& _Other) 
    {
        return *this;
    }

    // 디폴트 RValue 대입연산자
    Test& operator=(Test&& _Other) noexcept
    {
        return *this;
    }


public:
    // 디폴트 생성자
    Test() 
    {
    }

    // 디폴트 복사생성자
    Test(const Test& _Other) 
    {
    }

    // 디폴트 RValue 생성자 => 지금 물어보지 마라.
    Test(Test&& _Other) noexcept
    {
    }

    // 디폴트 소멸자
    ~Test() 
    {

    }
};

class Test2
{

};

int main()
{
    {
        // 자기 자신을 인자로 받는 생성자도 무조건 만들어 진다.
        Test New000 = Test();
        Test New001 = Test(New000);

        New000 = New001;
    }

    {
        // 자기 자신을 인자로 받는 생성자도 무조건 만들어 진다.
        Test2 New000 = Test2();
        Test2 New001 = Test2(New000);

        New000 = New001;
    }

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

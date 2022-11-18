// 21.nullptr.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    // 내가 어떤 포인터를 사용하고 싶어서 선언했어.
    // 이녀석에 초기값은 대부분의 프로그래머가
    // C에서 온 녀석이기 때문입니다.
    // c는 기본적으로 주소값을 정수라고 

    // 포인터를 사용하지 않는 다는 의미를 0으로 표현했다.
    // 5버전부터
    // int* Ptr = 0;

    // nullptr포인터형 상수
    // 모든 포인터에 다 들어갈수 있습니다.
    int* Ptr = nullptr;

    if (nullptr != Ptr)
    {
        *Ptr = 100;
    }

    int Value = 999;

    Ptr = &Value;

    if (nullptr != Ptr)
    {
        *Ptr = 100;
    }

    int a = 0;
}

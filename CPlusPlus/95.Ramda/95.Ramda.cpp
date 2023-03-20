// 95.Ramda.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <functional>

void TestFunction() 
{
}


int main()
{
    //[람다캡쳐, 캡처의 참조형식을 의미하게 된다 & = ](인자)
    //{
    //};

    // 람다 캡쳐는 외부에 있는 변수를 캡쳐해서 가져온다는 뜻이다.
    int Test = 50;

    int a = 20;

    int b = 20;

    __int64 aAddRess = (__int64)& a;

    int* IntPtr = &a;

    std::function<void(int)> Ptr = [a, &b](int _Value)
    {
        int TestValue = a;
        __int64 aAddRess = (__int64)&a;
        // int a = 50;

        int b = 0;
    };

    std::function<void(int)> Ptr0 = [&](int _Value)
    {
        *IntPtr = 50;
    };


    Ptr(20);


    std::cout << "Hello World!\n";
}

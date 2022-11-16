// 17.For.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int Start() 
{
    printf_s("초기화문\n");
    return 0;
}

int Check()
{
    printf_s("조건문\n");
    return 0;
}

int PlusMinus()
{
    printf_s("증감문\n");
    return 0;
}

int Job()
{
    printf_s("실행코드\n");
    return 0;
}

int main()
{
    // 정수하나를 초기화하기 위해서 초기화문을 사용하고
    // 그걸 검사하고
    // true라면 내가 할일을 실행한다음
    // 
    //for (
    //    int i = Start();
    //    Check(), i < 100; 
    //    PlusMinus(), i++
    //    )
    //{
    //    Job();
    //}

    //for (;true;)
    //{
    //    Job();
    //}

    for (
        int i = 0; 
        i < 10; 
        i+=1
        )
    {
        Job();
    }
}

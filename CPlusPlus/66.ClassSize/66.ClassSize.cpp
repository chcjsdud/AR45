// 66.ClassSize.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 바이트 패딩
class Test0
{
    // 1. 내부에서 가장큰 바이트 자료형을 찾는다.
    // 2. 그리고 순서대로 읽으면서
    // 3. 자료형이 하나있을때 무조건 가장 큰 자료형의 바이트로 할당한다.
    // 4. 그리고 후속 자료형과 합쳐서 그 가장 큰 자료형의 크기를 넘기지 않으면
    //    하나로 합친다.
    // 5. 계속 반복하면서 읽는다.

    char Value0; // 8
    __int64 Value2;  // 8
    char Value1; // 8

    void ttt() 
    {

    }
};

class Test1
{
    void ttt() 
    {

    }
};


class Test2
{
    // 자료형** _vfptr;
    // 가상함수 테이블이라고 합니다.
    // 가상함수들의 목록을 의미합니다.

    // char Test;

    virtual void AFunction()
    {

    }

    virtual void BFunction()
    {

    }

};



int main()
{
    Test2 Test;

    std::cout << sizeof(Test2);
}

// 81.OperatorEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Test 
{
private:
    int* Value;

public:
    // const가 붙지 않습니다.
    void operator=(Test&& _Other) 
    {
        // 얕은 복사만 합니다.
        Value = _Other.Value;
        _Other.Value = nullptr;
    }

    //void operator=(Test&& _Other) 
    //{
    //    int a = 0;
    //}

public:
    Test& operator++() 
    {
        ++*Value;
        return *this;
    }

    // 후위
    Test operator++(int)
    {
        Test NewTest;
        *NewTest.Value = *Value++;
        return NewTest;
    }

    Test() 
    {
        Value = new int();
    }

    Test(const Test& _Other)
    {
        Value = new int();
    }


    ~Test() 
    {
        if (nullptr != Value)
        {
            delete Value;
        }
    }
};

Test Function()
{
    Test NewTest = Test();

    NewTest++;

    return NewTest;
}

int main()
{
    Test NewTest;

    NewTest = Function();
}
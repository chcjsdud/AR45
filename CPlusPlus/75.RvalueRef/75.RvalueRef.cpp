// 75.RvalueRef.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

class Test 
{
private:
    int Value;
    int* Ptr = nullptr;

public:
    void Functiuon() 
    {
        Value = 10;
    }

public:
    Test()
    {
        Ptr = new int[10];
    }

    Test(const Test& _Other)
    {
        Ptr = new int[10];
        for (size_t i = 0; i < 10; i++)
        {
            Ptr[i] = _Other.Ptr[i];
        }
    }

    Test& operator=(const Test& _Other)
    {
        Ptr = new int[10];
        for (size_t i = 0; i < 10; i++)
        {
            Ptr[i] = _Other.Ptr[i];
        }

        return *this;
    }

    //// 이동 대입연산자.
    Test& operator=(Test&& _Other) noexcept
    {
        if (nullptr != Ptr)
        {
            delete Ptr;
            Ptr = nullptr;
        }

        this;

        Ptr = _Other.Ptr;
        _Other.Ptr = nullptr;

        return *this;
    }

    // Test(Test&& _Other) noexcept = delete;
    Test(Test&& _Other) noexcept
    {
        Ptr = _Other.Ptr;
        _Other.Ptr = nullptr;
    }


    ~Test()
    {
        if (nullptr != Ptr)
        {
            delete Ptr;
            Ptr = nullptr;
        }
    }

};

Test CreateTest() 
{
    Test NewTest;

    return NewTest;
}

Test CreateTest2()
{
    Test NewTest;

    NewTest.Functiuon();

    return NewTest;
}

// 32바이트인가?
// Ptr
std::vector<int> TestNewTest() 
{
    std::vector<int> Arr = std::vector<int>(1000);

    return Arr;
}


int CreateTest0() 
{
    return 10;
}

int main()
{
    int Value = 0;
    int Value1 = 10;

    Value = Value1 = Value;


    Test NewArr0;
    Test NewArr1 = NewArr0;

    NewArr1.operator=(NewArr0).operator=(NewArr0);

    //Test NewArr6;

    //NewArr1.operator=(CreateTest());

    //Test NewArr2 = CreateTest2();


    //CreateTest0();
    //

    //std::vector<int> Arr = TestNewTest();
}

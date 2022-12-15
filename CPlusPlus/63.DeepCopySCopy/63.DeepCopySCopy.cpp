// 63.DeepCopySCopy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class A 
{
public:
    A() {

    }

    ~A() {

    }

    A(const A& _Other) = delete;
    // A& operator=(const A& _Other) = delete;
    A(A&& _Other) noexcept = delete;
    A& operator=(A&& _Other) noexcept = delete;

    A& operator=(const A& _Other) 
    {
        return *this;
    }
};

class Data
{
public:
    A* NewA = nullptr;

    Data& operator=(const Data& _Data) 
    {
        // 얕은 복사.
        // 참조대 참조 복사
        // NewA = _Data.NewA;

        // 깊은 복사.
        // 참조대 참조 복사
        *NewA = *_Data.NewA;

        return *this;
    }

    Data() 
        : NewA(new A())
    {
        
    }

    Data(const Data& _Data)
        : NewA(new A())
        // 또 ㅌ
    {
        // 내껄 만들고 대입으로 깊은 복사까지 해야 터지지 않는다.
        *NewA = *_Data.NewA;
    }

    ~Data() 
    {
        if (nullptr != NewA)
        {
            delete NewA;
            NewA = nullptr;
        }
    }
};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Data NewData0;
    Data NewData1 = NewData0;

    // NewData1 = NewData0;
}

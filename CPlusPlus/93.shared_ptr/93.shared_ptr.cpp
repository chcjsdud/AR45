// 93.shared_ptr.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <crtdbg.h>
#include "A.h"
#include "B.h"

class Monster 
{
public:
    int RefCount;
    int Value;

public:
    void Damage() 
    {
        std::cout << "aaaaa" << std::endl;
    }
};

typedef Monster PtrType;

// template<typename PtrType>
class TPtr
{
public:
    PtrType* Ptr = nullptr;
    int* RefCount = nullptr;

    void AddCount() 
    {
        if (nullptr == RefCount)
        {
            return;
        }

        ++(*RefCount);
    }

    void DecCount()
    {
        if (nullptr == RefCount)
        {
            return;
        }

        --(*RefCount);

        if (0 == (*RefCount))
        {
            delete Ptr;
            delete RefCount;
        }
    }

public:
    TPtr()
    {

    }

    TPtr(const TPtr& _Other)
        : Ptr(_Other.Ptr)
        , RefCount(_Other.RefCount)
    {
        AddCount();
    }

    ~TPtr()
    {
        DecCount();
    }
};

TPtr make_Ptr() 
{
    TPtr Ptr;
    Ptr.Ptr = new Monster();
    Ptr.RefCount = new int();
    Ptr.AddCount();

    return Ptr;
}

int Test() 
{
    int Value = 10;
    return Value;
}

int main()
{

    {
        int Value = Test();
    }

    //Monster* NewPtr = new Monster();
    //Monster* NewPtr2 = NewPtr;

    //delete NewPtr2;

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    {
        // main함수의 NewPtr이라고하는 
        TPtr NewPtr = make_Ptr();

        TPtr NewPtr2 = NewPtr;

    }

    {
        std::shared_ptr<Monster> NewPtr = std::make_shared<Monster>();


        int a = 0;
    }

    {
                         // 1  
        std::shared_ptr<A> NewA = std::make_shared<A>();
                         // 1
        std::shared_ptr<B> NewB = std::make_shared<B>();

        // 순환 참조라고 합니다.
        // A가 B 를 알고
        // B는 A 를 알고
        // 2
        NewA->Ptr = NewB;
        NewB->Ptr = NewA;
    }

}




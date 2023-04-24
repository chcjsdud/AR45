// 93.shared_ptr.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <crtdbg.h>
#include "A.h"
#include "B.h"

class PtrClass 
{
    int RefCount = 0;
};

class Monster : public PtrClass
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
    Ptr.Ptr = new Monster(); // 100만번째 
    Ptr.RefCount = new int(); // 200만번째
    Ptr.AddCount();

    return Ptr;
}

int Test() 
{
    int Value = 10;
    return Value;
}

class GameEngineObject : public std::enable_shared_from_this<GameEngineObject>
{
public:
    template<typename PtrType>
    std::shared_ptr<PtrType> GetSharedThis()
    {
        return std::dynamic_pointer_cast<PtrType>(std::enable_shared_from_this<GameEngineObject>::shared_from_this());
    }

    virtual ~GameEngineObject() 
    {

    }
};

class Player  : public GameEngineObject
{
public:
    //std::shared_ptr< Player> GetSPtr() 
    //{
    //    return shared_from_this();
    //}
};

int main()
{

    {
        //NewPlayer->shared_from_this();
        //NewPlayer->weak_from_this();
     
        // Player* NewPlayer = new Player();
        std::shared_ptr<Player> NewPlayerSPtr = std::make_shared<Player>();
        // Player* NewPlayer = NewPlayerSPtr.get();

        std::shared_ptr<Player> Test0 = NewPlayerSPtr->GetSharedThis<Player>();

        std::shared_ptr<Player> Test1 = NewPlayerSPtr->shared_from_this();


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

        // 2
        NewB->Ptr = NewA;
    }

    return 1;

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

}




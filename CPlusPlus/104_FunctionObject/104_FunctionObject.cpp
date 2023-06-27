// 104_FunctionObject.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <mutex>

// 이게 함수 객체
class Functionopper 
{
public:
    void operator()() 
    {

    }
};

std::mutex Lock;

// 이게 많이 사용되는 사용
class Test 
{
    std::mutex& NewTest;

public:
    Test(std::mutex& _Lock) 
        : NewTest(_Lock)
    {
        NewTest.lock();
    }

    ~Test() 
    {
        NewTest.unlock();
    }
};

int main()
{
    Test NewTest = Test(Lock);

    Functionopper Test;

    return;

    Test();

    std::cout << "Hello World!\n";
}

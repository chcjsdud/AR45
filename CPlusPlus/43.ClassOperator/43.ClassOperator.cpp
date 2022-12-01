// 43.ClassOperator.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class MyInt 
{
public:
    void Function() 
    {

    }

public:
    void operator+(int _Other) 
    {
        MyInt* Ptr = this;

        return;
    }

    void operator+(char _Other)
    {
        MyInt* Ptr = this;

        return;
    }

    void operator+(int* _Other)
    {
        MyInt* Ptr = this;
        return;
    }


    //int operator<(MyInt & _Other)
    //{
    //    return true;
    //}
};

int main()
{
    MyInt NewInt0;
    MyInt NewInt1;
    MyInt NewInt2;

    // NewInt0 + NewInt1 + NewInt2;

    // NewInt0 + 'a';

    // NewInt0.operator+(NewInt1).operator+(NewInt2);

    //MyInt Result = NewInt0.operator+(NewInt1);
    //Result.operator+(NewInt2);

    // NewInt.Function();

    std::cout << "Hello World!\n";
}

// 32.Reference.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void Function0(int* Ptr) 
{
    *Ptr = 10;
}

void Function1(int* Ptr)
{
    Function0(Ptr);
}

void Function2(int* Ptr)
{
    Function1(Ptr);
}

void Function3(int* Ptr)
{
    Function2(Ptr);
}

void ValueChange(int* Value) 
{
    if (nullptr == Value)
    {
        return;
    }

    *Value = 30;
}

// c:\\aaaa.png
//뭐시기& TextureLoad(char* _Path) 
//{
//
//}

int main()
{
    {
        int Value = 20;
        // 상시 *이 붙은 포인터라고 생각하시면 됩니다.
        // int& ValueRef = Value;

        ValueChange(Value);

        // int* Ptr = &Value;
        // *Ptr

        // 상수영역을 수정할수 없기 때문에 const가 붙은 상태로 받아야
        // 사용할수 있다.
        // const int& ValueRef = 0;


        // ValueRef = 20;

        int Test = 0;

        // ValueRef == Value


        ValueChange(Value);

        int* Ptr = &Value;

        Function3(Ptr);
    }

    {
        int size = sizeof(int*);

        int Value = 10;

        int* Ptr = &Value;

        int& Ref = Value;

        int* Ptr = &Ref;

        Value += 2;

        int Ptrsize = sizeof(Value);

        int a = 0;

    }

    // Value = 10;

}

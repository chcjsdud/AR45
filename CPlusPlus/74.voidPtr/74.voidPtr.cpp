// 74.voidPtr.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void mymemset(void* _Ptr, int _Value, size_t _Size)
{

    char* Ptr = reinterpret_cast<char*>(_Ptr);

    for (size_t i = 0; i < _Size; i++)
    {
        Ptr[i] = _Value;
    }

}

int main()
{

    int Arr[10];

    // 바이트 단위로 
    mymemset(Arr, 1, sizeof(Arr));



    // 주소값만을 가지는 포인터입니다.
    // 타입을 가지지 않아요
    
    int Value = 0;
    // 어떤 주소값이든 사용할수 있다.
    void* Ptr = &Value;

    // void*를 사용하는 함수들은 대부분 크기를 넣어주는 

    // 100번지 + (sizeof(Type) * 1)
    // Ptr + 1;

    short Values = 0;
    Ptr = &Values;

    std::cout << "Hello World!\n";
}

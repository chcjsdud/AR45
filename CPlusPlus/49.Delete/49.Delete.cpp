// 49.Delete.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class A 
{
public:
    ~A() 
    {
        int a = 0;
    }
};

int main()
{
    //                     101112131415
    // 0 1 2 3 4 5 6 7 8 9 a b c d e f

    //8421
    0b11111111;
    
    // int Value = 0xff;
    int Value = 0xff;

    // 0x01

    // _CRTDBG_ALLOC_MEM_DF
    // 0b00000000000000000000000000000001
    // 0x01
    // _CRTDBG_LEAK_CHECK_DF
    // 0x   0   0   0   0   0   0   2   0
    // 0b00000000000000000000000000100000
    // 0x20

    // 0b00000000000000000000000000100001

    //                       돈9999     플레이어무적
    // 0b00000000000000000000000000100001
    // int 1개 가지고 32개의 옵션을 압축하기 위해서 이렇게 만들었다.

    // 메모리가 new 될때마다 체크해줘
    // 만약 그 메모리가 해제안되면 로그로 출력창에 띄워죠.
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    A* NewValue = new A[10];

    // NewValue[0];

    // 내가 직접 지워줘야 합니다.
    // 배열일 경우에는 delete[]
    delete[] NewValue;
    // 삭제하지 않은 heap 영역의 메모리를 c++에서는 릭이라고 한다.
    // 
    //Detected memory leaks!
    //    Dumping objects ->
    //{76} normal block at 0x000001F4441838F0, 4 bytes long.
    //    Data: < > 00 00 00 00
    //    Object dump complete.

    A* Ptr = new A();

    // 배열일 경우에는 delete
    delete Ptr;

    int* Test = nullptr;

    delete Test;
}

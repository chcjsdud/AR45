// 10.OperatorEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//int MySizeof() 
//{
//    return 크기;
//}

int main()
{
    int AAAA;

    // sizeof(메모리영역의 이름, 자료형 그자체)
    // 바이트 크기를 반환합니다.
    int size = 0;
    size = sizeof(int);
    size = sizeof(bool);

    // 참 혹은 거짓 ? 참일때 반환값 : 거짓일때 반환값

    int Left = 10;
    int Right = 20;

    bool Check = Left > Right;

    int Value = Check ? 100 : 200;

}

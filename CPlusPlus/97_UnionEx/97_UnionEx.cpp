// 97_UnionEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// class의 메모리 형식은
// 바이트 패딩을 하면서
// 변수들이 서로간의 메모리영역을 겹치게 두지 않습니다.

class int4
{
public:
    // 여기서부터는 유니온의 메모리구성방식을 사용해라.
    union 
    {
        struct 
        {
            int x;
            int y;
            int z;
            int w;
        };

        int Arr[4];
    };
};

class int4x4
{
public:
    // 여기서부터는 유니온의 메모리구성방식을 사용해라.
    union
    {
        struct
        {
            int _00;
            int _01;
            int _02;
            int _03;
            
            int _10;
            int _11;
            int _12;
            int _13;

            int _20;
            int _21;
            int _22;
            int _23;

            int _30;
            int _31;
            int _32;
            int _33;
        };

        int Arr[4][4];
    };
};

// 하나의 메모리공간에 여러개의 이름을 붙이는 거에요
// 레퍼런스와 같이.
union TestUnion
{
    // 여기서부터는 struct의; 방식을 사용해라.
    struct 
    {
        float x;
        float y;
        __int64 Test;
    };
    // float& y = x;

};

int main()
{
    // int Size0 = sizeof(float4);
    int Size1 = sizeof(TestUnion);

    int4x4 NewInt4;

    std::cout << NewInt4._01 << std::endl;
    int4 NewInt4;

    NewInt4.x = 20;

    std::cout << NewInt4.x << std::endl;
    std::cout << NewInt4.y << std::endl;
    std::cout << NewInt4.z << std::endl;
    std::cout << NewInt4.w << std::endl;

    for (size_t i = 0; i < 4; i++)
    {
        std::cout << NewInt4.w << std::endl;
    }


    // 400 
    // x
    // y
    // Test
    TestUnion NewTest;

    std::cout << "Hello World!\n";
}


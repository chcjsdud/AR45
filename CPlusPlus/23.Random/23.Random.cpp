// 23.Random.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

// 난수의 시작값을 용어적으로 시드밸류라고 합니다.
int Seed = 10;

void mysrand(int _Seed)
{
    Seed = _Seed;
    return;
}

int myrand() 
{
    // 여기 내부에서 어떤 짓을 해서건 그냥 숫자를 변경하고
    // 리턴하는것.
    Seed += 1;
    return Seed;
}

int main()
{
    // 1669015836
    // 1669015859
    // SRandom(time(0));

    // randtimeom
    // mysrand();
    srand(time(0));

    while (true)
    {
        // printf_s("%d\n", Random());

        // srand(0);

        printf_s("%d\n", rand());
        _getch();
    }

    //std::cout << "Hello World!\n";
}

// 79.FunctionConst.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Player
{
    int Att = 10;

public:
    int GetAtt() const
    {
        // 메모리를 바꾸지 않는다는 겁니다.
        // 정확하게 말하면 자기자신을 const로 만드는 겁니다.
        // Player* const Ptr = this;
        
        // 일반 맴버함수에서만 사용할수 있다.
        // 이유 => this를 const로 만드는 것이기 때문이다.
        // 함수의 const를 붙이면 Player에게 const가 붙게된다.
        // const Player* const Ptr = this;
        // this->Att = 999;
        return Att;
    }

    void Function() const
    {

    }
};

int main()
{
    std::cout << "Hello World!\n";
}

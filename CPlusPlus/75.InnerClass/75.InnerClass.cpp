// 75.InnerClass.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Player 
{
private:
    // 외부에 특정 클래스를 통한 인터페이스를 제공하고 싶을때.
    class Inventory {

    };


public:
    Inventory Inven;


private:
    // 어떤 클래스에서만 사용하는 클래스를 만들고 싶을때.
    class Item 
    {
        int ItemValue;

        void Funcion() 
        {
            // Hp = 20;
        }
    };

    void Test() 
    {
    }

};

int main()
{
    Player NewPlayer;

    // NewPlayer.Inven.

    // Player::Inventory Iven;

    // Player::Item

    std::cout << "Hello World!\n";
}

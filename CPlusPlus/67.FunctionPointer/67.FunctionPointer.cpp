// 67.FunctionPointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void PlayerAttack() 
{
    std::cout << "플레이어가 공격합니다!\n";
}

void MenuOpen()
{
    std::cout << "메뉴를 오픈합니다!\n";
}

class Image 
{

};

class UIButton
{
public:
    Image ButtonImage;
    void(*FunctionPtr)() = nullptr;

public:
    void Click() 
    {
        if (nullptr == FunctionPtr)
        {
            return;
        }

        FunctionPtr();
        // 플레이어가 버튼을 호출하면 이게 호출됨.
    }
};
//
//class PlayerAttackButton : public UIButton
//{
//public:
//    void Click() override
//    {
//        // 플레이어가 버튼을 호출하면 이게 호출됨.
//    }
//};

int main()
{
    UIButton PlayerAttackButton;
    UIButton MenuButton;

    PlayerAttackButton.FunctionPtr = PlayerAttack;
    MenuButton.FunctionPtr = MenuOpen;

    PlayerAttackButton.Click();
    MenuButton.Click();
    
    // 전역함수일때만 이 함수포인터로 가능합니다.
    void(*Function)(int Vlaue);

    std::cout << sizeof(Function);
    
}

// 94.Rtti.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// Real Time Type Infomation

#include <iostream>
#include <typeinfo>

class Parent 
{

};

class Player : public Parent
{

};

class Monster : public Parent
{

};

int main()
{
    const type_info& Info = typeid(Player);
    std::cout << Info.name() << std::endl;
    
}

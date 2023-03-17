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
    // Hash는 특정 메모리영역을 특정 정수로 변경하는 함수를 해쉬함수라고 부릅니다.

    // 면접때는 중요하기 때문에
    // "fasdfasdfasdfasdfsad" => 1231121122111% 5
    // "gsgregregergegregerg" => 1231121122111

    const type_info& Info = typeid(Player);
    std::cout << Info.name() << std::endl;

    std::string Name0 = Info.name();
    std::string Name1 = Info.raw_name();

    size_t Value = Info.hash_code();
}



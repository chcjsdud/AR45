// 90.HasaIsa.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class FightUnit {

};

class Item 
{

};

// Player는 Fight Unit다 => Is A 관계
class Player : public FightUnit 
{
    // Player는 Item을 가졌다. => Has a
    Item EquipItem;
};

class GameEngineActor 
{
protected:
    void CreateRenderer() 
    {

    }
};

// Is a의 해결방법
// 자기 스스로 업데이트를 하거나 이런것들이 구성하기 쉽니다.
// 단점 액터가 많이질겁니다.
class NumbersRenderObject : public GameEngineActor
{
    void Start() 
    {
        for (size_t i = 0; i < 10; i++)
        {
            CreateRenderer();
        }
    }
};


class PlayLevel
{
public:
    // PlayUI
    NumbersRenderObject* TimeNumber;
    NumbersRenderObject* BulletNumber;
    NumbersRenderObject* BomeNumber;
};


// 하나의 액터에다가 이걸 여러개 넣을수 있다.
class NumbersRenderInner
{
    GameEngineActor* Actor;

    void Start()
    {
        for (size_t i = 0; i < 10; i++)
        {
            Actor->CreateRenderer();
        }
    }
};


class UIActor
{
public:
    NumbersRenderInner TimeNumber;
    NumbersRenderInner BulletNumber;
    NumbersRenderInner BomeNumber;
};


int main()
{
    std::cout << "Hello World!\n";
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

// Node.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <GameEngineArray.h>
#include <conio.h>

// Node 는 어떠한 클래스가
// 자기자신의 참조형을 n개 가지는 구조를 node 구조라고 합니다.

char Arr[100][100] = 
{
    "에러",
    "시작마을",
    "초보사냥터",
    "중간마을",
    "중간사냥터",
    "오그리마",
    "스톰윈드",
    "모코코섬",
    "헤네시스",
    "시간의섬",
    "아무거나",
};


class Zone
{
public:
    int NameIndex = 0;

    GameEngineArray<Zone*> LinkZones;

public:
    void Link(Zone* _LinkZone) 
    {
        if (nullptr == _LinkZone)
        {
            MessageBoxAssert("존재하지 않는 지역과 연결할 수 없습니다.");
            return;
        }

        if (this == _LinkZone)
        {
            MessageBoxAssert("자기자신과는 연결할 수 없습니다.");
            return;
        }

        for (size_t i = 0; i < LinkZones.GetCount(); i++)
        {
            if (LinkZones[i] == _LinkZone)
            {
                MessageBoxAssert("이미 연결된 지역입니다.");
                return;
            }
        }


        // 연산량이 크겠죠.
        // 동적배열이기 대문에 이런일을 1000개가 들어있다고치면
        // 1000개를 1001개의 배열을 만들고 1000개를 1001개의 배열에 복사한다음
        // 기존의 1000개를 지우는 일을 하는것과 마찬가지이다.
        LinkZones.ReSize(LinkZones.GetCount() + 1);
        LinkZones[LinkZones.GetCount() - 1] = _LinkZone;

        _LinkZone->LinkZones.ReSize(_LinkZone->LinkZones.GetCount() + 1);
        _LinkZone->LinkZones[_LinkZone->LinkZones.GetCount() - 1] = this;
    }

    void LinkPrint() 
    {
        NamePrint();
        printf_s("지역은 다음의 지역들과 연결되어 있습니다.\n");
        for (size_t i = 0; i < LinkZones.GetCount(); i++)
        {
            printf_s("%ld. ", i + 1);
            LinkZones[i]->NamePrint();
            printf_s("\n");
        }
    }

    Zone* MoveSelect()
    {
        int SelectValue = _getch();
        SelectValue -= '1';

        if (SelectValue < 0
            && SelectValue <= LinkZones.GetCount())
        {
            printf_s("선택 범위를 벗어났습니다.\n");
            int Result = _getch();
            return nullptr;
        }

        Zone* LinkZone = LinkZones[SelectValue];

        return LinkZone;
    }


public:
    void NamePrint() 
    {
        printf_s(Arr[NameIndex]);
    }

public:
    Zone() 
    {

    }

    Zone(int _NameIndex)
        : NameIndex(_NameIndex)
    {

    }
};

int main()
{
    LeckCheck();

    Zone NewZone0(1);
    Zone NewZone1(2);
    Zone NewZone2(3);
    Zone NewZone3(4);
    Zone NewZone4(5);
    Zone NewZone5(6);
    Zone NewZone6(7);
    Zone NewZone7(8);
    Zone NewZone8(9);

    NewZone0.Link(&NewZone1);
    NewZone0.Link(&NewZone2);

    NewZone1.Link(&NewZone4);
    NewZone1.Link(&NewZone5);
    NewZone1.Link(&NewZone6);


    NewZone4.Link(&NewZone7);
    NewZone4.Link(&NewZone8);


    // NewZone2.Link(&NewZone1);

    Zone* CurZone = &NewZone0;
    while (true)
    {
        system("cls");

        CurZone->LinkPrint();

        printf_s("어디로 이동하시겠습니까?");
        Zone* NextZone = CurZone->MoveSelect();

        if (nullptr == NextZone)
        {
            continue;
        }
        CurZone = NextZone;
    }
}

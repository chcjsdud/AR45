// DamageSimul.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

// 절차지향 
// 데이터 기반.
// 플레이어라는 개념을 표현할수 없어요.

int PlayerAtt = 20;
int PlayerHp = 200;

int MonsterAtt = 10;
int MonsterHp = 100;

// 플레이어 능력치는 이렇게 보여줘야 한다.
// 100번지
// 함수를 실행할 메모리를 만들고
void StatusRender(const char* _Name, int _Att, int _Hp)
{
    printf_s("%s =====================================\n", _Name);
    printf_s("공격력 = %d \n", _Att);
    printf_s("체  력 = %d \n", _Hp);
    printf_s("============================================\n");
}

// 300번지
void PlayerDamage(int _Damage) 
{
    PlayerHp -= _Damage;
    int Input = 0;
    printf_s("플레이어가 %d데미지를 받았습니다.\n", _Damage);
    Input = _getch();
    printf_s("플레이어는 %d체력이 남았습니다.\n", PlayerHp);
    Input = _getch();
}

// 500번지
void MonsterDamage(int _Damage)
{
    MonsterHp -= _Damage;

    int Input = 0;
    printf_s("몬스터가 %d데미지를 받았습니다.\n", _Damage);
    Input = _getch();
    printf_s("몬스터는 %d체력이 남았습니다.\n", MonsterHp);
    Input = _getch();
}

int main()
{
    _getch();

    while (true)
    {
        // \n
        // int Value = system("D:\\AR45\\CPlusPlus\\x64\\Debug\\01.Program.exe");
        system("cls");

        // 플레이어 능력치를 보여줘라.
        // 100번지의 내용대로 해라.
        // "플레이어" == char[]
        // char[] == char*

        // "플레이어" == const char[]
        // const char[] => const char*
        StatusRender("플레이어", PlayerAtt, PlayerHp);
        StatusRender("몬스터", MonsterAtt, MonsterHp);
        _getch();
        // Winapi를 
        // 이거 말고도 다른 실행방법도
        // MonsterDamage(PlayerAtt);
        // PlayerDamage(MonsterAtt);

        {
            MonsterHp -= PlayerAtt;
            int Input = 0;
            printf_s("몬스터가 %d데미지를 받았습니다.\n", PlayerAtt);
            Input = _getch();
            printf_s("몬스터는 %d체력이 남았습니다.\n", MonsterHp);
            Input = _getch();
        }
        {
            PlayerHp -= MonsterAtt;
            int Input = 0;
            printf_s("플레이어가 %d데미지를 받았습니다.\n", MonsterAtt);
            Input = _getch();
            printf_s("플레이어는 %d체력이 남았습니다.\n", PlayerHp);
            Input = _getch();
        }
    }
}
 
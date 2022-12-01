#include "Monster.h"
#include <iostream>
#include <conio.h>


// cpp에서는 쓸수 없다 inline 
/*inline*/ void Monster::StatusRender()
{
    printf_s("몬스터 =====================================\n");
    printf_s("공격력 = %d \n", Att);
    printf_s("체  력 = %d \n", Hp);
    printf_s("============================================\n");
}

/*inline */void Monster::Damage(int _Damage)
{
    Hp -= _Damage;
    int Input = 0;
    printf_s("몬스터가 %d데미지를 받았습니다.\n", _Damage);
    Input = _getch();
    printf_s("몬스터는 %d체력이 남았습니다.\n", Hp);
    Input = _getch();
}
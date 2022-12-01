#include "Player.h"
#include <iostream>
#include <conio.h>

void Player::StatusRender() 
{
    printf_s("플레이어 =====================================\n");
    printf_s("공격력 = %d \n", Att);
    printf_s("체  력 = %d \n", Hp);
    printf_s("============================================\n");
}

void Player::Damage(int _Damage)
{
    Hp -= _Damage;
    int Input = 0;
    printf_s("플레이어가 %d데미지를 받았습니다.\n", _Damage);
    Input = _getch();
    printf_s("플레이어는 %d체력이 남았습니다.\n", Hp);
    Input = _getch();
}


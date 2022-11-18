// 22.GlobalVar.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 어느 지역에도 속하지 않은 변수가 됩니다.
// 어느 함수에도 속하지 않은 변수가 됩니다.
// 전역변수라고 하게 됩니다.
// 전역변수는 프로세스와 생명주기를 같이 합니다.
int PlayerHp = 100;

// 전역 함수
void PlayerDamage(int _Damage)
{
    PlayerHp -= _Damage;
    printf_s("플레이어가 %d데미지를 입었습니다.", _Damage);
}

void PlayerHeal(int _Heal)
{
    PlayerHp += _Heal;
    printf_s("플레이어가 %d데미지를 입었습니다.", _Heal);
}

// 함수의 바깥을 전역이라고합니다.
// 그래서 사실 전역함수라고 부릅니다.
int main()
{
    // 이 내부를 메인의 영역, 지역

    PlayerDamage(10);
    PlayerHeal(20);
    
}

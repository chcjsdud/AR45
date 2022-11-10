// 05.Function.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 리턴값   이름    인자
// int     Attack (int AttackATT, int AttackMonsterHP)

// 리턴값의 자료형중
// void는 아무것도 안하겠다.
//void Attack(int AttackATT, int AttackMonsterHP)

int Attack(int AttackATT, int AttackMonsterHP)
{
    AttackMonsterHP = AttackMonsterHP - AttackATT;

    // return 이라고 쓰면 모든걸 종료하면서 리턴값을 외부로 반환해줘.
    return AttackMonsterHP;
}

// 함수의 (인자라고 하는데.)

int main()
{ // 스코프 => 지역

    // 지역변수라고 합니다.
    // 지역변수는 지역내부에서만 메모리가 유효합니다.

    int ATT1 = 100;

    // 공격력을 만들고
    int ATT;
    ATT = 10;

    int MonsterHP;
    MonsterHP = 100;
    // 공격했다

    // int UnName;

    MonsterHP = /*UnName = */Attack(ATT, MonsterHP);

    Attack(ATT, MonsterHP) - 10;

    // 지역이라는것은 어디서나 만들수 있습니다.
    // 이름없는 지역
    {
        int TestValue = 200;
    }

    TestValue = 100;

}

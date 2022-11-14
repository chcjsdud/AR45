// 11.Array.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{

    // int MonsterHp1;

    // 배열의 기본문법은 어떤 자료형을 n개 
    // 생성한다는 것을 정의 내리는 것입니다.
    // 정적 배열이라고 합니다.
    //. int MonsterHPArr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // 배열은 선언되고 나면 내가 입력하지 않은 곳에
    // 명확하게 0이 들어가게 된다.
    // int MonsterHPArr[10] = { 0 };
    // int MonsterHPArr[10] = {1 };
    // 초기화를 하지 않으면 쓰레기 값이라고 부리는 값이 들어갑니다.
    // int MonsterHPArr[10]; xxxx 이렇게 사용하면 안된다.
    int MonsterHPArr[10] = {};

    int Value = true;

    Value = MonsterHPArr[0];
    Value = MonsterHPArr[1];
    Value = MonsterHPArr[2];
    Value = MonsterHPArr[3];
    Value = MonsterHPArr[4];
    Value = MonsterHPArr[5];
    Value = MonsterHPArr[6];
    Value = MonsterHPArr[7];
    Value = MonsterHPArr[8];
    Value = MonsterHPArr[9];

    //  int[]      int
    // MonsterHPArr = Value;
    MonsterHPArr[0] = Value;

    int CurMonsterIndex = 3;
    MonsterHPArr[CurMonsterIndex] = 20;
    
}
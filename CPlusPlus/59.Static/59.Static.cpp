// 59.Static.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Monster.h"

// 굉장히 많은 부분에서 쓰이는데
// static 클래스내부 static만 설명하겠습니다.
// 가장 많이 사용되는.
// static member 변수
// static member 함수
// 는 기본적으로 클래스의 이름만으로 사용이 가능하다.


int main()
{

	//Monster NewMonster0;

	//Monster NewMonster1;

	Monster NewMonster2;

	NewMonster2.Func(/*&NewMonster2*/);


	std::cout << Monster::GetAllMonsterCount();
}

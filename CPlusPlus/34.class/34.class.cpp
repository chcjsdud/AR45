// 34.class.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 인간이 일반적으로 생각하는 가장 근본되는 개념들을
// 자료형으로 표현한것들
// 정수 문자 이런것들을 파란색으로 나오는 자료형들
// 언어를 만든 프로그래머들이 먼저 다 정의해놓은 개념들
// 기본자료형 이라고 한다.

// 내 게임에는 총알이 있었으면 좋겠어
// 내 게임에서는 아이템이 있었으면 좋겠어.
// 

// c++에서 객체지향을 지원하는 문법입니다.
//class 개념이름 
//{
//};

// c를 배운 학생

// 개념적으로 속성이라고 합니다. 객체지향. 
//struct Player 
//{
//  속성
//	char ArrName[100];
//	int Att;
//	int Def;
//	int Hp;
//};

// 객체지향에서 속성은 보통 명사이다.
// 공격력
// 방어력
// 힘
// 체력

// 이게 시작입니다.
// 내부를 걱정하는 경우.
class Player 
{
	char ArrName[100];
	int Att;
	int Def;
	int Hp;

	void Attack() {

	}

	void Move() {

	}

	void LevelUp() {

	}
};

class physics 
{
	int Gravity;
};

// 객체지향에서는 전역을 쓸필요가 없어.
int Gravity;

class ProgramStart 
{
	int main()
	{

	}
};

class MyGame
{
	class Player {

	};

	class Monster {

	};

};

class Int 
{

};

// 클래스는 세상의 모든개념 == 모든것(만든 못하는게 없어)
// 나는 안되던데요

// 사용자 임의 자료형
// 사용자 자료형 => class

int main()
{
	int PlayerAtt = 10;
	// int == class Player
}


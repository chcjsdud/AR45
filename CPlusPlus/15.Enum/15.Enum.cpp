// 15.Enum.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//void Function()
//{
//    JOBTYPE Type;
//}

void Function1()
{
    JOBTYPE Type = FIGHTER;
}


// Enum
// 사용자 정의 자료형 문법 중 하나입니다.
// 내가 나만의 타입을 만들어 내고 이것을 자료형으로 사용할수
// 있는 문법
// 그중 Enum은 정수형 상수를 문자로 표현하는데 사용된다.
enum JOBTYPE
{
    // 실행되고나서 바꿀수 없다.
    // 시작값을 내가 이렇게 초기화 해줄수도 있다.
    FIGHTER = 10,
    ARCHER,
    MAGE
};

void Function()
{
    JOBTYPE Type = FIGHTER;
}

int main()
{
    int JobType = 10;

    //if (JobType == FIGHTER)
    //{
    //}
    //else if (JobType == MAGE)
    //{
    //}
    //else if (JobType == MAGE)
    //{
    //} 

    switch (JobType)
    {
    case FIGHTER:
        break;
    case ARCHER:
        break;
    case MAGE:
        break;
    default:
        break;
    }

    Function();
    
}

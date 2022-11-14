#include <iostream>

int Plus(int Left, int Right)
{
    return Left + Right;
}

int PlusPlus(int Value)
{
    return Value + 1;
}

bool Check() 
{
    return false;
}

int main()
{
    int Left = 7;
    int Right = 3;
    int Result = 0;

    // =
    // 은 대입연산자로 오른쪽에있는 메모리 영역을
    // 왼쪽에 있는 메모리영역으로 변환(혹은 대입)해서 넣어라.

    // 항에 따라서
    // 연산자를 변수와 변수의 상호작용을 표현하고.

    // 연산자를 사용하는데 필요한 메모리영역(변수)의 개수에 따라서
    // 단항 1개
    // 이항 2개
    // 삼항 3개

    // 산술연산자부터 보겠습니다.
    // - + * / %

    // 정수의 처리는 소수점 결과를 무시합니다.
    // == 정수의 결과는 정수밖에 나오지 않습니다.
    // 연산자는 눈으로 보기에는 하나의 기호로 보이지만
    // 실제로는 다수의 명령의 집합니다 == 함수 

    // 단항
    // 산술 단항 연산자.
    Result = -Left; // 

    // 이항
    Result = Left - Right; // 빼기
    Result = Left + Right; // 더하기 
    Result = Plus(Left, Right);
    Result = Left * Right; // 곱하기
    Result = Left / Right; // 나누기 
    Result = 1 / 5; // 나누기 
    Result = Left % Right; // 나머지

    int ResultValue = 0;
    Result = 10;
    // 정수로서의 ++연산은 +1
    ResultValue = ++Result;
    ResultValue = --Result;

    //             ++Result;
    ResultValue = (Result = PlusPlus(Result));
    ResultValue = (Result = Result + 1);

    // 추후에 알려드리도록 할께요.
    // 지금은 표현조차 할수 없습니다.
    //ResultValue = Result++;
    //ResultValue = Result--;

    // 비교 연산자
    // 참과 거짓의 개념에 대해서 알아야 합니다.
    // 메모리 영역의 크기와 상관없이
    //  참  => 메모리 영역중 단 하나의 비트라도 1이 있으면 참
    // 거짓 => 모든 비트가 0이라면 거짓
    // 참을 1이라고 하는 사람이 있는데.

    // 1바이트 논리형
    // 자료형변환이라고 합니다.
    // 형변환
    bool ResultBool = 4248125125;
    int Value = ResultBool;

    ResultBool = Left > Right; // 왼쪽이 크다.
    ResultBool = Left < Right; // 왼쪽이 작다.
    ResultBool = Left >= Right; // 왼쪽이 크거나 같다.
    ResultBool = Left <= Right; // 왼쪽이 작거나 같다.
    ResultBool = Left == Right; // 왼쪽과 오른쪽이 같다.
    ResultBool = Left != Right; // 왼쪽과 오른쪽이 다르다.

    // 논리 연산자
    // 참과 거짓을 기반으로 다시 참과 거짓을 판단하는 연산자입니다.
    // 참과 거짓 상수
    ResultBool = true;
    ResultBool = false;

    // 하나라도 false가 있으면 false
    ResultBool = true && true;
    ResultBool = true && false;
    ResultBool = false && true;
    ResultBool = false && false;

    // (연산자는 다른 연산보다 내 연산을 먼저 처리해서 결과를 도출하라.)
    ResultBool = Left > Right && (Left < Right);

    // 하나라도 true가 있으면 true
    ResultBool = true || true;
    ResultBool = true || Check();
    ResultBool = false || true;
    ResultBool = false || false;

    // true면 false
    // false면 true
    ResultBool = !true;
    ResultBool = !false;

    // int 32비트라는걸 알고 계시죠?

    ResultBool = 0b00000000000000000000000000000001;

    Left = 0b00000000000000000000000000000001;
    Left = 0b00000000000000000000000000000010;

    // int 양수 최대값이 나왔을것이고
    Left = 0b01111111111111111111111111111111;
    // -1
    Left = 0b11111111111111111111111111111111;

}

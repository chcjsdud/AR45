// 53.IfDef.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 전처리기 입장에서는
// BOOL값을 하나 만든것과 같습니다.
// 를 전처리문에게 알려줍니다
// VALUE를 선언했다는 뜻도 가지게 됩니다.

#define VALUE 10


// CHECK를 선언했다는 뜻도 가지게 됩니다.
// #define CHECK

// CHECK를 선언했다면
#ifdef CHECK
// 이코드를 만들어라고
int TestValue = 10;
// 선언안햇다면 아예 없어져
#endif

#ifdef CHECK
// 이코드를 만들어라고
int TestValue2 = 20;
// 선언안햇다면 아예 없어져
#else
int TestValue2 = 30;
#endif


int main()
{
    // TestValue = 20;

    std::cout << TestValue2 << std::endl;

    // 

}

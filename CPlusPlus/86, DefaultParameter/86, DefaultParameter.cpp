// 86, DefaultParameter.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//void Function(int A = 10, int B)
//{
//    int a = 0;
//}

// 가장 오른쪽에만 디폴트 인자를 넣어줄수 있다.
// 오른쪽 끝에서부터 채우면 디폴트인자를 몇개를 사용하건 문제가 없습니다.
void Function(int A = 20, int B = 10, int C = 20)
{
    int a = 0;
}

// 오버로딩을 할때 주의해야한다.
//void Function(int A, int B, int C)
//{
//    int a = 0;
//}


int main()
{
    // Function(20, 10);

    Function();

    std::cout << "Hello World!\n";
}

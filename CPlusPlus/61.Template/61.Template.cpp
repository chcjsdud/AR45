// 61.Template.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 템플릿은 자료형을 변수처럼 사용하는 문법입니다.

template<typename DataType>
void Function(DataType Test)
{
    std::cout << Test;
}

//void Function(int Test)
//{
//    std::cout << Test;
//}
//
//void Function(bool Test)
//{
//    std::cout << Test;
//}
//
//void Function(int* Test)
//{
//    std::cout << Test;
//}

// 템플릿 특수화라는 문법이 있는데.

template<>
void Function(int Test)
{
    std::cout << "인트입니다.";
}

//void Function(int* Test)
//{
//    std::cout << Test;
//}
//
//void Function(wchar_t Test)
//{
//    std::cout << Test;
//}

int main()
{
    int* Ptr = nullptr;

    // 함수의 경우에는 인자추론이라는것을 해서
    // 인자가 확실한경우에는 
    Function/*<int*>*/(Ptr);

    Function/*<int>*/(10);
    Function/*<bool>*/(true);
}

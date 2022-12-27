// 77.TemplateEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

template<typename Value0Type, typename Value1Type>
void Function(Value0Type Value0, Value1Type Value1)
{
    std::cout << Value0 << std::endl;
    std::cout << Value1 << std::endl;
}

template<typename Value0Type, typename Value1Type>
class Test
{
public:
    Value0Type Test0;
    Value1Type Test1;
};

int main()
{
    int Ptr = 0;

    // 함수의 경우에는 인자추론이 가능해서
    Function<int, int*>(10, &Ptr);

    Test<int, int> TTT1;
    Test<int, char> TTT2;

    std::cout << "Hello World!\n";
}

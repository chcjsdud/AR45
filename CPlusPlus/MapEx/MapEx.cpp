// MapEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <map>
#include <string_view>

int main()
{
    // std::map<std::string_view, int> Map;

    // 주소값을 비교하는
    std::map<std::string_view, int> Map;

    {
        std::string Test = "aaa";
        Map.insert(std::make_pair(Test.c_str(), 1));
    }
    Map.insert(std::make_pair("aaa", 1));

    std::map<int, int> IntMap;

    // 배열 같죠?
    // 없으면 insert
    // 있다면 find
    // 없으면 만들고
    IntMap[10] = 1;

    std::cout << "Hello World!\n";
}

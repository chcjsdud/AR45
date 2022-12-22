// Vector.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

// new와 delete는 c++의 기본연산중에서도 가장 느린 연산입니다.
// 되도록이면 많이 안되게하려고 프로그래머들이 노력한다.

// GameArray 내부에 자료와 배열의 크기는 상관이 있나요.
// Skill을 10개 만든다면

typedef int DataType;

class GameEngineVector 
{
    int DataSize;
    int MemorySize;
    DataType* Ptr;
};

int main()
{
    {
        // push_back
        // 배열형 시퀸스 자료구조 입니다.
        
        // 크기가 정해져있지 않습니다.
        std::vector<int> IntVector = std::vector<int>();
        //IntVector.push_back(8);
        //IntVector.push_back(9);
        //IntVector.push_back(5);
        //IntVector.push_back(0);
        //IntVector.push_back(7);

        for (size_t i = 0; i < 100; i++)
        {
            // 내부에 존재하는 배열의 크기입니다.
            std::cout << "Capacity" << IntVector.capacity() << std::endl;
            // 내가 집어넣은 데이터의 크기입니다.
            std::cout << "Size" << IntVector.size() << std::endl;
            IntVector.push_back(i);
        }

        for (size_t i = 0; i < IntVector.size(); i++)
        {
            // std::cout << IntVector[i] << std::endl;
        }

            // std::cout << "Hello World!\n";
    }
}

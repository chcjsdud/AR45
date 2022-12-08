// 56.DanglingPointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    //{
    //    // 스택메모리는 delete할수 없습니다.
    //    int Value = 100;

    //    // 동적할당하지 않은 녀석은 삭제하면 무슨문제가 생길지 예상할수 없다.
    //    int* Ptr = &Value;

    //    delete Ptr;
    //}

    {
        int* Ptr = new int();

        if (nullptr != Ptr)
        {
            delete Ptr;
            Ptr = nullptr;
            // 
            // Ptr = nullptr;
        }

        if (nullptr != Ptr)
        {
            int Test = *Ptr;
        }

        if (nullptr != Ptr)
        {
            delete Ptr;
            Ptr = nullptr;
        }

        int a = 0;
    }

    {
        // 댕글링 포인터
        // 지웠는데 쓴다.
        //int* Ptr = new int();

        //delete Ptr;

        //*Ptr = 100;
    }

    {
        // 로스트 포인터
        // 동적할당 해놓고 그 주소값을 받지 않는것.
        int* Ptr = new int();

        // 기존에 먼저 할당한 메모리의 주소는 잃어 버리는것.
        Ptr = new int();
    }

}

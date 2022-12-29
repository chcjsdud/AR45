// Map.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <map>
#include <GameEngineDebug.h>

typedef int KeyType;
typedef int ValueType;

class GameEnginePair 
{
public:
    KeyType first;
    ValueType second;
};

class GameEngineMap
{
private:
	class BinaryNode
	{
	public:
		BinaryNode* Parent = nullptr;
		BinaryNode* LeftChild = nullptr;
		BinaryNode* RightChild = nullptr;
        GameEnginePair Pair;

        BinaryNode* MinNode() 
        {
            if (nullptr == LeftChild)
            {
                return this;
            }

            return LeftChild->MinNode();
        }

        BinaryNode* MaxNode()
        {
            if (nullptr == RightChild)
            {
                return this;
            }

            return RightChild->MaxNode();
        }

        BinaryNode* ParentNext(const KeyType& _Key) 
        {
            if (Pair.first > _Key)
            {
                return this;
            }

            if (nullptr == Parent)
            {
                return nullptr;
            }

            return Parent->ParentNext(_Key);
        }

        BinaryNode* NextNode()
        {
            if (nullptr == RightChild)
            {
                return Parent->ParentNext(Pair.first);
            }

            return RightChild->MinNode();
        }


        void ChildChange(BinaryNode* _Old, BinaryNode* _New)
        {
            if (_Old == RightChild)
            {
                RightChild = _New;
            }

            if (_Old == LeftChild)
            {
                LeftChild = _New;

            }

            if (nullptr != _New)
            {
                _New->Parent = this;
            }
        }


        BinaryNode* find(const KeyType& _Key) 
        {
            if (Pair.first == _Key)
            {
                return this;
            }
            else if (Pair.first > _Key)
            {
                if (nullptr == LeftChild)
                {
                    return nullptr;
                }

                return LeftChild->find(_Key);
            }
            else if (Pair.first < _Key)
            {
                 if (nullptr == RightChild)
                {
                    return nullptr;
                }

                return RightChild->find(_Key);
            }

            return nullptr;

        }

        void Insert(const GameEnginePair& _Pair)
        {
            if (Pair.first > _Pair.first)
            {
                if (nullptr == LeftChild)
                {
                    LeftChild = new BinaryNode();
                    LeftChild->Pair = _Pair;
                    LeftChild->Parent = this;
                    return;
                }

                return LeftChild->Insert(_Pair);
            }
            else if (Pair.first < _Pair.first)
            {
                if (nullptr == RightChild)
                {
                    RightChild = new BinaryNode();
                    RightChild->Pair = _Pair;
                    RightChild->Parent = this;
                    return;
                }

                RightChild->Insert(_Pair);
            }
            else 
            {
                MessageBoxAssert("키가 겹치는 pair를 insert했습니다");
            }
        }

        void FirstOrder()
        {
            std::cout << Pair.first << std::endl;
            if (nullptr != LeftChild)
            {
                LeftChild->FirstOrder();
            }
            if (nullptr != RightChild)
            {
                RightChild->FirstOrder();
            }
        }

        void Relase() 
        {
            if (nullptr != LeftChild)
            {
                LeftChild->Relase();
            }
            if (nullptr != RightChild)
            {
                RightChild->Relase();
            }
            delete this;
        }

        // 후위 순회
        void LastOrder()
        {
            if (nullptr != LeftChild)
            {
                LeftChild->LastOrder();
            }
            if (nullptr != RightChild)
            {
                RightChild->LastOrder();
            }
            std::cout << Pair.first << std::endl;
        }

        // 중위 순회
        void MidOrder()
        {
            if (nullptr != LeftChild)
            {
                LeftChild->MidOrder();
            }
            std::cout << Pair.first << std::endl;
            if (nullptr != RightChild)
            {
                RightChild->MidOrder();
            }
        }

	public:
		BinaryNode()
		{

		}
		~BinaryNode()
		{
        }
	};

public:
	class iterator
	{
		// 나는 분명히 여러가지 접근제한 지정자를 사용하고 있지만
		// 어떤 클래스 에게만큼은 나의 모든걸 public으로 공개하겠다.
		friend GameEngineMap;

	private:
        BinaryNode* CurNode;

	public:
        bool operator==(const iterator& _Other)
        {
            return _Other.CurNode == CurNode;
        }

        bool operator!=(const iterator& _Other)
        {
            return _Other.CurNode != CurNode;
        }

        //_NODISCARD pointer operator->() const noexcept {
        //    return pointer_traits<pointer>::pointer_to(**this);
        //}


        GameEnginePair* operator->()
        {
            if (nullptr == CurNode)
            {
                return nullptr;
            }

            return &CurNode->Pair;
        }


		iterator& operator++()
		{
            CurNode = CurNode->NextNode();
			return *this;
		}
	};

public:
    void insert(const GameEnginePair& _Pair)
    {
        if (nullptr == RootNode)
        {
            RootNode = new BinaryNode();
            RootNode->Pair = _Pair;
            return;
        }

        RootNode->Insert(_Pair);
    }

    iterator find(const KeyType& _Key) 
    {
        if (nullptr == RootNode)
        {
            return end();
        }

        iterator NewIter;
        NewIter.CurNode = RootNode->find(_Key);
        return NewIter;
    }

    iterator erase(const iterator& _Other)
    {
        BinaryNode* DeleteNode = _Other.CurNode;
        BinaryNode* ParentNode = DeleteNode->Parent;
        BinaryNode* LeftChildNode = DeleteNode->LeftChild;
        BinaryNode* RightChildNode = DeleteNode->RightChild;
        BinaryNode* NextNode = _Other.CurNode->NextNode();

        iterator NewIter;
        NewIter.CurNode = NextNode;

        if (nullptr == DeleteNode)
        {
            MessageBoxAssert("end를 삭제하려고 했습니다.");
            return NewIter;
        }

        if (nullptr == LeftChildNode && nullptr == RightChildNode)
        {
            if (nullptr != ParentNode)
            {
                ParentNode->ChildChange(DeleteNode, nullptr);
            }

            if (RootNode == DeleteNode)
            {
                RootNode = nullptr;
            }

            delete DeleteNode;
            DeleteNode = nullptr;
            return NewIter;
        }

        BinaryNode* ChangeNode = nullptr;
        BinaryNode* ChangeParentNode = nullptr;

        if (nullptr != LeftChildNode)
        {
            ChangeNode = LeftChildNode->MaxNode();
            ChangeParentNode = ChangeNode->Parent;
        } else if (nullptr != RightChildNode)
        {
            ChangeNode = RightChildNode->MinNode();
            ChangeParentNode = ChangeNode->Parent;
        }

        if (nullptr != ChangeParentNode)
        {
            ChangeParentNode->ChildChange(ChangeNode, ChangeNode->LeftChild);
        }

        if (nullptr != ParentNode)
        {
            ParentNode->ChildChange(DeleteNode, ChangeNode);
        }

        if (LeftChildNode != ChangeNode)
        {
            ChangeNode->LeftChild = LeftChildNode;
            if (nullptr != LeftChildNode)
            {
                LeftChildNode->Parent = ChangeNode;
            }
        }
        if (RightChildNode != ChangeNode)
        {
            ChangeNode->RightChild = RightChildNode;
            if (nullptr != RightChildNode)
            {
                RightChildNode->Parent = ChangeNode;
            }
        }

        if (RootNode == DeleteNode)
        {
            RootNode = ChangeNode;
        }

        delete DeleteNode;
        DeleteNode = nullptr;

        return NewIter;
    }


    iterator begin()
    {
        if (nullptr == RootNode)
        {
            return end();
        }

        iterator NewIter;
        NewIter.CurNode = RootNode->MinNode();
        return NewIter;
    }


    iterator end()
    {
        iterator NewIter;
        NewIter.CurNode = nullptr;
        return NewIter;
    }

    // 전위 순회
    void FirstOrder() 
    {
        if (nullptr == RootNode)
        {
            return;
        }
        RootNode->FirstOrder();
    }

    void Relase()
    {
        if (nullptr == RootNode)
        {
            return;
        }
        RootNode->Relase();
        RootNode = nullptr;
    }

    // 후위 순회
    void LastOrder()
    {
        if (nullptr == RootNode)
        {
            return;
        }
        RootNode->LastOrder();
    }

    // 중위 순회
    void MidOrder()
    {
        if (nullptr == RootNode)
        {
            return;
        }
        RootNode->MidOrder();
    }

    ~GameEngineMap() 
    {
        if (nullptr != RootNode)
        {
            RootNode->Relase();
            RootNode = nullptr;
        }
    }


public:
    BinaryNode* RootNode = nullptr;
};

GameEnginePair make_pair(KeyType _Key, KeyType _Value)
{
    return { _Key , _Value };
}

int main()
{
    LeckCheck();

    //{
    //    // 레드블랙알고리즘을 사용한 자가균형 탐색 2진 트리 자료구조입니다.
    //    //      Key  Value
    //    std::map<const char*, MonsterData> DataMap;

    //    DataMap.insert(std::make_pair("오크", MonsterData{ 10, 100 }));
    //    // 키는 겹치면 상관은 없는데 
    //    DataMap.insert(std::make_pair("드래곤", MonsterData{ 50, 1000 }));


    //    std::map<const char*, MonsterData>::iterator StartIter = DataMap.begin();
    //    std::map<const char*, MonsterData>::iterator EndIter = DataMap.end();

    //    for (; StartIter != EndIter; ++StartIter)
    //    {
    //        // for가 키고
    //        // StartIter.operator->().first
    //        std::cout << "Key : " << StartIter->first << std::endl;
    //        std::cout << "Value : " << StartIter->second.Att << std::endl;

    //    }

    //}
    

    {
        std::map<int, int> DataMap;

        DataMap.insert(std::make_pair(10, 10));
        DataMap.insert(std::make_pair(2, 2 ));
        DataMap.insert(std::make_pair(5, 5 ));
        DataMap.insert(std::make_pair(7, 7 ));
        DataMap.insert(std::make_pair(8, 8 ));
        DataMap.insert(std::make_pair(3, 3 ));
        DataMap.insert(std::make_pair(20, 20));

        std::map<int, int>::iterator FindIter = DataMap.find(99);

        if (FindIter != DataMap.end())
        {
            FindIter->first;
            FindIter->second;
        }

        // std::map<int, int>::iterator DeleteNextIter = DataMap.erase(DataMap.find(15));
        //std::map<int, int>::iterator StartIter = DataMap.begin();
        //std::map<int, int>::iterator EndIter = DataMap.end();

        //for (; StartIter != EndIter; ++StartIter)
        //{
        //    std::cout << StartIter->first << std::endl;
        //}

        int a = 0;

    }

    {
        std::map<int, int> DataMap;

        DataMap.insert(std::make_pair(1, 1));
        DataMap.insert(std::make_pair(2, 1));
        DataMap.insert(std::make_pair(3, 1));
        DataMap.insert(std::make_pair(4, 1));
        DataMap.insert(std::make_pair(5, 1));
        DataMap.insert(std::make_pair(6, 1));
        DataMap.insert(std::make_pair(7, 1));
    }

    {
        GameEngineMap DataMap;

        DataMap.insert(make_pair(20, 1));
        DataMap.insert(make_pair(2, 1 ));
        DataMap.insert(make_pair(10, 1 ));
        DataMap.insert(make_pair(3, 1 ));
        DataMap.insert(make_pair(5, 1));
        DataMap.insert(make_pair(4, 1));
        DataMap.insert(make_pair(15, 1 ));
        DataMap.insert(make_pair(16, 1));
        DataMap.insert(make_pair(30, 1 ));
        DataMap.insert(make_pair(25, 1));

        GameEngineMap::iterator FindIter = DataMap.find(99);

        if (FindIter != DataMap.end())
        {
            FindIter->first;
            FindIter->second;
        }

        //std::cout << "전위 순회" << std::endl;
        //DataMap.FirstOrder();
        //std::cout << "후위 순회" << std::endl;
        //DataMap.LastOrder();
        //std::cout << "중위 순회" << std::endl;
        //DataMap.MidOrder();

        DataMap.erase(DataMap.find(15));


        GameEngineMap::iterator StartIter = DataMap.begin();
        GameEngineMap::iterator EndIter = DataMap.end();

        for (; 
            StartIter != EndIter; 
            ++StartIter
            )
        {
            if (StartIter->first == 8)
            {
                int a = 0;
            }

            std::cout << StartIter->first << std::endl;
        }


    }


}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

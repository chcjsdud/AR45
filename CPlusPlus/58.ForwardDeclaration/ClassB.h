#pragma once
// #include "ClassA.h"

// 전방선언
// 참조형이라고 해서 아무것도 안해줘도 되는건 아니고
// 클래스의 존재는 알려줘야 한다.
class ClassA;
class ClassB
{
public:
	// constrcuter destructer
	ClassB();
	~ClassB();

	// delete Function
	ClassB(const ClassB& _Other) = delete;
	ClassB(ClassB&& _Other) noexcept = delete;
	ClassB& operator=(const ClassB& _Other) = delete;
	ClassB& operator=(ClassB&& _Other) noexcept = delete;

	void BFunction()
	{

	}

protected:

private:
	ClassA* Object;
};


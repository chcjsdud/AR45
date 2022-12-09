#pragma once
// #include "ClassB.h"
// #include "ClassA.cpp"


// 전방선언
// 이런 클래스가 있을거야....
class ClassB;
class ClassA
{
public:
	// constrcuter destructer
	ClassA();
	~ClassA();

	// delete Function
	ClassA(const ClassA& _Other) = delete;
	ClassA(ClassA&& _Other) noexcept = delete;
	ClassA& operator=(const ClassA& _Other) = delete;
	ClassA& operator=(ClassA&& _Other) noexcept = delete;

	ClassB* ReturnBObject();

	void AFunction();
	//{
	//	// 헤더가 꼭 있어야 한다. 
	//	// Object->BFunction();
	//}

protected:

private:
	// 값형으로 가지고 있기 때문에.
	// 참조형으로 가지고 
	ClassB* Object;

};


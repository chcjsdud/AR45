#pragma once
#include <memory>

// Ό³Έν :
class B;
class A
{
public:
	std::shared_ptr<B> Ptr;

public:
	// constrcuter destructer
	A();
	~A();

	// delete Function
	A(const A& _Other) = delete;
	A(A&& _Other) noexcept = delete;
	A& operator=(const A& _Other) = delete;
	A& operator=(A&& _Other) noexcept = delete;

protected:

private:

};


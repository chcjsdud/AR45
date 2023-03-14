#pragma once
#include <memory>

// Ό³Έν :
class A;
class B
{
public:
	std::shared_ptr<A> Ptr;

public:
	// constrcuter destructer
	B();
	~B();

	// delete Function
	B(const B& _Other) = delete;
	B(B&& _Other) noexcept = delete;
	B& operator=(const B& _Other) = delete;
	B& operator=(B&& _Other) noexcept = delete;

protected:

private:

};


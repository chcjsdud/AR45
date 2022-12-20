#pragma once
#include <ConsoleGameObject.h>

// Ό³Έν :
class Part : public ConsoleGameObject
{
public:
	// constrcuter destructer
	Part();
	Part(wchar_t _Renderchar);
	~Part();

	// delete Function
	Part(const Part& _Other) = delete;
	Part(Part&& _Other) noexcept = delete;
	Part& operator=(const Part& _Other) = delete;
	Part& operator=(Part&& _Other) noexcept = delete;

	virtual void Update();

protected:

private:
	Part* Prev = nullptr;

};


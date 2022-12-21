#pragma once
#include "Part.h"

// Ό³Έν :
class Body : public Part
{
public:
	static void CreateBody();

	static Body* GetCurBody();

	// constrcuter destructer
	~Body();

	// delete Function
	Body(const Body& _Other) = delete;
	Body(Body&& _Other) noexcept = delete;
	Body& operator=(const Body& _Other) = delete;
	Body& operator=(Body&& _Other) noexcept = delete;

	void Update() override;

protected:

private:
	Body();

	static Body* CurBody;
};


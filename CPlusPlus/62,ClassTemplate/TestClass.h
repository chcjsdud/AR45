#pragma once

// 설명 :
template<typename DataType>
class TestClass
{
public:
	// constrcuter destructer
	TestClass();
	~TestClass();

	// delete Function
	TestClass(const TestClass& _Other) = delete;
	TestClass(TestClass&& _Other) noexcept = delete;
	TestClass& operator=(const TestClass& _Other) = delete;
	TestClass& operator=(TestClass&& _Other) noexcept = delete;

	// 템플릿 클래스의 함수는 헤더에서 구현해야만 한다.
	void Func() {

	}

protected:

private:
	DataType Value;

};


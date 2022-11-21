// 24.PointerEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void PtrFunction(int* _Ptr)
{

}

int main()
{
	// 포인터의 문법적 개념 => 어떤 자료형에 *이 붙은거다.
	// 100번지
	int Value = 0;
	// 위치 : 100번지
	// 크기 : 4바이트
	// 형태 : int
	// 값 : 0


	// 포인터는 자신에게서 *땐 자료형의 주소값을 받을수 있다.
	// int변수의 위치인 int*를 리턴해주는 연산자입니다.
	// &Value => 자신의 자료형에 *을 붙인 포인터형을 리턴하는것.
	// Value ==> 자료형이? int
	// int => int*
	// 이 개념은 절대로 바뀌지 않는다.
	// 200번지
	int* Ptr = &Value;

	// 위치 : 200번지
	// 크기 : 8바이트
	// 형태 : int*
	// 값 : 100번지

	PtrFunction(Ptr);
	PtrFunction(&Value);

	//             int**
	// PtrFunction(&Ptr);

	// 결국 그 Pointer라는 것은 뭐죠?
	// 64비트일때? 8바이트 정수
	// 문법적으로 완전히 같은 포인터형들끼리만 대입이 되지만.

	// int* <= 인트 포인터형 => 자료형

	// int*  <= int**
	// int* PPtr = &Ptr;
	//           int**
	// 300번지
	int** PPtr = &Ptr;
	// 위치 : 300번지
	// 크기 : 8바이트
	// 형태 : int**
	// 값 : 200번지

	// 400번지
	int*** PPPtr = &PPtr;
	// 위치 : 400번지
	// 크기 : 8바이트
	// 형태 : int**
	// 값 : 300번지

	// int        = int****
	int**** PPPPtr = &PPPtr;

	int size = sizeof(PPPPtr);


	// int****
	// int
	++(****PPPPtr) = 999;

	Value;

}

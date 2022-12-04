// 20.PointerOperator.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 100번지에 PlayerHp가 존재.
// 50번지
//          100       108      116

//           50번지
void Damage(int* _Hp, int Att)
{
	__int64 AddRess0 = (__int64)&_Hp;
	__int64 AddRess1 = (__int64)&Att;

	(*_Hp) -= Att;
	// Main에있는 PlayerHp -= Att;

	int a = 0;
}

void Test(int Test1, int Test2, int Test3)
{
	__int64 AddRess0 = (__int64)&Test1;
	__int64 AddRess1 = (__int64)&Test2;
	__int64 AddRess2 = (__int64)&Test3;
}




int main()
{
	{
		int Value = 10;

		int* ValuePtr = &Value;

		// 이 주소의 값에 직접 접근하고 싶어
		// *ValuePtr == Value;
		(*ValuePtr) = 20;
		// Value = 20;
	}

	{
		// 메인함수에 선언된 지역변수는 프로그램이랑 생명주기가 같다.
		int PlayerHp = 100;
		int MonsterAtt = 10;

		Damage(&PlayerHp, MonsterAtt);

		Test(10, 20, 30);
	}

	{
		// 300번지에 1바이트 크기의 메모리영역.
		// 1바이트 true
		// 40
		bool Value = true;

		// 400번지에 있는 8바이트 크기의 메모리영역.
		// 8바이트 300이 들어있습니다.
		bool* BoolPtr = &Value;

		*BoolPtr = false;

		int* IntPtr = (int*)Value;
	}

	{
		int Value = 0;
		int* TestPtr = &Value;

		// 내가 담고있는 주소값 + (정수 * sizeof(내가 가리키는 자료형))

		int* TestPlus0 = TestPtr + 1;
		__int64 Address0 = (__int64)TestPlus0;
		int* TestPlus1 = TestPtr + 2;
		__int64 Address1 = (__int64)TestPlus1;
		int* TestPlus2 = TestPtr + 3;
		__int64 Address2 = (__int64)TestPlus2;
		int* TestPlus3 = TestPtr + 4;
		__int64 Address3 = (__int64)TestPlus3;
		int* TestPlus4 = TestPtr + 5;
		__int64 Address4 = (__int64)TestPlus4;

		int a = 0;
	}

	{
		bool Value = 0;
		bool* TestPtr = &Value;

		// 내가 담고있는 주소값 + (정수 * sizeof(내가 가리키는 자료형))

		bool* TestPlus0 = TestPtr + 1;
		__int64 Address0 = (__int64)TestPlus0;
		bool* TestPlus1 = TestPtr + 2;
		__int64 Address1 = (__int64)TestPlus1;
		bool* TestPlus2 = TestPtr + 3;
		__int64 Address2 = (__int64)TestPlus2;
		bool* TestPlus3 = TestPtr + 4;
		__int64 Address3 = (__int64)TestPlus3;
		bool* TestPlus4 = TestPtr + 5;
		__int64 Address4 = (__int64)TestPlus4;
	}

	
		int Arr[10];

		for (int i = 0; i < 10; i++)
		{
			Arr[i] = i;
		}

		// 특정 자료형의 배열형은
		// 특정 자료형의 포인터로 변환이 가능하다.
		int* Ptr = Arr;
		
		int* Value1Ptr = (Ptr + 1);

		int Value11 = *Value1Ptr;
		

		// *(Ptr + 1);

		// 100 104 108 112 116 120 ..
		// [0] [1] [2] [3] [4] [5] [6][7][8][9]

		int Value0 = Ptr[0];
		int Value1 = Ptr[1];
		int Value2 = Ptr[2];
		int Value3 = Ptr[3];
		int Value4 = Ptr[4];
		int Value5 = Ptr[5];
		int Value6 = Ptr[6];
		int Value7 = Ptr[7];
		int Value8 = Ptr[8];
		int Value9 = Ptr[9];

		int* Ptr0 = Ptr + 0;
		int* Ptr1 = Ptr + 1;
		int* Ptr2 = Ptr + 2;
		int* Ptr3 = Ptr + 3;
		int* Ptr4 = Ptr + 4;
		int* Ptr5 = Ptr + 5;
		int* Ptr6 = Ptr + 6;
		int* Ptr7 = Ptr + 7;
		int* Ptr8 = Ptr + 8;
		int* Ptr9 = Ptr + 9;

		Value0 = *Ptr0;
		Value1 = *Ptr1;
		Value2 = *Ptr2;
		Value3 = *Ptr3;
		Value4 = *Ptr4;
		Value5 = *Ptr5;
		Value6 = *Ptr6;
		Value7 = *Ptr7;
		Value8 = *Ptr8;
		Value9 = *Ptr9;

		// 넘기지 말아야 합니다.
		// Ptr[50];

		int a = 0;
	

	{


		// 100      101      102      103
		// 00000000 00000000 00000000 00000001
		
		// 100      101      102      103
		// 00000001 00000000 00000000 00000000

		// 100
		int Value = 0b00000000000000000000000000000001;
		char* Ptr = (char*)&Value;

		char Value0 = Ptr[0];// 100
		char Value1 = Ptr[1];// 101
		char Value2 = Ptr[2];// 102
		char Value3 = Ptr[3];// 103

		int a = 0;
	}

	{
		// 여러분들이 변수를 보면 설명할수 있어야 하는 4가지 요소
		int Value = 10;
		// 1. 위치 => 주소값
		// 2. 형태 => 정수
		// 3. 크기 => 4바이트
		// 4. 값 => 10

		// 1. 위치 => 램의 어느 번지
		// 2. 형태 => 정수 
		// 3. 크기 => 4바이트
		// 4. 값 => 10

		// unsigned char의 최대 표현값은?
		// 0~255
		// r    g    b    a
		// 255, 255, 255, 255

		// 형태가 중요한 이유 + 
		// 함수나 연산자에서 이걸 어떻게 비트와 바이트를 연산할지 알려면
		// 정수인지 실수인지 뭔지를 알아야 해줄수 있으니까.

		// 크기에서 중요한점은 보통 대입을 하려고 할때 중요하다.
		// 크기가 큰곳에서 작은곳으로 대입하는일은 안합니다.
	}

	{
		// 100번지
		int Value = 10;
		// 1. 위치 => 100번지
		// 2. 형태 => 정수 
		// 3. 크기 => 4바이트
		// 4. 값 => 10

		// 200번지
		int* ValuePtr = &Value;
		// 1. 위치 => 200번지
		// 2. 형태 => 정수 주소값
		// 3. 크기 => 8바이트
		// 4. 값 => 100

		// 100번지에 20을 복사해라.
		*ValuePtr = 10;

		// 200번지에 20을 복사해라.
		ValuePtr = (int*)10;

		int* ValuePtr1;

		//__int64 Address = (__int64)ValuePtr12;

		int a = 0;
	}

}

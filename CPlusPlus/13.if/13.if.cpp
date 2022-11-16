// 13.if.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	{
		// 조건문
		// 메모리영역(변수)
		// /* 범위 주석 */
		// 컨트롤 kc를 누르면 자신이 범위로 지정한 영역에 주석을 걸어준다.

		// 참
		// 거짓

		if (0/*메모리 영역*/)
		{
			int a = 10;
			printf_s("조건에 들어왔습니다.");
		}

		// a = 20;

		if (/*bool Test =*/ -2)
		{
			printf_s("조건에 들어왔습니다.");
		}

		if (bool Test = true)
		{
			printf_s("조건에 들어왔습니다.");
		}

		int Hp = 100;
		// 선생님의 스타일
		if (0 <= Hp)
		{
			printf_s("조건에 들어왔습니다.");
		}

		if (0 == Hp)
		{
			printf_s("플레이어는 죽었습니다.");
		}

		//if (1 = Hp)
		//{
		//	printf_s("플레이어는 죽었습니다.");
		//}


		// 쉼표로 해서 내부에 넣어놓으면
		// 가장 오른쪽 조건만 체크한다.
		int Test = 0;
		Hp = 0;
		if (0 == Hp, Test)
		{
			printf_s("플레이어는 죽었습니다.");
		}
	}

	{
		int Value = 0;

		if (Value)
		{
			printf_s("조건이 참입니다.");
		}
		// 단독으로는 사용하지 못합니다.
		// 무조건 if 아래 연결해서 사용해야 합니다.
		else 
		{
			// if 조건들이 모두 거짓이라면
			// 실행된다.
			printf_s("조건이 거짓입니다.");
		}
	}


	{
		int Value = 0;

		if (Value)
		{
			printf_s("조건이 참입니다.");
		}
		// 단독으로는 사용하지 못합니다.
		// 무조건 if 아래 연결해서 사용해야 합니다.
		else if(1)
		{
			printf_s("조건이 참입니다1");
		}
		else if (false)
		{
			printf_s("조건이 참입니다2");
		}

		else if (true)
		{
			printf_s("조건이 참입니다3");
		}
		else
		{
			// if 조건들이 모두 거짓이라면
			// 실행된다.
			printf_s("조건이 거짓입니다.");
		}

		// if와 else if로 엮인 문법은 그중 참이 있다면 나머지 모든 조건은 무시됩니다.
		// 위에서 부터 읽어서 
	}

	{
		if(true)
			printf_s("조건이 참입니다.");
		else
			printf_s("조건이 거짓입니다.");
	}

}

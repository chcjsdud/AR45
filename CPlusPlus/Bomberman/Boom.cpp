
#include "Boom.h"
#include <conio.h>
#include "ConsoleGameScreen.h"
#include "player.h"
#include <Windows.h>
Boom::Boom()
{
	SetRenderChar(L'��');
}

Boom::~Boom()
{

}

void Boom::Update()
{
	if (0 > --Time)
	{
		return;
	}

	//   ��
	//   ��
	//�ڡڡݡڡ�
	//   ��
	//   ��

	// 1. ���������� ����� ������.
	// 1-1. ���� ������ �� �Ʒ��� 1�����̶� ���̰� �ض�.
	// 1-2. �׳� ����ũ�� ��ü�� ���̰� ������.
	// 1-3. �ð����� ������ ���̰� ������.
	// 
	// ���ڰ� ǥ�÷� ���� ������ �ϼ���.


	// 2. ������������� �ٸ� ��ź�� ������ ���� ��������.


	ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());
}



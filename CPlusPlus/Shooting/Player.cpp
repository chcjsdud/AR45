#include "Player.h"
#include <conio.h>

void Player::Update() 
{
	// ���� 1. ȭ�� �ٱ����� �������� ���弼��.
	// ���� 2. �ܻ� ���켼��.

	// �̰� ���ص� �˴ϴ�.
	// �̰͵� ���ߴ�.
	// ���� 3. ���͸� 1���� ���弼��.
	// ���� 4. �Ѿ��� 1�� ���弼��
	// ���� 5. �Ѿ��� ���͸� ������ �Ѵ� ������� �ϼ���.

	// ������ ���� �� �������� �˷��ִ� �Լ�.
	// ��¥ ������ ��

	if (0 == _kbhit())
	{
		return;
	}

	// ���α׷� �Է��� �ö����� ������?
	int Input = _getch();

	Int4 Left = {1, 0};

	switch (Input)
	{
	case 'a':
	case 'A':
		Move({-1, 0});
		break;
	case 'd':
	case 'D':
		Move({1, 0 });
		break;
	case 's':
	case 'S':
		Move({ 0, 1 });
		break;
	case 'w':
	case 'W':
		Move({ 0, -1 });
		break;
	default:
		break;
	}
}
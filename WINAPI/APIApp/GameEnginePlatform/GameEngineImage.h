#pragma once
#include <Windows.h>
#include <string_view>

// �̹�����
// => ��ǻ�Ϳ��� ���� �����̳� ũ�⸦ ������ �ִٸ�
// Ư�� ������� ������ �����ϰ� �ִ� bit�� �����ϼ� �ۿ� ����.
// �׷��� byte�� �����̶�� �Ҽ� �ִ�.
// ����.
// �̹����� �����ϼ��ۿ� ����

// ��� �̹����� 2������ ����ϸ� �˴ϴ�.
// 1. ���� �����ϳ��� �����Ʈ�� ��� ǥ���ߴ°�? ��� ������ RGBA�� ���ؼ� ǥ���մϴ�.
//    �� RGBA�� 1���� �����Ʈ�� �Ἥ ǥ���Ұųİ� �����Դϴ�.
//    Bitmap ������ RGBA�� ���� R�� 1����Ʈ�� ���ؼ� ǥ���մϴ�.
// 2. ������.
//    bitmap�� �������� �ʾ�.

// Bitmap�� ����ϸ� ���� 1062x1380 ¥�� int 2���� 
// int ArrBitMap[1380][1062]
// char Color[4]
// Color[0] == 255

// �̰� �����찡 �����ϱ� �����մϴ�.
// int ArrBitMap[1380][1062] <= �츮�� �̰� ���� ���ؿ�.
// �迭�� ���� ������ �Ҽ� �ִ� ������ �ִµ� �װ� HDC�̴�.
// HDC�� �׷��� ������ �迭�� ����Ǿ� �ְ�. �װ� �����Ҽ� �ְ� �����ִ� ����̴�.


// ���� :
class GameEnginePath;
class GameEngineImage
{
public:
	// constrcuter destructer
	GameEngineImage();
	~GameEngineImage();

	// delete Function
	GameEngineImage(const GameEngineImage& _Other) = delete;
	GameEngineImage(GameEngineImage&& _Other) noexcept = delete;
	GameEngineImage& operator=(const GameEngineImage& _Other) = delete;
	GameEngineImage& operator=(GameEngineImage&& _Other) noexcept = delete;

	bool ImageLoad(const GameEnginePath& _Path);

	bool ImageLoad(const std::string_view& _Path);


protected:

private:
	HDC ImageDC;
	HBITMAP BitMap;
	HBITMAP OldBitMap;
	BITMAP Info;

};


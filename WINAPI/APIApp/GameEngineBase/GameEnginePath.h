#pragma once
// c++�� ����Ǵ� ������ ����Ҽ� �ִ� ��� ���ڿ� ���� ó������� �������ش�.
#include <filesystem>

// ���� : ��ο� ���õ� ����� ��ǥ�ϴ� Ŭ����
class GameEnginePath
{
public:
	// constrcuter destructer
	GameEnginePath();
	~GameEnginePath();

	// delete Function
	GameEnginePath(const GameEnginePath& _Other) = delete;
	GameEnginePath(GameEnginePath&& _Other) noexcept = delete;
	GameEnginePath& operator=(const GameEnginePath& _Other) = delete;
	GameEnginePath& operator=(GameEnginePath&& _Other) noexcept = delete;

protected:

private:
	// �������ؼ� ������ �ʰ� �Ǿ����ϴ�.
	// std::string Path;
	std::filesystem::path Path;

};


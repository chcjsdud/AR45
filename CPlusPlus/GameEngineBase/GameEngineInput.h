#pragma once

// Ό³Έν :
class GameEngineInput
{

	

public:
	static int GetKey() 
	{
		return CurKey;
	}

	static bool GetIsInput()
	{
		return IsInput;
	}

	static void ConsoleInputCheck();

	// constrcuter destructer
	GameEngineInput();
	~GameEngineInput();

	// delete Function
	GameEngineInput(const GameEngineInput& _Other) = delete;
	GameEngineInput(GameEngineInput&& _Other) noexcept = delete;
	GameEngineInput& operator=(const GameEngineInput& _Other) = delete;
	GameEngineInput& operator=(GameEngineInput&& _Other) noexcept = delete;

protected:

private:
	static bool IsInput;
	static int CurKey;
};


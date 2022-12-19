#pragma once


class int4
{
public:
	static const int4 LEFT;
	static const int4 RIHGT;
	static const int4 UP;
	static const int4 DOWN;

public:
	int X = 0;
	int Y = 0;
	int Z = 0;
	int W = 0;

	// int랑 똑같이 만들려고
	int4& operator+=(const int4& _Value) 
	{
		X += _Value.X;
		Y += _Value.Y;
		Z += _Value.Z;
		W += _Value.W;
		return *this;
	}

	int4 operator+(const int4& _Value)
	{
		int4 Result = *this;
		Result.X += _Value.X;
		Result.Y += _Value.Y;
		Result.Z += _Value.Z;
		Result.W += _Value.W;
		return Result;
	}


	// 1 == 1 
	bool operator==(const int4& _Value)
	{
		return X == _Value.X && Y == _Value.Y;
	}

};
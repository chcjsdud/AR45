#pragma once


class int4
{
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
};
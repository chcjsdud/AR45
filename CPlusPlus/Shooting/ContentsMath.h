#pragma once

class Int4
{
	// 맴버변수가 전부다 public일 경우에는
public:
	int X = 0;
	int Y = 0;
	int Z = 0;
	int W = 1;

	//  1, 0
	// +1, 0
	Int4& operator +=(const Int4& _Value) 
	{
		X += _Value.X;
		Y += _Value.Y;
		Z += _Value.Z;
		W += _Value.W;

		return *this;
	}
};
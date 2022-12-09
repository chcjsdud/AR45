#include "Monster.h"

int Monster::AllMonsterCount = 0;

Monster::Monster() 
{
	++AllMonsterCount;
}

Monster::~Monster() 
{
}


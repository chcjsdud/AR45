#include "ClassA.h"
#include "ClassB.h"

ClassA::ClassA() 
{
}

ClassA::~ClassA() 
{
}

void ClassA::AFunction()
{
	// 헤더가 꼭 있어야 한다. 
	Object->BFunction();
}


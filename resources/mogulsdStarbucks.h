#pragma once
#include "Starbucks.h"

class mogulsdStarbucks
{
public:
	mogulsdStarbucks();
	void build(Entry* c, int n);
	Entry* getNearest(double x, double y);
	Entry* arrayData;
	int arrayLength;
};


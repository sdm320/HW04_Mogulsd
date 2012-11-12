#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "Starbucks.h"

using namespace ci;

class mogulsdStarbucks
{
public:
	mogulsdStarbucks();
	void build(Entry* c, int n);
	Entry* getNearest(double x, double y);
	Entry* arrayData;
	int arrayLength;
	void draw(Entry e);
	Vec2f center;
};


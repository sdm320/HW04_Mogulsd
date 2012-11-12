#include "mogulsdStarbucks.h"


mogulsdStarbucks::mogulsdStarbucks(void)
{
}

void mogulsdStarbucks::build(Entry* c, int n){
	arrayLength = n;
	arrayData = new Entry[n];
	for(int i=0;i<n;i++){
		arrayData[i] = c[i];
	}

}
void mogulsdStarbucks::draw(){
	gl::color(0,255,0);
	for(int i=0;i<arrayLength;i++){
		center = Vec2f(arrayData[i].x,1-(arrayData[i].y));
		gl::drawSolidCircle(center,1);
	}

}
Entry* mogulsdStarbucks::getNearest(double x, double y){
	Entry nearest  = arrayData[0];
	Entry* temp = new Entry();
	for(int i=0;i<arrayLength;i++){
		int myX = arrayData[i].x-x;
		int myY = arrayData[i].y-y;
		int nearestX = nearest.x-x;
		int nearestY = nearest.y-y;
		if(sqrt(pow(myX,2.0) + pow(myY,2.0))< sqrt(pow(nearestX,2.0) + pow(nearestY,2.0)))
		{
			nearest = arrayData[i];
		}
	}
	*temp = nearest;
	return temp;

}
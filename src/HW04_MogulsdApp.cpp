#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "Starbucks.h"
#include "mogulsdStarbucks.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>



using namespace ci;
using namespace ci::app;
using namespace std;

class HW04_MogulsdApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	ifstream myfile;
	string words;
	Entry* starbucksLocations;
	Entry* nearest;
private:
	static const int AppWidth=1000;
	static const int AppHeight=673;
	static const int TextureSize=1024;
	mogulsdStarbucks* starbucks;
	gl::Texture Map;


};

void HW04_MogulsdApp::setup()
{
	Map = gl::Texture(loadImage( "usa-map.gif"));
	starbucksLocations = new Entry[7700];
	myfile.open("Starbucks_2006.csv");
	words="";
	int i = 0;
	if(myfile.fail())
	{
		cout << "Error: main() ; Failed to open file: " << endl;
		
	}
	else
    {
		while(!myfile.eof()){
			getline(myfile, starbucksLocations[i].identifier,',');
			myfile>>starbucksLocations[i].x;
			myfile.get();
			myfile>>starbucksLocations[i].y;
			myfile.get();
			i++;
		}
		myfile.close();
		starbucks = new mogulsdStarbucks();
		starbucks ->build(starbucksLocations,7655);

	}
	
	
}

void HW04_MogulsdApp::mouseDown( MouseEvent event )
{
	if(event.isLeft()){
		Vec2f mouseLocation = event.getPos();
		double scaledX = mouseLocation.x/(AppWidth*.673);
		double scaledY = (AppHeight - mouseLocation.y)/(AppWidth*.673);

		Entry* nearest = starbucks -> getNearest(scaledX, scaledY);
		
		console() <<mouseLocation.x<<" "<<mouseLocation.y<<endl;
		console() <<scaledX<<" "<<scaledY<<endl;
		console() <<nearest->identifier<<" "<<nearest->x<<" "<<nearest->y<< endl;
		
	}
}

void HW04_MogulsdApp::update()
{
}

void HW04_MogulsdApp::draw()
{
	
	gl::draw(Map, getWindowBounds());
	

}

CINDER_APP_BASIC( HW04_MogulsdApp, RendererGl )

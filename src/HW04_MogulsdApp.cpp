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
private:
	static const int AppWidth=1000;
	static const int AppHeight=673;
	static const int TextureSize=1024;
	mogulsdStarbucks* starbucks;
	gl::Texture Map;
	Vec2f center;

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
			cout<<starbucksLocations[i].identifier<<endl;
			i++;
		}
		myfile.close();
		starbucks = new mogulsdStarbucks();
		starbucks ->build(starbucksLocations,7655);
		Entry* nearest = starbucks ->getNearest(.1,.1);
		cout<<nearest->identifier<<" "<<nearest->x<<" "<<nearest->y<<endl;
	}
	
}

void HW04_MogulsdApp::mouseDown( MouseEvent event )
{
}

void HW04_MogulsdApp::update()
{
}

void HW04_MogulsdApp::draw()
{
	//gl::color( Color(0,0,0));
	gl::draw(Map, getWindowBounds());

	/*for(int i = 0; i < 7655; i++){
		center = Vec2f();
		gl::color(40,140,9);
		gl::drawSolidCircle(center,5);
	}*/
}

CINDER_APP_BASIC( HW04_MogulsdApp, RendererGl )

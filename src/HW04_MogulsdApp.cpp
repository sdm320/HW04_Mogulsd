#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
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
	
};

void HW04_MogulsdApp::setup()
{
	
	ifstream myfile;
	myfile.open("../resources/Starbucks_2006.csv");
	string words="";
	if(myfile.fail())
	{
		cout << "Error: main() ; Failed to open file: " << endl;
		
	}
	else
    {
        string line;
        do
        {
            getline(myfile,line,',');
            
        } while (!myfile.eof());

        myfile.close();
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
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( HW04_MogulsdApp, RendererGl )

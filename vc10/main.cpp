#include "Starbucks.h"
#include "mogulsdStarbucks.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>


using namespace std;

int main(){
	ifstream myfile;
	string words;
	Entry* starbucksLocations;
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
		mogulsdStarbucks* starbucks = new mogulsdStarbucks();
		starbucks ->build(starbucksLocations,7655);
		Entry* nearest = starbucks ->getNearest(.1,.1);
		cout<<nearest->identifier<<" "<<nearest->x<<" "<<nearest->y<<endl;
	}






}
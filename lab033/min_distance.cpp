
#include <math.h>
#include <iostream>

using namespace std;
float distance(float x1, float x2, float y1, float y2);

int main(){

	float x_min, y_min, min_distance = 1000,temp;
	int length = 10;
	float points[length];

	points[0] =   4;
	points[1] =  16;
	points[2] =  32;
	points[3] =  15;
	points[4] = -12;
	points[5] = -14;
	points[6] =   2;
	points[7] =  87;
	points[8] =   0;
	points[9] =   0;

	
	
	/*
	for (short i=0; i<length; i=i+2)
	{
		for(short j=i+2; j<length; j=j+2)
		{
			temp = distance(points[i],points[j],points[i+1],points[j+1]);
			cout<< "I: " << i<< "  J: "<<j<<endl; 
			cout << "Temp: " << temp << endl;
			if(min_distance > temp){
				min_distance = temp;
				x_min = j;
				y_min = j+1;
			}
		}
	}
	*/

	cout << endl << "min_distance: "<< min_distance << endl;

}

float distance(float x1, float x2, float y1, float y2){

	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
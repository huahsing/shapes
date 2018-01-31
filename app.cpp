#include "circle.h"
#include "triangle.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;
using namespace myShapes;

int main() 
{
	int numOfCircles, numOfTriangles, numOfShapes;
	bool quit = false;
	char userinput;
	vector<Shape*> shapeList;
	
	srand(time(NULL));
	cout << "random number of circles and triangles between 5 to 10 will be generated" << endl;
	
	while(!quit)
	{
		numOfCircles = numOfTriangles= 0;
		numOfShapes = rand() % 6 + 5;
		
		for(int i = 0; i < numOfShapes; i++ )
		{
			int type = rand() % 2;
			
			switch(type)
			{
				case 0:
					shapeList.push_back(new Circle(rand() % 10 + 1));
					break;
					
				case 1:
					shapeList.push_back(new Triangle(rand() % 5 + 1, (double)rand()/(RAND_MAX)*M_PI+0.1, rand() % 5 + 1));
			}
		}
		
		cout << "Constructed -->" << endl;
		cout << "number of shapes: " << Shape::getTotalShapes() << endl;
		cout << "number of circles: " << Circle::getTotalCircles() << endl;
		cout << "number of polygons: " << Polygon::getTotalPolygons() << endl;
		cout << "number of triangles: " << Triangle::getTotalTriangles() << endl;
		
		for(int i = 0; i < shapeList.size(); i++ )
		{
			cout << "Shape " << i << ": " << shapeList[i]->getTypeName() << " : peri=" << shapeList[i]->perimeter() << ", area=" << shapeList[i]->area() << endl;
		}
		
		cout << "\nDestroying..." << endl;
		for(int i = 0; i < shapeList.size(); i++ )
		{
			delete shapeList[i];
		}
		shapeList.clear();
		
		cout << "\nagain? (y/n) : ";
		cin >> userinput;
		
		if(userinput == 'n') quit = true;
	}
	
	return 0;
}
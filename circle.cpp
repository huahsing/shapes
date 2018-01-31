#include "circle.h"
#include <cmath>

namespace myShapes {
	
int Circle::count = 0;
	
// note the below syntax, we make sure our constructor calls its parent class constructor because in our design,
// we need the typeName to be initialized
Circle::Circle() : Shape("Circle") 
{ 
	radius = 1.0; 
	++count; 
	CTORCHK(1); 
}

Circle::Circle(double radius) : Shape("Circle")  
{ 
	this->radius = radius; 
	++count; 
	CTORCHK(2); 
}

Circle::~Circle() 
{ 
	--count; 
	DTORCHK(); 
}

void Circle::setRadius(double radius) { this->radius = radius; }

// we can use the 'inline' keyword to suggest to the compiler to make a method inline
inline double Circle::getRadius() const { return radius; }

double Circle::perimeter() const { return 2 * M_PI * radius; }

double Circle::area() const { return M_PI * pow(radius, 2); }

};
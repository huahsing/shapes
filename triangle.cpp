#include "triangle.h"
#include <cmath>

namespace myShapes {

int Triangle::count = 0;

Triangle::Triangle(double side_a, double angle_ab, double side_b) : Polygon(3, "Triangle")
{
	sides[0] = side_a;
	angles[0] = angle_ab;
	sides[1] = side_b;
	
	// compute side c
	sides[2] = sqrt( pow(side_a, 2) + pow(side_b, 2) - (2 * side_a * side_b) * cos(angle_ab) );
	
	#define side_c sides[2]
	// compute angle_bc
	angles[1] = acos( (pow(side_b, 2) + pow(side_c, 2) - pow(side_a, 2) / 2 * side_b * side_c) );
	// compute angle_ac
	angles[2] = acos( (pow(side_c, 2) + pow(side_a, 2) - pow(side_b, 2) / 2 * side_c * side_a) );
	
	++count;
	CTORCHK(1);
}

Triangle::~Triangle() 
{	
	--count; 
	DTORCHK(); 
}

double Triangle::getSideA() const { return sides[0]; }
double Triangle::getSideB() const { return sides[1]; }
double Triangle::getSideC() const { return sides[2]; }
double Triangle::getAngleAB() const { return angles[0]; }
double Triangle::getAngleBC() const { return angles[1]; }
double Triangle::getAngleAC() const { return angles[2]; }
double Triangle::perimeter() const { return (sides[0] + sides[1] + sides[2]); }
double Triangle::area() const
{
	double p = (sides[0] + sides[1] + sides[2]) / 2;
	return sqrt(p * (p - sides[0]) * (p - sides[1]) * (p - sides[2]));
}

};
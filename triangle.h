#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "polygon.h"
// please look at 'Circle' class first if you haven't

namespace myShapes {
	
class Triangle : public Polygon {
private:
	static int count; 
	
public:
	// construct a SAS triangle
	Triangle(double side_a, double angle_ab, double side_b);
	~Triangle();
	
	double getSideA() const;
	double getSideB() const;
	double getSideC() const;
	double getAngleAB() const;
	double getAngleBC() const;
	double getAngleAC() const;
	double perimeter() const;
	double area() const;
	
	static int getTotalTriangles() { return count; } 
};

};

#endif // end __TRIANGLE_H__
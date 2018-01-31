#ifndef __POLYGON_H__
#define __POLYGON_H__

#include "shape.h"
// please look at 'Circle' class first if you haven't

namespace myShapes {
	
// this is also an abstract class
class Polygon : public Shape {
private:
	static int count;
	
protected:
	int numOfSides;
	
	// dynamic arrays: this is just to show example for dynamic allocations/deallocations
	// alternatively, we can use vectors for a cleaner implementation when we need a container for a list of items
	double *sides;
	double *angles;
	
	Polygon(int numOfSides, string typeName);		
	
	
public:
	virtual ~Polygon();
	
	virtual double perimeter() const = 0; 
	virtual double area() const = 0;
	
	static int getTotalPolygons() { return count; } 
};

};

#endif // end __POLYGON_H__
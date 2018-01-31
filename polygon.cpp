#include "polygon.h"
#include <cassert> 
// assert library can be used to help us perform simple debugging during development
// if an assert fails, the application will exit with a message
// advantage of using assert over "printf/cout/if else check for errors" 
//   eg:
//      if( something is false ) exit(1);
// is that, we do not need to manually remove or comment out the code;
// we can just pass in a flag "NDEBUG" during compilation to 'remove' the assert lines in the final machine code
// for more advanced error handling, we need to use Exceptions, which we may cover in future

namespace myShapes {
	
int Polygon::count = 0;
	
Polygon::Polygon(int numOfSides, string typeName) : Shape(typeName) 
{ 
	assert(numOfSides >= 3);
	this->numOfSides = numOfSides;
	// allocate dynamic arrays of sides and angles
	sides = new double[numOfSides];
	angles = new double[numOfSides];
	assert(sides != NULL && angles != NULL);
	++count;
	CTORCHK(1);
}

Polygon::~Polygon()
{
	if(sides) delete [] sides;
	if(angles) delete [] angles;
	--count;
	DTORCHK();
}

};
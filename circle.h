#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "shape.h"
// please look at 'Shape' class first if you haven't

namespace myShapes {
	
// since Circle is the same namespace as Shape, we do not need to import the "myShapes" namespace with "using"
class Circle : public Shape {
private:
	static int count; // we declare same attribute name again, but this 'count' belongs to the 'Circle' class
	double radius;

public:
	// note the below syntax, we make sure our constructor calls its parent class constructor because in our design,
	// we need the typeName to be initialized
	Circle();
	Circle(double radius);
	~Circle();

	// we don't need to have 'virtual' keyword here as we don't expect 'Circle' to be inherited
	// if it gets inherited, and we assign an instance of its child class to 'Circle' type variable,
	//   then when we call 'perimeter()' it will end up calling Circle's perimeter() and not the child class's perimeter()
	//   polymorphism feature in method overriding only gets activated when we use the 'virtual' keyword
	//   the 'virtual' keyword tells the compiler to resolve the function mapping during runtime
	void setRadius(double radius);
	double getRadius() const;
	double perimeter() const;
	double area() const;	
	
	static int getTotalCircles() { return count; } 
	// if we want to access parent's attribute of same name we use <Parent Classname>::<same attribute name> in the method
	// but in our case, it will not work because 'count' has been declared as 'private' in the parent class so it cannot be
	// accessed by anyone
};

};

#endif // end __CIRCLE_H__
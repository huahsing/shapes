#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <iostream>
#include <string>

using namespace std;

// create some flags to check constructor/destructor calls
#define CTOR_CHECK 1
#define DTOR_CHECK CTOR_CHECK

#if CTOR_CHECK
	#define CTORCHK(ctor_num) { cout << __FUNCTION__ << " constructor " << ctor_num << " called." << endl; }
#else
	#define CTORCHK(ctor_num) {}
#endif

#if DTOR_CHECK
	#define DTORCHK() { cout << __FUNCTION__ << " called." << endl; }
#else
	#define DTORCHK() {}
#endif


namespace myShapes {


// Shape is an abstract class because it has at least one unimplemented method
class Shape {
private:
	string typeName;
	
	// this is a static attribute for Shape 
	// (a static attribute has only one copy in the global application space, shared across all instances of the same class)
	// a static attribute must always be explicitly initialized in the source file
	// this attribute will be used to keep track of number of Shapes created.
	static int count;

	
protected:
	// make the constructor protected to hide it from non-derived classes (since this is an abstract class)
	// since the argument to the constructor has the same name as the class attribute 'typeName', 
	// we use the 'this' pointer (which refers to current instance) to qualify the class attribute
	//    : need to understand the difference between objects and class and the terms 'instance', 'instantiation'
	Shape(string typeName) 
		{ 
			this->typeName = typeName; 
			++count; 
			CTORCHK(1); 
		}
	

public:
	// destructors for classes to be inherited must always be virtual and public to avoid memory leaks
	virtual ~Shape() 
		{ 
			--count; 
			DTORCHK(); 
		}
		
	// unimplemented abstract methods that must be implemented by child classes
	// the keyword 'const' is optional here. It helps to improve the maintainability of our software.
	// when we use the keyword 'const' after a method name, it guarantees that the method will not modify the object's attributes
	// '= 0' after a method declaration tells us that the method is not implemented, thus making this class an 'abstract' class
	virtual double perimeter() const = 0; 
	virtual double area() const = 0;
	
	// this is an inline method (the above constructors and destructors are also inline methods)
	virtual string getTypeName() const { return typeName; }
	
	// this is a static method, which can only access other static attributes or methods,
	// to call it, it must be qualified by the class name instead of the instance name (instance name == variable name of a class)
	// eg: 
	//   cout << "Total shapes created: " << Shape::getTotalShapes() << endl;
	static int getTotalShapes() { return count; }
};

};

#endif // end __SHAPE_H__
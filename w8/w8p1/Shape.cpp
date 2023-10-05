/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8
// Version 1.0
// Description
// tester program
//
// Revision History
// -----------------------------------------------------------
// Name   Siripa Purinruk    Date 17/July/2023     Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
//I have done all the coding by myself and only copied the code that my 
//professor provided to complete my workshops and assignments.
#include <iostream>
#include "Shape.h"

namespace sdds {
	//virtual empty constructor
	Shape::~Shape() {};

	std::ostream& operator<<(std::ostream& os, const Shape& shape) {
		shape.draw(os);
		return os;
	};

	std::istream& operator>>(std::istream& is, Shape& shape) {
		shape.getSpecs(is);
		return is;
	};

}
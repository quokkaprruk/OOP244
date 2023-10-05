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
#include <string>
#include <iomanip>
#include "Line.h"

using namespace std;

namespace sdds {
	//private
	Line::Line():  LblShape(), m_length(0) {};
	Line::Line(const char* str, int len): LblShape(str){
		m_length = len;
	};
	//Line::~Line() {};

	void Line::getSpecs(std::istream& is) {
		
		LblShape::getSpecs(is);
		//read the length from input stream
		is >> m_length;
		is.ignore(1000, '\n');

	};
	void Line::draw(std::ostream& os) const{
		
		if (m_length > 0 && label() != nullptr) {
			os << label() << endl;
			int i = 0;
			while ( i < m_length) {
				os << '=';
				i++;
			}

		}
	
	};
}
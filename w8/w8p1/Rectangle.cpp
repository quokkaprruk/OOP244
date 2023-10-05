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
#include <iomanip>
#include "Rectangle.h"
#include <cstring>
//#include "cstring.h"

using namespace std;
namespace sdds {
	//int m_width;
	//int m_height;
	Rectangle::Rectangle() :  LblShape(), m_width(0), m_height(0) {};
	Rectangle::Rectangle(const char* str, int width, int height) : LblShape(str) {
		
		m_height = height;
		m_width = width;
		//error: m_width is signed signed and strlen return unsigned
		if (m_height < 3 || m_width < (int)strlen(label() + 2)) {
			//set rectangle to an empty state?
			m_width = 0;
			m_height = 0;
		}
	};
	
	//~Rectangle(); //no destructor to implement

	void Rectangle::getSpecs(std::istream& is) {
		LblShape::getSpecs(is);
		is >>  m_width;
		is.ignore();
		is >> m_height;
		is.ignore(1000, '\n');
		

	};
	void Rectangle::draw(std::ostream& os) const {
	//if rectangle is not in empty state
		if (m_width > 0 && m_height > 0 && label() != nullptr) {
			// First line
			os << '+';
			for (int i = 0; i < m_width - 2; i++) {
				os << '-';
			}
			os << '+' << endl;

			// Second line
			os << "|" ;
			os << left << setw(m_width - 2) << setfill(' ') << label();
			os << "|" << endl;

			// Next lines
			for (int i = 0; i < m_height - 3; i++) {
				os << "| ";
				os << right << setw(m_width - 2) << " |" << endl;
			}

			// Last line
			os << '+';
			for (int i = 0; i < m_width - 2; i++) {
				os << '-';
			}
			os << '+';
			
		}
	};
}
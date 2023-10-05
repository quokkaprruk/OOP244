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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "LblShape.h"
//#include "cstring.h"
#include <cstring>

using namespace std;

namespace sdds {
	
	//protected:
	const char* LblShape::label() const {
		return m_label;
	};

	//public:

	LblShape::LblShape(): m_label(nullptr) {};//already initialized also in .h file
	
	LblShape::LblShape(const char* newLabel) {
		if (newLabel != nullptr && newLabel[0] != '\0') {
			m_label = new char[strlen(newLabel) + 1];
			strcpy(m_label, newLabel);
		}

	};

	LblShape::~LblShape() {
		delete[] m_label;
		m_label = nullptr;
	};

	//cant copy = no implement
		//LblShape(const LblShape& src) = delete;
		//LblShape& operator=(const LblShape src) = delete;

	//implement the pure virtual function only this function
	void LblShape::getSpecs(std::istream& is) {
		
		string labelStr;
		getline(is, labelStr , ',');

		// Allocate memory for m_label and copy the label
		delete[] m_label; // Deallocate any existing memory
		m_label = new char[labelStr.length() + 1];
		strcpy(m_label, labelStr.c_str());

	};

	




}
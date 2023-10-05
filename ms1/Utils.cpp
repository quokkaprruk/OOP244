/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
//#include <string>
#include "Utils.h"
#include "Menu.h"
using namespace std;


namespace sdds {

	unsigned int getValidInteger(unsigned int min, unsigned int max) {
	
		unsigned value;
		bool result = false;

		do {
			cin >> value;
			if (!cin || value < min || value > max) {
				cout << "Invalid Selection, try again: ";
				cin.clear();
				cin.ignore(1000, '\n');
				result = false;
			}
			else {
				result = true;
			}
			
		} while (result == false);
		return value;//mistake: put outside of the loop!
	};

	int strLen(const char* s) {
		int length = 0;
		while (s[length] != '\0') {
			length++;
		}
		return length;
	}

	void strCpy(char* des, const char* src) {
		int i = 0;
		while (src[i] != '\0') {
			des[i] = src[i];
			i++;
		}
		des[i] = '\0';
	}

}
/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
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
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__

namespace sdds {
	unsigned int getValidInteger(unsigned int min, unsigned int max);
	// returns the lenght of the C-string in characters
	int strLen(const char* s);
	// Copies the srouce character string into the destination
	void strCpy(char* des, const char* src);
	
}
#endif // SDDS_UTILS_H__

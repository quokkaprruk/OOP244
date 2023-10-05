/*A module to hold the general utility functions for the applications. This file may be moved to 
other workshops and assignments if needed.*/
/*safe guard*/

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds {

	void flushkeys();
	bool ValidYesResponse(char ch);
	bool yes();
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);

}
#endif
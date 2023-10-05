#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include "Collection.h"
#include "ReadWrite.h"
#include "Car.h"
#include "Employee.h"
#include "Student.h"

namespace sdds {

	/* 
	T1* because T* m_data in Collection Class
	no const Collection<T1>& CP
	NOTE: 
	1. need operator== to do the comparison for both T1 and T2 because
	we declare T1 and T2 as a different data type...
	*/
	template <typename type1, typename type2>
	bool search(Collection<type1>& CP, type1* arrData, int size, const type2& keyValue) {
		bool result = false;

		for (int i = 0; i < size; i++) {
			if (arrData[i]==keyValue) {
			//if (keyValue== arrData[i] ) {
				CP.add(arrData[i]);
				result = true;
			}
		}
		return result;
	};

	/*
* search function template
* Template type requirements:
*   - The equality operator (==) must be defined for the type1 in the if condition (arrData[i]==keyValue).
*	- keyValue hasto be const to compare with the elements in the 'arrData' array
*
* listArrayElements function template
* Template type requirements:
*   - Must have an insert operator (<<) defined to print their values to the standard output stream.
*/

	

	template <typename type>
	void listArrayElements(const char* title, const type* arrObj, int size) {
		std::cout << title;
		std::cout << std::endl;
		for (int i = 0; i < size; i++) {
			if (arrObj) {

				std::cout << i + 1 << ": " << arrObj[i];
				std::cout << std::endl;
			}
		}
	};

}

#endif // !SDDS_SEARCHNLIST_H_



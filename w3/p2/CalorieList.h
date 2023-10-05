#ifndef SDDS_CALORIELIST_H
#define SDDS_CALORIELIST_H
#include "Food.h"

namespace sdds {
	class CalorieList {
	private:
		// sets the CalorieList to accept the "size" number of Food Items. 
		Food* f_items;
		int f_noOfItems;
		int f_itemsAdded;
		int totalCal()const;// private function

	public:
		void setEmpty();
		bool isValid()const;

		// This function is called to prepare the CalorieList for accepting food items
		void init(int size);

		// Adds Food Items using their Name, Calorie count and time of consumption up to 
		// the number set in the init() function, returns true if successful.
		bool add(const char* item_name, int calories, int when);

		//Title
		void Title() const;
		
		// Footer
		void Footer() const;
		// Displays the report with food information and the total calorie consumed in the day
		// as shown in the report sample
		void display()const;

		// Releases all the memory used. After this function init() can be called for another
		// report;
		void deallocate();
	};
}
#endif // !


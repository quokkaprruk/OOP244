//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <iomanip>
#include "CalorieList.h"
#include "cstring.h"
using namespace std;

namespace sdds {
//public:


	void CalorieList::setEmpty() {
		f_items = nullptr;//This is Item class
	};

	bool CalorieList::isValid()const {
		bool result = true;
		int flag = 0;

		//check f_items is not null and all items in f_items array are valid
		if (f_items != nullptr) {
			for (int i = 0; i < f_noOfItems && flag == 0; i++) {
				if (!f_items[i].isValid()) {
					result = false;
					flag = 1;
				}
			}
		}
		return result;
	};

	int CalorieList:: totalCal()const {
		int sum = 0;
		for (int i = 0; i < f_noOfItems; i++) {
			//calculate totalCal
			sum += f_items[i].calories();
		}
		return sum;
	};

	// This function is called to prepare the CalorieList for accepting food items
	void CalorieList::init(int size) {
		
		if (size > 0 /* && f_items != nullptr*/) {
			//assign size to f_noOfitems
			f_noOfItems = size;
			f_itemsAdded = 0;

			//allocate memory
			f_items = new Food[f_noOfItems];

			for (int i = 0; i < f_noOfItems; i++) {
				f_items[i].setEmpty();
			}
		}
		else {
			setEmpty();
		}
	};

	// Adds Food Items using their Name, Calorie count and time of consumption up
	// to the number set in the init() function, returns true if successful.
	bool CalorieList::add(const char* item_name, int calories, int when) {
		
		bool result = false;
		if (f_itemsAdded < f_noOfItems) {

			f_items[f_itemsAdded].set(item_name, calories, when);//***
			f_itemsAdded++;
					
			result = true;

		}		

		return result;
	};

	void CalorieList::Title() const{
		
		cout << "+----------------------------------------------------+\n";

		if (isValid()) {

			cout << "|  Daily Calorie Consumption                         |\n";
		}
		else {

			cout << "| Invalid Calorie Consumption list                   |\n";
		}
		cout << "+--------------------------------+------+------------+\n";
		cout << "| Food name                      | Cals | When       |\n";
		cout << "+--------------------------------+------+------------+\n";
	};

	void CalorieList::Footer() const {
		cout << "+--------------------------------+------+------------+\n";

		if (isValid()) {
			const int WIDTH = 6;
			cout << "|    Total Calories for today:   ";
			cout << right << setw(WIDTH) << setfill(' ') << totalCal();
			cout << " |            |\n";
		}
		else {

			cout << "|    Invalid Calorie Consumption list                |\n";
		}
		
		cout << "+----------------------------------------------------+\n";

	};


	// Displays the report with food information and the total calorie consumed in the day
	// as shown in the report sample
	void CalorieList::display()const {
		Title();
		for (int i = 0; i < f_noOfItems; i++) {
			f_items[i].display();
		}
		Footer();
	};

	// Releases all the memory used. After this function init() can be called for another
	// report;
	void CalorieList::deallocate() {
		delete[] f_items;
	};
}
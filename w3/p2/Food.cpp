//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <cstdio>
#include <iomanip>
#include "Food.h"
#include "cstring.h"

using namespace std;

namespace sdds {


	//MEMBER FUNCS
	void Food::setEmpty() {
		f_cal = -1;
		f_time = 0;
		f_name[0] = '\0';//setEmpty => blankstring 
	};

	bool Food:: isValid() const{

		//if one false = all false :use AND
		return ((f_cal >= 0 && f_cal <= 3000) && (f_time > 0 && f_time <= 4) && ( f_name[0] != '\0')); /* && f_name != nullptr)*/
	
	};

	void Food:: set(const char* newName, int newCal, int newTime) {

		//f_name = newName;
		if (newName == nullptr || newCal < 0 || newCal > 3000 || newTime <= 0 || newTime > 4) {
			setEmpty();
		}
		else {
			strnCpy(f_name, newName, sizeof(f_name) - 1);
			f_name[sizeof(f_name) - 1] = '\0';
			f_cal = newCal;
			f_time = newTime;
		}

		
	};


	int Food::calories()const {

		return f_cal;
	}

	void Food::display() const{
		
		if (isValid()) {
			const int NAME_WIDTH = 30;
			const int CALS_WIDTH = 4;
			const int TIME_WIDTH = 10;
			cout << "| ";
			cout << left << setw(NAME_WIDTH) << setfill('.') << f_name; 
			cout << " | " << right << setw(CALS_WIDTH) << setfill(' ')<< f_cal;
			cout << " | " << left << setw(TIME_WIDTH) << setfill(' ');
			
			switch (f_time) {

			case 1:
				cout << "Breakfast";
				break;
			case 2:
				cout << "Lunch";
				break;

			case 3:
				cout << "Dinner";
				break;

			case 4:
				cout << "Snack";
				break;

			} 
			cout << " |\n";
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |\n";
		}
	};
}
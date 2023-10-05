#include<iostream>
#include<string>
#include "cstring.h"
#include "MotorVehicle.h"
#include <iomanip>
using namespace std;
namespace sdds {
	//class MotorVehicle {
	/*
	private:
		char m_plateNum[MAX_PLATE_LEN];
		char m_location[MAX_LOC_LEN];
		int m_year;
		//can add anything 
	*/
	//public:
		//constr
	void MotorVehicle::setEmpty() {
		strCpy(m_plateNum, "");
		strCpy(m_location, "Factory");
		m_year = 0;
	};
	
	MotorVehicle::MotorVehicle() {
		setEmpty();
	};

	MotorVehicle::MotorVehicle(const char* licenPlate, const int year) {
		setEmpty();//m_location is "Factory"
		strnCpy(m_plateNum, licenPlate,MAX_PLATE_LEN-1);
		m_plateNum[MAX_PLATE_LEN - 1] = '\0';
		m_year = year;
	};

	void MotorVehicle::moveTo(const char* address) {
		if (strCmp(m_location, address) != 0) {
			cout << "|" << right << setw(8) << m_plateNum << "| ";
			cout << "|" << right << setw(20) << m_location << " ---> ";
			cout << left << setw(20) << address << "|" << endl;
			strnCpy(m_location, address,MAX_LOC_LEN-1);
			m_location[MAX_LOC_LEN - 1] = '\0';

		}

	};
	
	std::ostream& MotorVehicle::write(std::ostream& os ) const {
		os << "| " << m_year << " | ";
		os << m_plateNum << " | ";
		os << m_location;
		return os;
	};
	std::istream& MotorVehicle::read(std::istream& in) {
		cout << "Built year: ";
		in >> m_year;
		while (!in) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Inavalid";
			in >> m_year;
		}

		cout << "License plate: ";
		in >> m_plateNum;
		cout << "Current location: ";
		in >> m_location;

		return in;
	};
	

	//standalone func
	std::ostream& operator<< (std::ostream& os, const MotorVehicle& motor) {
		return motor.write(os);
	};
	std::istream& operator>> (std::istream& is, MotorVehicle& motor) {
		return motor.read(is);
	};
}

#include <iostream>
#include <iomanip>
#include "Truck.h"
#include "cstring.h"
using namespace std;
namespace sdds {
	//class Truck : public MotorVehicle {
		/*
		float capacity;
		float loadKg;
		*/

	//public:
	
	Truck::Truck():MotorVehicle() {
		MotorVehicle::setEmpty();
		t_capacity = 0.0;
		t_loadKg = 0.0;
	};
	/*
	Truck::Truck(float capa):MotorVehicle(const char* licenPlate, int year) {
	//can't!!!
	};
	*/
	Truck::Truck(const char* plateNum, int year, double capa, const char* address):
		MotorVehicle(plateNum, year) {
		//do we need this? motor already have it
		//MotorVehicle::setLicenPlate(plateNum); it will be set in the constructor
		//strCpy(m_location, address); //m_location is private in MotorVehicle
		MotorVehicle::moveTo(address);
		t_capacity = capa;
		t_loadKg = 0.0;


	}

	bool Truck::addCargo(double cargo) {
		
		bool result = false;
	 /*
		if (t_capacity - t_loadKg >= cargo) {
			t_loadKg += cargo;
			result = true;
		}
		else {
			result = false;
		}*/
		//cout << cargo << endl;
		if ( t_loadKg != t_capacity) {
			if(cargo >= t_capacity-t_loadKg){
				cargo -= t_capacity - t_loadKg;
				t_loadKg = t_capacity;	
				//cout <<cargo<<endl;
			}
			else { //cargo < dif
				t_loadKg += cargo;
				cargo = 0.0;
				//cout << cargo << endl;
			}
			
			result = true;
		}
		else {
			result = false;
		}


		return result;
	};
	bool Truck::unloadCargo() {
		bool result = false;
		if (t_loadKg != 0.0) {
			t_loadKg = 0.0;
			result = true;
		}
		return result;
	};
	std::ostream& Truck::write(std::ostream& os ) {
		MotorVehicle::write();
		os << " | " << t_loadKg << "/" << t_capacity;
		return os;
	};
	std::istream& Truck::read(std::istream& in) {
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> t_capacity;
		cout << "Cargo: ";
		in >> t_loadKg;

		return in;
	};


	std::ostream& operator<< (std::ostream& os, Truck& truck) {
		return truck.write(os);
	};
	std::istream& operator>> (std::istream& is, Truck& truck) {
		return truck.read(is);
	};

}

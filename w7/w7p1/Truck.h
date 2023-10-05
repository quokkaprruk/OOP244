#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H
#include "MotorVehicle.h"
namespace sdds {
	//hold the info of motorvehicle:inheritance
	class Truck : public MotorVehicle{
		double t_capacity{0.0};
		double t_loadKg{0.0};

	public:
		Truck();
		Truck(const char* plateNum, int year, double capa, const char* address);
		//Truck(float capa);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os = std::cout);
		std::istream& read(std::istream& in);
	};

	std::ostream& operator<< (std::ostream& os, Truck& truck);
	std::istream& operator>> (std::istream& is, Truck& truck);

}

#endif // !1




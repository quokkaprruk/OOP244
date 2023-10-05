#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H
#include <iostream>


namespace sdds {
	const int MAX_PLATE_LEN = 9;
	const int MAX_LOC_LEN = 64;
	class MotorVehicle {
		//holds information about a vehicle with an engine.
	private:
		char m_plateNum[MAX_PLATE_LEN]{'\0'};
		char m_location[MAX_LOC_LEN]{'\0'};
		int m_year{0};
		//can add anything 
	public:
		//added
		void setEmpty();
		
		//constr
		MotorVehicle();
		MotorVehicle(const char* licenPlate, const int year);

		void moveTo(const char* address);
		std::ostream& write(std::ostream& os = std::cout) const;
		std::istream& read(std::istream& in);

		
	};
	std::ostream& operator<< (std::ostream& os, const MotorVehicle& motor) ;
	std::istream& operator>> (std::istream& is,  MotorVehicle& motor);

}
#endif // !1
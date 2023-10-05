// Final Project Milestone 3
// Periodical Publication 
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name Siripa Purinruk              Date  20/July/2023               Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "Streamable.h"

namespace sdds {

	
	//class Streamable { 

	//pure virtual: no implementation
	//virtual std::ostream& write(std::ostream& os) const = 0;
	//virtual std::istream& read(std::istream& is) = 0;
	//virtual operator bool()const = 0;
	

	//virtual
	Streamable::~Streamable() {}; //doesn't perform any deallocation
	//bool Streamable::conIO(std::ios& iosObj)const {}; =>require must return a value
	// set to pure virtual function
	//can't implement because we we dont know the requirement
	

	//cant have default arg like ostream& os = std::cout
	std::ostream& operator<< (std::ostream& os, const Streamable& stream) {
		//can be written only when the object is valid****
		//if dont have this condition => error
		if (stream) {
			stream.write(os);
		}
		return os;
	};
	std::istream& operator>> (std::istream& is, Streamable& stream) {
		stream.read(is);
		return is;
	};
}
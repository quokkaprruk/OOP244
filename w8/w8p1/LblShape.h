#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include<iostream>
#include "Shape.h"

namespace sdds {
	class LblShape : public Shape {
		char* m_label{nullptr}; //initialize to nullptr

	protected:
		const char* label() const;
	public:

		LblShape();
		LblShape(const char* newLabel);
		~LblShape();

		//cant copy
		//cant declare parameter src for the abstract class!
		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape&) = delete;

		//implement the pure virtual function only this function
		void getSpecs(std::istream& is) override;

	};
}
#endif // !SDDS_LBLSHAPE_H


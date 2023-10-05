#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include<iostream>
#include "LblShape.h"


namespace sdds {
	class Line : public LblShape {
		int m_length; //hold the length of line
	public:

		Line();
		Line(const char* str, int len);
		//~Line(); //no destructor to implement

		void getSpecs(std::istream& is) override;
		void draw(std::ostream& os) const override;
	};

};
#endif // !SDDS_LINE_H


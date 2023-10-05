#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H 
#include <iostream>
#include "Label.h"
namespace sdds {

	class LabelMaker {
		int numLabel;
		Label* label;
	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();
	};
}
#endif // !1

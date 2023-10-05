#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
#include "cstring.h"
#include "LabelMaker.h"
#include "Label.h"
using namespace std;
namespace sdds {

	LabelMaker::LabelMaker(int noOfLabels) {
		numLabel = noOfLabels;
		label = new Label [numLabel];
	};

	void LabelMaker::readLabels() {

		cout << "Enter " << numLabel << " labels:" << endl;
		for (int i = 0; i < numLabel; i++) {
			cout << "Enter label number " << i + 1 << endl;
			cout << "> ";
			label[i].readLabel();
		}	
	};

	void LabelMaker::printLabels() {
		//using default frame from label.h

		for (int i = 0; i < numLabel; i++) {
			label[i].printLabel();
			cout << "\n";
		}
			
	};

	LabelMaker::~LabelMaker() {
		delete[] label;
	};
}
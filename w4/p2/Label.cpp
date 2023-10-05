#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "cstring.h"
#include "Label.h"
using namespace std;
namespace sdds {

	void Label::clearInputBuffer() {
		while (getchar() != '\n');
	};

	//function: to set the default label
	void Label::setDefaultLabel() {
		l_label = nullptr; //set to empty string
		l_frame = nullptr; 
		setLabelFrame("+-+|+-+|");
	};

	//function: to set label(the text) to non-default value
	void Label::setLabelContent(const char* content) {
	
		if (content != nullptr && content[0] != '\0') {
			
			int len = strlen(content);

			if (len <= 70) {
				delete[] l_label;
				l_label = new char[len + 1];
				strcpy(l_label, content);
				l_label[len] = '\0';
			}
			else {
				delete[] l_label;
				l_label = new char[71];
				strncpy(l_label, content,70);
				l_label[70] = '\0';		
			}
		}
		
	};

	void Label::setLabelFrame(const char* frameArg) {
		
		if (frameArg != nullptr && frameArg[0] != '\0') {
			delete[] l_frame; 
			l_frame = new char[strlen(frameArg) + 1];
			strcpy(l_frame, frameArg);
			l_frame[strlen(frameArg)] = '\0';
		}
		else {
			setDefaultLabel();
		}
	};

	//CONSTRUCTOR
	Label::Label() {
		setDefaultLabel();
	};

	Label::Label(const char* frameArg) {

		setDefaultLabel();
		setLabelFrame(frameArg);
	};

	Label::Label(const char* frameArg, const char* content) {
	
		//Creates a Label :
		setDefaultLabel();
		//1. the frame set to frameArg (fixed)
		setLabelFrame(frameArg);
		//2. the content of the Label set to the corresponding argument (dynamic)
		setLabelContent(content);
		
	};

	Label::~Label() {
	//deallocate
		delete [] l_label; ///why this always have a problem?
		delete[] l_frame;
	};

	void Label::readLabel() {
		char strContent[70 + 1];
		//Reads the label from console up to 70 characters
		scanf("%70[^\n]", strContent); // ***
		clearInputBuffer();
		setLabelContent(strContent);

	};

	
	std::ostream& Label::printLabel()const {
	//print

		if (l_label != nullptr && l_label[0] != '\0' && l_frame != nullptr && l_frame[0] != '\0') {
			
			int contentLen = strlen(l_label)+3;
			//line 1
			cout << l_frame[0];
			cout << setw(contentLen) << setfill(l_frame[1]);
			cout << l_frame[2] << endl;

			//line 2
			cout << l_frame[7] << setw(contentLen) << setfill(' ') << l_frame[3] << endl;

			//line 3
			cout << l_frame[7] << " " << l_label << " " << l_frame[3] << endl;

			//line 4
			cout << l_frame[7] << setw(contentLen) << setfill(' ') << l_frame[3] << endl;

			//line 5
			cout << l_frame[6];
			cout << setw(contentLen) << setfill(l_frame[5]);
			cout << l_frame[4];

		}
		
		return cout;
	};

	
}


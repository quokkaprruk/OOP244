/* Citation and Sources...
Final Project Milestone ?
Module: Menu
Filename: LibApp.cpp
Version 1.0
Author	Siripa Purinruk
Revision History
-----------------------------------------------------------
Date      Reason
2023/July/10
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include <string>
#include "LibApp.h"

using namespace std;
namespace sdds {
	/*
	class LibApp {
		Menu m_mainMenu = "Seneca Libray Application"; //insertion operator
		Menu m_exitMenu = "Changes have been made to the data, what would you like to do?";
		bool m_changed = false;
		//LibApp is  friend of Menu
	*/

	//private method:
	bool LibApp::confirm(const char* message) {

		bool result = false;
		Menu menu(message);
		
		menu << "Yes";
		unsigned value = menu.run();
		if (value == 1) {
			result = true;
		}
		return result;
	};

	// prints: "Loading Data"<NEWLINE>
	void LibApp::load() {
		
		cout << "Loading Data\n";
	};

	// prints: "Saving Data"<NEWLINE>
	void LibApp::save() {

		cout << "Saving Data\n";
	};

	// prints: "Searching for publication"<NEWLINE>
	void LibApp::search() {
		
		cout << "Searching for publication\n";
	};

	void LibApp::returnPub() {
		search();
		cout << "Returning publication\n";
		cout << "Publication returned\n" << endl;
		m_changed = true;
	};

	void LibApp::newPublication() {
		cout << "Adding new publication to library" << endl;

		bool ok = confirm("Add this publication to library?");
		if (ok == true) {
			m_changed = true;
			cout << "Publication added" << endl;
		}
		cout << endl;
	};

	void LibApp::removePublication() {
		cout << "Removing publication from library" << endl;
		search();

		bool ok = confirm("Remove this publication from the library?");
		if (ok == true) {
			m_changed = true;
			cout << "Publication removed" << endl;
		}
		cout << endl;
	};
	
	void LibApp::checkOutPub() {
		search();
	
		bool ok = confirm("Check out publication?");
		if (ok == true) {
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
		cout << endl;
	};
	
	//public: Constructor
	LibApp::LibApp():m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?") {
		
		//(m_mainMenu.m_title is initialized in .h file) => error use of deleted function
		//(m_exitMenu.m_title is initialized in .h file) => error use of deleted function
		m_changed = false;
		//populates mainMenu item
		m_mainMenu << "Add New Publication" << "Remove Publication";
		m_mainMenu << "Checkout publication from library" << "Return publication to library";

		//populates exitMenu item
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

		load();
		
	};
	
	std::ostream& LibApp::run(std::ostream& os) {
		unsigned selectMainmenu;
		unsigned selectExitmenu;
		
		do {

			selectMainmenu = m_mainMenu.run();//will disply title, menu, check validInt

			switch (selectMainmenu) {
			case 1: newPublication();
				break;
			case 2: removePublication();
				break;
			case 3: checkOutPub();
				break;
			case 4: returnPub();
				break;
			case 0:
				if (m_changed == true) {

					selectExitmenu = m_exitMenu.run();
					switch (selectExitmenu) {
					case 0:
						if (confirm("This will discard all the changes are you sure?")) {
							m_changed = false;
						}
						break;
					case 1: save();
						break;
					case 2: //discard selected(goback to main menu)
						//before going to main => confirm first
						selectMainmenu = 1;
						break;
						      
					}
				}
cout << endl;
				break;
		
			}
		} while (selectMainmenu != 0);
		
		cout << "-------------------------------------------\n"
				"Thanks for using Seneca Library Application\n";
		return os;
	};



}

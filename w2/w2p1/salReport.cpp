/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop  Part 2
// Version 1.0
// Description
// professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name                  Date            Reason
//Siripa Purinruk       23/05/2023 
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "Employee.h"
using namespace sdds;
int main() {
    if (load()) { //load() is in employee.h
        display(); //display need to be created in employee.h
    }
    deallocateMemory();
    return 0;
}
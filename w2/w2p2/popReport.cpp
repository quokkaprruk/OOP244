/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 2 Part 2
// Version 1.0
// Description
// professor's tester program
//
// Revision History
// --------------------------------------------------------------------
// Name Siripa Purinruk           Date 23/05/2023           Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Population.h"
using namespace sdds;
using namespace std;
int main() {

    //if successfully load
   if (load("PCpopulations.csv")) {
      display();
   }
   deallocateMemory();
   return 0;
}
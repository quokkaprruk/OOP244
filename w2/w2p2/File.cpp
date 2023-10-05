#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "File.h"
using namespace std;

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   
   //read postalcode
   bool read(char postCode[]) {
       bool success = fscanf(fptr, "%[^,],", postCode) == 1;
       return success;
   };

   //read number of population
   bool read(int& noPoppulation) {

       bool success = fscanf(fptr, "%d\n", &noPoppulation) == 1;
       return success;
 
   };
}
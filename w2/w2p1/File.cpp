#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

//add


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
            noOfRecs += (ch == '\n');//if ch == '\n', increment noOfRecs by 1
        }
        rewind(fptr);//reset the pointer to the beginning of the file
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr); //checks if the fptr file pointer is not NULL, fclose is called to close the file
        /*if (fptr) { 
            fclose(fptr); 
        }
        */
    }

    // TODO: read functions go here
    bool read(char m_name[]) { // accepts as a parameter the address of an array of characters.
    
        //             comparison=> result 1 or 0 => becomes bool (true,false)  
        bool success = fscanf(fptr, "%[^\n]\n", m_name) == 1;//read until meet the [,]. then, "," to consume the comma and move the ptr to the next position
        return success;
    };

    bool read(int& m_empNo) { //accepts as a parameter a reference to an integer representing the employee number.
        bool success = fscanf(fptr, "%d,", &m_empNo) == 1; // don't forget &
        return success;
    };

    bool read(double& m_salary) { //accepts as a parameter a reference to an floating point number in double precision representing the employee's salary. 
        bool success = fscanf(fptr, "%lf,", &m_salary) == 1;
        return success;
        
    };
    
}
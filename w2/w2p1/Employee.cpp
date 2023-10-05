#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"

using namespace std;
namespace sdds {

    //Global
    int noOfEmployees;// Holds the number of records (employees) in the file.
                      // Should be used (after setting) to allocate the dynamic array of Employees.
    Employee* employees; // Stores the address of a dynamically-allocated array of employees.
                         // The size of the array is "noOfEmployees".


    // sorts the array of employees based on the employee number.
    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(Employee& employees) {
        bool ok = false;
        char name[128];
        /* if reading of employee number, salay and name are successful
                allocate memory to the size of the name + 1
                and keep its address in the name of the Employee Reference

                copy the name into the newly allocated memroy

                make sure the "ok" flag is set to true
           end if
        */
        
        //read temporary variable: name
        if (read(employees.m_empNo) && read(employees.m_salary) && read(name)) {

            //1. find actual length of employee name using strlen
            int nameLen = strLen(name)+1;

            /*char* m_name */
            //step 1: allocate memory
            //don't know the size of emplyees.m_name 
            employees.m_name = new char[nameLen];
           
            //step 2: copy string
            strCpy(employees.m_name, name);

            //change ok flag
            ok = true;
        }

        return ok;
    }

    // TODO: Finish the implementation of the 0 arg load function 
    bool load() {
        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE)) { //if open file successfully => true
            /*
             Set the noOfEmployees to the number of recoreds in the file.
             dyanamically allocated an array of employees into the global
             Employee pointer; "employees" to the size of the noOfEmployees.

             In a loop load the employee records from the file into
             the dynamic array.

             If the number of the records does not match the number of reads
                print the message
               "Error: incorrect number of records read; the data is possibly corrupted"
             Otherwise
                set the ok flag to true
             End if

             close the file
             */
             //setting 
            noOfEmployees = noOfRecords();// int

            //allocate dynamic memory
            employees = new Employee[noOfEmployees];

            //loop: load the employee records from the file into the dynamic array.
            for (i = 0; i < noOfEmployees; i++) {

                if (load(employees[i])) {// why it said overload?=> function with the same name but has different parameter
                    ok = true;
                }
                else {
                    cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
                }
            }

        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }

        closeFile();
        return ok;
    };

    // TODO: Implementation for the display functions go here
    //displays a employee record on the screen:
    void display(Employee& employees) {
    //NUMBER: NAME, SALARY<NEWLINE>
       
            printf("%d: %s, ", employees.m_empNo, employees.m_name);
           //check if the first two precision of salary < 0.05? => if yes, display .0lf
            printf(((employees.m_salary - (int)employees.m_salary) < 0.05 || (employees.m_salary - (int)employees.m_salary) >= 0.95) ? "%.0lf\n" : "%.1lf\n", employees.m_salary);
           //ex. 5000.95 => 5001
           //ex. 5000.05 => 5000.1
    };

    //another display function
    void display() {
        cout << "Employee Salary report, sorted by employee number\n"
            "no- Empno, Name, Salary\n"
            "------------------------------------------------\n";

        //sort the array
        sort();

        //iterate over the sorted array
        for (int i = 0; i < noOfEmployees; i++) {
            printf("%d- ", i + 1); 
            display(employees[i]);
        }

    };

    // TODO: Implementation for the deallocateMemory function goes here
    //deallocate all the memory used by the the dynamic array of employees 
    //(make sure to also deallocate the names).
    void deallocateMemory() {

        //deallocate employee name
        int i ;
        for (i = 0; i < noOfEmployees; i++) {
            delete[] employees[i].m_name;
        }

        //deallocate size of struct Employees, which is noOfemplyees
        delete[] employees;
       
    };


}
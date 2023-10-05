#include <iostream>
#include "cstring.h"
#include "Population.h"
#include "File.h"
using namespace std;
namespace sdds {

    int noOfPostCode;
    Population* population;
    int i;

    //where should this function be placed
    //sort the population number
    void sort() {
        int i, j;
        Population temp;
        
        for (i = noOfPostCode-1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (population[j].noPopulation > population[j + 1].noPopulation) {
                    temp = population[j];
                    population[j] = population[j+1];
                    population[j + 1] = temp;
                }
            }
            
        }
    //change the order of postCode that match the number of population
    
    };

    bool load(Population& population) {

        //read function to read string in file.cpp
        //bool read(char code[]);
        //read function to read int in file.cpp
        //bool read(int& noPoppulation);

        bool ok = false;
        if (read(population.postCode) && read(population.noPopulation)) {
            ok = true;
        }
        return ok;
    };

    //created function 2:
    bool load(const char filename[]) {
        bool ok = false;
        
        //if successfully open the file
        if (openFile(filename)) { //PASSED

            //find number of Records
            noOfPostCode = noOfRecords();

            //allocate dynamic memory(the size of Population)
            population = new Population[noOfPostCode];

            
            //function overloading: load => read data and store data
            for (i = 0; i < noOfPostCode; i++) {
                //read number of records
                /* if (read(population[i].postCode) && read(population[i].noPopulation)) {
                    ok = true;
                }*/
                if (load(population[i])) {
                    ok = true;
                }
                else {
                    cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
                }
            }
            closeFile();
            
        }
        else {
            cout << "Could not open data file: " << filename << endl;

        }

        return ok;
    };



    //void display receive Population object
    void display(Population& population) {
        cout << population.postCode << ":  " << population.noPopulation << endl;
    }

    //display with no parameter
    void display() {

        cout << "Postal Code: population\n"
                "-------------------------\n";
        
        //sort array
        sort();

        int i; int total = 0;
        for (i = 0; i < noOfPostCode; i++) {
            cout << i + 1 << "- ";
            display(population[i]);
            //sum the total population
            total += population[i].noPopulation;
        }
        cout << "-------------------------\n";

        cout << "Population of Canada: " << total << endl;
    };
    
    //deallocate function
    void deallocateMemory() {
    
        delete[] population;
    };

}
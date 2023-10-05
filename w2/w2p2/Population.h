#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
#include "File.h"

namespace sdds {

	struct Population
	{
		char postCode[4];//fixed size, all postal code has 3 characters + '\0'
		int noPopulation;
	};

	//to sort the number of population
	void sort();

	//to check whether successfully read each data + records int array
	bool load(Population& population);

	//to check whether can open the file + allocates the dyanmic array of population size
	bool load(const char filename[]);

	//display each record 
	void display(Population& population);

	//sort + display all population records 
	void display();

	//deallocate the population array
	void deallocateMemory();

}
#endif // SDDS_POPULATION_H_
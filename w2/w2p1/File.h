#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);//open data file for reading
	void closeFile();
	int noOfRecords();//returns number of records
	
	
	// TODO: Declare read prototypes
	bool read(char m_name[]); // accepts as a parameter the address of an array of characters.

	bool read(int& m_empNo); //accepts as a parameter a reference to an integer representing the employee number.

	bool read(double& m_salary); //accepts as a parameter a reference to an floating point number in double precision representing the employee's salary. 

}
#endif // !SDDS_FILE_H_

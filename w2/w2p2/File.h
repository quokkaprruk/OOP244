#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();

   //read postalcode
   bool read(char code[]);

   //read number of population
   bool read(int& noPoppulation);
}
#endif // !SDDS_FILE_H_

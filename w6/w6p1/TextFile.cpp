#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
    Line::operator const char* () const {
        //it initializes the m_value pointer to a null value.
        return (const char*)m_value;
    }
    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;
        m_value = new char[strLen(lineValue) + 1];
        strCpy(m_value, lineValue);
        return *this;
    }

    Line::~Line() {
        delete[] m_value;
    }
    /*
    Line::Line() {
        m_value = nullptr;
    } do not need to add a default constructor
    because in .h already provides a default constructor in the class definition*/

   //class TextFile
   /*
   //A pointer to hold the dynamic array of Lines. 
   //This attribute should be initialized to nullptr
    Line* m_textLines;

    //hold the dynamic Cstring holding the name of the file. 
    //This attribute should be initialized to nullptr
    char* m_filename;

    // unsigned integer to be set to the number of lines in the file.
    unsigned m_noOfLines;

    //page size is the number of lines that should be displayed on the screen before the display is paused. After these lines are displayed, 
    //the user must hit enter for the next page to appear.
    unsigned m_pageSize;
    */
//private
    void TextFile::setEmpty() {
        delete[] m_textLines;
        m_textLines = nullptr;

        delete[] m_filename;
        m_filename = nullptr;
        m_noOfLines = 0;
    };
    void TextFile::setFilename(const char* fname, bool isCopy ) {
        if (!isCopy) {
            m_filename = new char[strLen(fname) + 1];
            strCpy(m_filename, fname);
        }
        else {
            const char* prefix = "C_";
    
            m_filename = new char[strLen(fname)+strLen(prefix) + 1];
            strCpy(m_filename, prefix);
            strCat(m_filename, fname);
            //cout << m_filename;
        }
    };
    
    void TextFile::setNoOfLines() {
        //the problem is the filename is changed...
        
        ifstream file(m_filename); //ifstream: is used for reading input from files
        char ch;
        if (file.is_open()) {
            while (file.get(ch)) { // get: read one char at a time
                if (ch == '\n')
                {
                    m_noOfLines++;
                }
            }
            //case: the last line doesn't have a new line character
            if (m_noOfLines > 0 && ch != '\n') {
                m_noOfLines++;
            }

        } else {
            delete[] m_filename;
            m_filename = nullptr;
        }
        
        
        
    };
    void TextFile::loadText() {
        if (m_filename != nullptr) {
            delete[] m_textLines;
            m_textLines = new Line[m_noOfLines];

            ifstream file(m_filename);

            //read the line using a local C++ string object and the getline helper function. 
            //create string object
            string line;
            unsigned int lineCount = 0; //lineCount = non-negative value

            //read lines from "files"(input stream) and stores it in "line" string
            if (file.is_open()) {
                while (getline(file, line)) {
                    m_textLines[lineCount] = line.c_str();//c_str(): convert string obj to the character array
                    lineCount++;
                }
                m_noOfLines = lineCount;
            }
           
            
        }
    };
    void TextFile::saveAs(const char* fileName)const {
        //use ofstream obj to open new file
        ofstream newfile(fileName);

       // if (newfile) { //open successfully
        if (newfile.is_open()) {
            for (unsigned i = 0; i < m_noOfLines; i++) {
                //each line of m_textLines[i] is written to the newfile
                newfile << m_textLines[i] << endl; //need the operator <<
            }
        }
       // newfile.close();
    };
    
//public
    //constructor
    TextFile::TextFile(unsigned pageSize ) {
        //create empty textFile
        setEmpty();
        m_pageSize = pageSize;
    };
    TextFile::TextFile(const char* filename, unsigned pageSize) {
       
        setEmpty();
        m_pageSize = pageSize;
        if (filename) {
            setFilename(filename); 
            setNoOfLines();
            loadText();
        }
    };
    //rule of three implementation
    TextFile::TextFile(const TextFile& src) {
       
       setEmpty();
       m_pageSize = src.m_pageSize;
       
       if (this != &src) {
           if (src.m_filename && src.m_textLines && src.m_noOfLines > 0) { 

               setFilename(src.m_filename, true);
               //save the content of the incoming text file:allocate again?
               m_noOfLines = src.m_noOfLines;
               
               m_textLines = new Line[m_noOfLines];
               
               for (unsigned int i = 0; i < m_noOfLines; i++) {
                   m_textLines[i].m_value = new char[strLen(src.m_textLines[i].m_value) + 1];
                   strCpy(m_textLines[i].m_value, src.m_textLines[i].m_value);
               }
               saveAs(m_filename); // changed from m_filename
              
           }
       }
    };
    TextFile& TextFile::operator=(const TextFile& src) {
        
  
        if (this != &src) {
          
            if (src.m_filename && src.m_textLines && src.m_noOfLines > 0 && *this) { 

                //deallocate the dynamic array of Textand sets the pointer to null
                if (m_textLines != nullptr) {
                    delete[] m_textLines;
                    m_textLines = nullptr;
                }
                m_pageSize = src.m_pageSize; 
               
                //save the content of the incoming text file:allocate again?
                m_noOfLines = src.m_noOfLines;
                m_textLines = new Line[m_noOfLines];

                for (unsigned i = 0; i < m_noOfLines; i++) {
                    m_textLines[i].m_value = new char[strLen(src.m_textLines[i].m_value) + 1];
                    strCpy(m_textLines[i].m_value, src.m_textLines[i].m_value);
                }
                saveAs(m_filename); // changed from m_filename

            }
        }
        return *this;
    };
    //destructor
    TextFile::~TextFile() {
        delete[] m_textLines;
        m_textLines = nullptr;

        delete[] m_filename;
        m_filename = nullptr;
    };

    unsigned TextFile::lines()const {
        return m_noOfLines;
    };

   
    std::ostream& TextFile::view(std::ostream& ostr)const {
        
        if (m_filename && m_filename[0] != '\0') { //valid both
            ostr << m_filename << endl;

            ostr << setw(strLen(m_filename)) << setfill('=') << "=" << endl;
           
            for (unsigned i = 0; i < m_noOfLines; i++) {

                ostr << m_textLines[i] << endl;

                // Pause after printing "m_pageSize" lines ???????
                if ((i + 1) % m_pageSize == 0) {
                    ostr << "Hit ENTER to continue...";
                    //ostr.flush();
                    //char newline;
                    //cin.get(newline);// why need 2 enter???
                    //add
                    std::cin.ignore(1000, '\n');
                   
                }
            }
        }
        return ostr;
    };

    std::istream& TextFile::getFile(std::istream& istr) {
       /*
       char filename[50]; 
       istr.getline(filename, sizeof(filename));
       */
        string filename;
        //read line from input istr and stores it in "filename" str.
        getline(istr, filename);
        setFilename(filename.c_str());
        setNoOfLines();
        loadText();
        return istr;
    };

    TextFile::operator bool()const {
        //return true if it's not empty state
        return m_filename != nullptr && m_textLines != nullptr && m_noOfLines > 0;
    };
   
    const char* TextFile::name()const {
        return m_filename;
    };

    
    const char* TextFile::operator[](unsigned index)const {
        const char* result = nullptr;

        if (*this) { //valid?????
            if (index >= m_noOfLines) {
                index -= m_noOfLines;
               
            }
            result = m_textLines[index].m_value;
        }
        
        return result;
    };


//out of class
    std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
        text.view(ostr);

        return ostr;
    };
    std::istream& operator>>(std::istream& istr, TextFile& text) {
        text.getFile(istr);
       
        return istr;
    };

   
   
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Text.h"
using namespace std;
namespace sdds {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   /*
   Mandatory functionalities
if anything goes wrong in setting up the class or 
reading a file, it will be set to an empty state.
   */
   void Text::setEmptyState() {
       delete[] m_filename; 
       m_filename = nullptr;
       delete[] m_content;
       m_content = nullptr;
       //getFileLength();

   };

   const char* Text::getContent() const {
       return m_content;
   }
//protected:NOT SURE!
   const char& Text::operator[](int index)const { //provides read-only access to the content of the text for the derived classes of Text.
   
       //The behaviour of the operator is not defined if the index goes out of bounds.
      /*
       int len = strlen(m_content);
       if (index < 0 || index >= len) {
         
               return m_content[index];
       }
      */ 
       return m_content[index];
   }; 

//public:
   //constructor
   Text::Text(const char* filename) :m_filename(nullptr), m_content(nullptr) {
       //setEmptyState(); ////set empty first: initialize filename and content
       //initialize m_file name
       if (filename != nullptr && filename[0] != '\0') {

           m_filename = new char[strlen(filename) + 1];
           strcpy(m_filename, filename);
       }
       

   };

    //rule of three
 
    Text::Text(const Text& src):m_filename(nullptr), m_content(nullptr) {
        //setEmptyState();
        if (this != &src) {
            
            if (src.m_filename != nullptr && src.m_filename[0] != '\0') {
                m_filename = new char[strlen(src.m_filename) + 1];
                strcpy(m_filename, src.m_filename);

                read(); //read content in the new file name

               
            }
        }
    
    };
    Text& Text::operator=(const Text& src) {
    
        if (this != &src) {
            if (m_filename) { //!= nullptr
                setEmptyState();
            }
            
            if (src.m_filename != nullptr && src.m_filename[0] != '\0') {
               //allocate memory for filename
                m_filename = new char[strlen(src.m_filename) + 1];
                strcpy(m_filename, src.m_filename);
                
                read();//for m_content 
            }
        }
        return *this;
    };

    Text::~Text() {
        //deallocate
        delete[] m_filename;
        m_filename = nullptr;
        delete[] m_content;
        m_content = nullptr;

    };

    /*check read function!!!*/
    void Text::read() {
        
        if (m_filename != nullptr && m_filename[0] != '\0') {

            int chLen = getFileLength(); //got the total number of character+1(abc,'\n','\0')

            if (chLen > 0) {
                m_content = new char[chLen + 1]; ///pb?
                ifstream file(m_filename);
                if (file) { //open successfully
                    file.read(m_content, chLen); //read and store in m_content
                    m_content[chLen] = '\0';
                    file.close();
                }
                else {
                    setEmptyState();
                }
            }
            else {
                setEmptyState();
            }
        }

    };
    void Text::write(std::ostream& os)const {
        if (m_content) { //!= nullptr
          os << m_content; 
        }
    };

std::ostream& operator<<(std::ostream& os, const Text& text) {
     text.write(os);
     return os;
};


}
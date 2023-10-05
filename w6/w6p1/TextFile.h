#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>
namespace sdds {
    class Line {
        char* m_value{ nullptr }; //a member var declaration:
        //{nullptr} :it initializes the m_value pointer to a null value.
        operator const char* ()const;
        Line() {}
        Line& operator=(const char*);
        ~Line();
        friend class TextFile; 
        // copy and copy assignment prevention goes here
        Line(const Line& line)=delete;
        Line& operator=(const Line& line)=delete;

    };

    class TextFile {
        //4 member var
        // 
        //A pointer to hold the dynamic array of Lines. 
        //This attribute should be initialized to nullptr
        Line* m_textLines{nullptr};

        //hold the dynamic Cstring holding the name of the file. 
        //This attribute should be initialized to nullptr
        char* m_filename{nullptr};

        // unsigned integer to be set to the number of lines in the file.
        unsigned m_noOfLines;

        //page size is the number of lines that should be displayed on the screen before the display is paused. After these lines are displayed, 
        //the user must hit enter for the next page to appear.
        unsigned m_pageSize;
        
        void setFilename(const char* fname, bool isCopy = false);
        void setNoOfLines();
        void loadText();
        void saveAs(const char* fileName)const;
        void setEmpty();
    public:
        TextFile(unsigned pageSize = 15);
        TextFile(const char* filename, unsigned pageSize = 15);
        TextFile(const TextFile&);
        TextFile& operator=(const TextFile&);
        ~TextFile();
        std::ostream& view(std::ostream& ostr)const;
        std::istream& getFile(std::istream& istr);
        operator bool()const;
        unsigned lines()const;
        const char* name()const;
        const char* operator[](unsigned index)const;
    };
    std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
    std::istream& operator>>(std::istream& istr, TextFile& text);

}
#endif // !SDDS_TEXTFILE_H__

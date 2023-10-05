#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "HtmlText.h"
namespace sdds {

    //public:
    void HtmlText::setEmptyState() {
        Text::setEmptyState();
        delete[] m_title;
        m_title = nullptr;
    };

    //initialize m_title
    HtmlText::HtmlText(const char* filename, const char* title) :Text(filename), m_title(nullptr) {

        //consider Text class?
        if (title != nullptr && title[0] != '\0') {
            
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
        else {
            setEmptyState();
        }

    };

    //rule of three
    HtmlText::HtmlText(const HtmlText& src) :Text(src), m_title(nullptr) {

        //*this = src;
        if (this != &src) {
            if (src.m_title != nullptr && src.m_title[0] != '\0') {
                m_title = new char[strlen(src.m_title) + 1];
                strcpy(m_title, src.m_title);

                //dont need read here: already call the copy constructor Text(src)
                //read();
            }
        }
      
    };

    HtmlText& HtmlText::operator= (const HtmlText& src) {

        if (this != &src) {
            Text::operator=(src); //base

            if (m_title) {

                delete[] m_title; // Release old memory
                m_title = nullptr;
            }

            if (src.m_title != nullptr && src.m_title[0] != '\0') {
                m_title = new char[strlen(src.m_title) + 1];
                strcpy(m_title, src.m_title);
            }
        }
        return *this;
    };
    HtmlText::~HtmlText() {
        delete[] m_title;
        m_title = nullptr;

    };

    void HtmlText::write(std::ostream& os)const {


        bool MS = false; //boolean set to false
        //1
        os << "<html><head><title>";
        (m_title != nullptr) ? os << m_title : os << "No Tiltle";

        //2
        os << "</title></head>\n<body>\n";

        if (m_title != nullptr) {
            os << "<h1>" << m_title << "</h1>\n";
        }


        const char* content = getContent();
        int contentLength = strlen(content);
        for (int i = 0; i < contentLength; i++) {

            const char& ch = content[i]; // Using the protected index operator of the base class
            //char ch = content[i];
            switch (ch) {
            case ' ':
                if (MS) {
                    os << "&nbsp;";
                }
                else {
                    MS = true;
                    os << ' ';
                }
                break;
            case '<':
                os << "&lt;";
                MS = false;
                break;
            case '>':
                os << "&gt;";
                MS = false;
                break;
            case '\n':
                os << "<br />\n";
                MS = false;
                break;
            default:
                os << ch;
                MS = false;
            }
        }
        os << "</body>\n</html>";
    }
   
};
        
  
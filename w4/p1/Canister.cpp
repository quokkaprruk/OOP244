#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include <string.h>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;

namespace sdds {

	//private
    void Canister::setToDefault() {
        m_contentName = nullptr; //sets the content name pointer to null
        m_diameter = 10.0; // in centimeters 
        m_height = 13.0;   // in centimeters
        m_contentVolume = 0.0;  // in CCs
        m_usable = true;
    };

    void Canister::setName(const char* Cstr) {
        //....
         if(Cstr != nullptr && m_usable){
             delete [] m_contentName;
             //allocate 
             m_contentName = new char[strlen(Cstr) + 1];
             //copy
             strcpy(m_contentName, Cstr);
             //add null terminator at the end
             m_contentName[strlen(Cstr)] = '\0';
         }
         
    };

    bool Canister :: isEmpty()const {
        return (m_contentVolume < 0.00001) ? true : false;
    };

    bool Canister::hasSameContent(const Canister& C)const {
        return (strcmp(m_contentName, C.m_contentName) && !(m_contentName==nullptr && C.m_contentName==nullptr)) ? true : false;
    };
    
    //public
    Canister::Canister() {//constructor
        m_contentName = nullptr; //empty string by default
        m_diameter = 10.0; // in centimeters 
        m_height = 13.0;   // in centimeters
        m_contentVolume = 0.0;  // in CCs
        m_usable = true;
    
    };

    Canister::Canister(const char* contentName) {
        //Sets the attributes to their default values (note: reuse code)
        setToDefault();
        setName(contentName);
    };

    Canister::Canister(double height, double diameter, const char* contentName) {
        
        setToDefault();
        //If the dimensions are within acceptable values:
        if ((height >= 10.0 && height <= 40.0) && (diameter >= 10.0 && diameter <= 30)) {
            //add this?
            m_height = height;
            m_diameter = diameter;
            m_contentVolume = 0.0;
            setName(contentName);
        }
        else {
            m_usable = false;
        }

    };
    //destructor
    Canister::~Canister() {//destructer
        //***
        delete[] m_contentName;
    };

    Canister& Canister::setContent(const char* contentName) {

        //It will set the Content name of the canister using the 
        //following rule and then returns the reference of the current 
        //object (i.e. *this):

        if (contentName == nullptr) {
            this->m_usable = false;
        }
        else if (this->m_contentName == nullptr || this->m_contentName[0] == '\0' ) { //add the latter condition /*|| this->m_contentName == nullptr*/
            setName(contentName);
        }
        else if(strcmp(m_contentName,contentName) != 0){
            
                this->m_usable = false;  
        }

        return *this;
    };

   
    Canister& Canister :: pour(double quantity) { // quantity refers to C[5], 
     
        //m_usable, volume, capacity, m_contentVolume all refers to C[6]
        if (m_usable && quantity > 0 && (volume() + quantity) <= capacity()) {

            m_contentVolume += quantity;

        }
        else { //case: overflow
            m_usable = false;
        }
        
        return *this; //*this still refers to C[6] ??
    };


    //C[6]=milK pour C[5]=milk 
    //current obj = C[6]
    Canister& Canister :: pour(Canister& C) { 

        //Pours the content of the Canister argument into 
        //the current Canister following the Specs stated at the top
       
        if (this->isEmpty()) {
            this->clear();
            setName(C.m_contentName);//change this->name to C.name
            /*
            this->m_contentName = new char[strlen(C.m_contentName) + 1];
            strcpy(this->m_contentName, C.m_contentName);*/
        }
        else {
            setContent(C.m_contentName);  
        }

        if (C.volume() > (this->capacity() - this->volume())) {

            double difContent = this->capacity() - this->volume();
            C.m_contentVolume -= difContent;
            this->m_contentVolume = this->capacity();
        }
        else {

            pour(C.m_contentVolume);
            C.m_contentVolume = 0.0;
        }
       
        return *this;
    };

    double Canister::volume()const {
        return m_contentVolume;
    };

    //object : std::ostream& => allows the function to be used in a chain with other stream output operations.
    std::ostream& Canister ::display()const {
    
        cout << fixed << setprecision(1) << setw(7) << capacity();
        cout << "cc (";
        cout << fixed << setprecision(1) << m_height;
        cout << "x";
        cout << fixed << setprecision(1) << m_diameter;
        cout << ") Canister";

        if (!m_usable) {
            cout << " of Unusable content, discard!";
        }
        else if (m_contentName != nullptr) {
            cout << " of ";
            cout << fixed << setprecision(1) << setw(7) << volume();
            cout << "cc   ";
            cout << m_contentName;
        }

        return cout;
    };

    double Canister::capacity()const {
        const double PI = 3.14159265;
        double Capacity = PI *(m_height - 0.267) * (m_diameter/ 2) *(m_diameter / 2);

        return Capacity;
    };
    void Canister::clear() {
        delete[] m_contentName;
        
        setToDefault();
    };
}
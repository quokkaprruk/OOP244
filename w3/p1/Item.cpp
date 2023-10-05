//I have done all the coding by myself
//and only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {

    //PRIVATE
    void Item::setName(const char* name) {
        strnCpy(m_itemName, name, sizeof(m_itemName) - 1);
        m_itemName[sizeof(m_itemName) - 1] = '\0';
    };

    //PUBLIC

    // Sets the Item to a recognizable safe Empty State. 
    void Item:: setEmpty() {
        m_itemName[0] = '\0'; //m_itemName[0] = '\0';
        m_price = 0.0;
    };
    

    //DON'T FORGET:empty state(safe empty state).***
    void Item::set(const char* name, double price, bool taxed) {
        
        if (price < 0.0 || name == nullptr) {
            setEmpty();
        }
        else {
            setName(name);
            m_price = price, m_taxed = taxed;

        }
    };
  
    double Item:: price()const {
        return m_price;
    };

    // Returns the product of m_price and 0.13 Or returns 0.0 if the m_taxed is false.
    double Item:: tax()const {    
        const double taxRate = 0.13;
        return (m_taxed) ?  (m_price * taxRate): 0.0;//(m_taxed == false) ?  0.0 : (m_price*taxRate);
    };

    // Returns true if the Item is not set to the empty state (As done in setEmpty function) .
    // This function can not modify its owner.
    bool Item::isValid()const {
        return (m_itemName[0] != '\0' && m_price != 0.0); // ? true : false;
    };

    void Item:: display()const {
        const int NAME_WIDTH = 20;
        const int PRICE_WIDTH = 7;
        const int PRICE_PRECISION = 2;
        if (isValid()) {
            cout << "| ";
            //start from left
            cout << left << setw(NAME_WIDTH) << setfill('.') << m_itemName;
            cout << " | ";
            //start from right
            cout << fixed << right << setw(PRICE_WIDTH) << setfill(' ') << setprecision(PRICE_PRECISION) << m_price;
            cout << " | ";
            cout << (m_taxed ? "Yes" : "No ");
            cout << " |" << endl;
        }
        else {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |\n";
        }
    };
    
}

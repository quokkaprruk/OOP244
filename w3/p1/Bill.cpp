//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

    //PRIVATE:
    //Sets the Bill object to an empty state by setting m_title to an Empty Cstring and m_items to nullptr
    void Bill::setEmpty() {
        m_title[0] = '\0';
        m_items = nullptr;//This is Item class
    };

    //***Returns true if m_title is not empty and m_items is not null and all the Items in the m_items array are valid.
    bool Bill::isValid()const {
    
        bool result = true;
        int flag = 0;
        if (m_title[0] != '\0' && m_items != nullptr) {
            for (int i = 0; i < m_noOfItems && flag == 0; i++) {
                if (!m_items[i].isValid()) {
                    result = false;
                    flag = 1;
                }
            }
        }
            return result;
    };

    double Bill:: totalTax()const {

        double sum = 0.0;
        for (int i = 0; i < m_noOfItems; i++) {
            //Adds all the taxes of the items using a loop 
            sum += m_items[i].tax();
        }
        return sum;
    };

    double Bill::totalPrice()const {
        double sum = 0.0;
        for (int i = 0; i < m_noOfItems; i++) {
            //Adds all the price of the items using a loop 
            sum += m_items[i].price();
        }
        return sum;
    };

    void Bill::Title()const {
        const int WIDTH = 36;
        cout << "+--------------------------------------+\n";
        if (isValid()) {
            cout << "| " << left << setw(WIDTH) << setfill(' ') << m_title;
            cout << " |\n";
        }
        else {
            cout << "| Invalid Bill                         |\n";
        }
        cout << "+----------------------+---------+-----+\n";
        cout << "| Item Name            | Price   + Tax |\n";
        cout << "+----------------------+---------+-----+\n";
    };

    void Bill::footer()const {
        const int WIDTH = 10;
        cout << "+----------------------+---------+-----+\n"; 
        if (isValid()) {
            cout << "|                Total Tax: ";
            cout  << right << setw(WIDTH) << setfill(' ') << totalTax();
            cout << " |\n";
            cout << "|              Total Price: ";
            cout  << right << setw(WIDTH)<< setfill(' ') << totalPrice();
            cout << " |\n";    
            cout << "|          Total After Tax: ";
            cout  << right << setw(WIDTH) << setfill(' ')  << totalTax() + totalPrice();
            cout << " |\n";
        }
        else {
            cout << "| Invalid Bill                         |\n";
        }
        cout << "+--------------------------------------+\n";

    };
    

    //PUBLIC:
    void Bill::init(const char* title, int noOfItems) {

       // If any of the arguments are invalid, it will set the Bill to an empty state (ie. title is null or noOfItems is zero or less)
        if (title == nullptr || noOfItems<= 0) {
            setEmpty();
        }
        else {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;

            strnCpy(m_title, title, sizeof(m_title) - 1);//size = 37-1
            //m_title[sizeof(m_title)-1] = '\0';

            // dynamic allocate an array of Items pointed by m_items member variable.
            // The length of this array will be m_noOfItems.
            m_items = new Item[m_noOfItems];

            //*****Make sure all the dynamically allocated Items are set to empty
            for (int i = 0; i < m_noOfItems; i++) {
                m_items[i].setEmpty();
            }
        }
    };

 
    bool Bill::add(const char* item_name, double price, bool taxed) {
    
        bool result = false;
    
        if (m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].set(item_name,price,taxed);
            m_itemsAdded++;
            result = true;
        }
        return result;
    };

    void Bill::display()const {
        Title();
        for (int i = 0; i < m_noOfItems; i++) {
            m_items[i].display();
        }
        footer();
    };

    void Bill::deallocate() {
        delete[] m_items;
        m_items = nullptr;
    };
}
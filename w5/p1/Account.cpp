#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
    //private function
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }
    // New account : constructor
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }
    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }
    //function
    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }

    //1: returns true if the account is valid and otherwise false. 
      //This operator can not modify the account object.
    Account::operator bool() const {
         return (m_number >= 10000 && m_number <= 99999
             && m_balance >= 0);
    };

    //2.returns the account number. 
    //This operator can not modify the account object.
    Account::operator int() const {
        return m_number; //change from m_number to return this->m_number
    };

    //3.returns the balance value. 
    //This operator can not modify the account object.
    Account:: operator double() const {
        return m_balance;
    };

    //type: unary operator
    
    bool Account ::operator ~() const{ // why after add const, it works?
        
        return (m_number == 0);
    };


    //type: binary operator
    /*All the binary member operators will not take any action if the account is in an invalid state.*/
    Account& Account::operator=(const int newAcNumber) {
        if (newAcNumber >= 10000 && newAcNumber <= 99999) {
           
            if (m_number == 0) { //this ac is new
                m_number = newAcNumber;
            }
        }
        else {
            setEmpty();
        }
        return *this;
    }; 

    Account& Account::operator=(Account& rightAccount) { //mix[8] == mix[7]
    //left ac is new and right  ac have to be valid
        //movemoney from old ac to new ac
        if ( m_number == 0 && rightAccount.operator bool()) {
            m_balance = rightAccount.m_balance;
            m_number = rightAccount.m_number;
            rightAccount.m_balance = 0;
            rightAccount.m_number = 0;

        }
        else {
            //?
        }
        return *this;
    
    }; //new account can be set to another Account object

    Account& Account::operator+=(const double value) {
        //val must >= 0 and account isvalid
        if (value >= 0 && *this) {
            m_balance += value;
        }
        return *this;
    };

    Account& Account::operator-=(const double value) {
        if (value <= m_balance && value >= 0 && *this) {
            m_balance -= value;
        }
        return *this;
    };

    Account& Account::operator<<(Account& anotherAc) { // move fund to the left account
        if (anotherAc.m_number != this->m_number) {
            this->m_balance += anotherAc.m_balance;
            anotherAc.m_balance = 0.0; // this is wrong
        }

        return *this;
    }; 

    Account& Account::operator>>(Account& anotherAc) { // move fund to the right account
        if (anotherAc.m_number != this->m_number) {
            anotherAc.m_balance += m_balance;
            m_balance = 0.0;
        }
        return *this;
    }; 

    //helper function
    double operator+(const Account& leftAc, const Account& rightAc) {
        double sum=0.0;

      //  if ((bool)leftAc && (bool)rightAc) {
        if (leftAc && rightAc) {
            sum = (double)leftAc + (double)rightAc;
        }
        return sum;

    };
    double operator+=(double& leftVal, const Account& rightAc) {
   
        double sum = leftVal;
        //sum += static_cast<double>(rightAc);
        sum += (double)rightAc;
        // Cast to double explicitly
        // sum += rightAc.m_balance; // why cant use this??
        leftVal = sum; // Assign the updated value back to the leftVal reference
        return leftVal;
    };

};




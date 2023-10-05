#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();
    public:
        //constructor
        Account();
        Account(int number, double balance);
        //function
        std::ostream& display()const;

        //operator
        //type: conversion operator
        operator bool() const;
        operator int () const;
        operator double() const;

        //type: unary operator
        bool operator~() const;

        //type: binary operator
        Account& operator=(const int newAcNumber); //set new account number //add const

        Account& operator=(Account& rightAccount); //new account can be set to another Account object

        Account& operator+=(const double value);//add const

        Account& operator-=(const double value);//add const

        Account& operator<<(Account& anotherAc); // move fund to the left account

        Account& operator>>(Account& anotherAc); // move fund to the right account

    };
    //helper operator
    double operator+(const Account& leftAc, const Account& rightAc);
    double operator+=(double& leftVal, const Account& rightAc);

}
#endif // SDDS_ACCOUNT_H_
#ifndef SDDS_MARK_H
#define SDDS_MARK_H

namespace sdds {

	class Mark {
		int m_mark;

	public:

		//constructor:
		Mark();//default constructor

		Mark(int value);//overloaded constructor
	
		//operators
		//: conversion 
		operator int () const; //return int value
		operator double() const;
		operator bool() const; //return true if mark is valid
		operator char() const;

		//unary operator?
		
		//binary operator
		Mark& operator+=(const int value); //what should be return?

		Mark& operator=(int value);

	};
	int operator+=(int& value, Mark& mark);
}

#endif // !1
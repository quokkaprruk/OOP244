#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Mark.h"

using namespace std;

namespace sdds {

	//private:

	//public:
	//constructor:
	Mark::Mark() { //default constructor
		m_mark = 0;
	};

	Mark::Mark(int value) { //overloaded constructor
		
		if (value >= 0 && value <= 100) { //can use bool operator?
			m_mark = value;
		}
		else {
			m_mark = -1;
		}
	};

	//operators
	//: conversion 
	Mark:: operator int() const { //return int value
		
		return (m_mark >= 0 && m_mark <= 100) ? m_mark : 0;
	}; 

	Mark::operator double() const {

		double m_gpa = 0.0;
		if (m_mark >= 0 && m_mark < 50) {
			m_gpa = 0.0;
		}
		else if (m_mark < 60) {
			m_gpa = 1.0;
		}
		else if (m_mark < 70) {
			m_gpa = 2.0;
		}
		else if (m_mark < 80) {
			m_gpa = 3.0;
		}
		else if (m_mark <= 100) {
			m_gpa = 4.0;
		}
		
		return m_gpa;
	};
	
	Mark::operator bool() const { //return true if mark is valid // use???///not use
		return (m_mark >= 0 && m_mark <= 100);
	}; 

	Mark::operator char() const {

		char m_grade = 'X';
		if (m_mark >= 0 && m_mark < 50) {
			
			m_grade = 'F';
		}
		else if (m_mark < 60) {
			m_grade = 'D';
		}
		else if (m_mark < 70) {
			m_grade = 'C';
		}
		else if (m_mark < 80) {
			m_grade = 'B';
		}
		else if (m_mark <= 100) {
			m_grade = 'A';
		}

		return m_grade;
	};

	//unary operator?

	//binary operator
	Mark& Mark::operator+=(const int value) { 
		//if (m_mark >= 0 && m_mark <= 100) 
		if(*this){ 
			if (value >= 0 && value <= 100) { //if it's valid => let's see where it's go? : should go to operator bool
				this->m_mark += value;
			}
		}
		return *this;
	}; 

	Mark& Mark::operator=(int value) { 
		
		this->m_mark = value;	
		return *this;
	};

	
	//why recursive problem??? 
	int operator+=(int& value, Mark& mark) { //com confusion? why?
		int tempmark = (int)mark;
		if (tempmark >= 0 && tempmark <= 100) {
			value += tempmark;
		}
		return value;
	};

}

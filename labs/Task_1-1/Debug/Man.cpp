// реализация класса Man
#include "stdafx.h"
#include <iostream>
#include "Man.h"

const int l_name = 30;
const int l_year = 5;
const int l_pay = 10;
const int l_buf = l_name + l_year + l_pay;



Man::Man(int lName) { 
	std::cout << "Constructor is working\n";
	pName = new char[lName + 1];
}
Man::~Man() { 
	std::cout << "Destructor is working\n";
	delete[] pName;
}

void Man::SetName(const char* fromBuf) {
	if (pName == NULL) {
		std::cout << "problem\n";
	}
	strncpy_s(pName, l_name, fromBuf, _TRUNCATE);
	pName[l_name] = '\0';
}
//void Man::SetBirthYear(const char* fromBuf) {
//	
//}
//void Man::SetPay(const char* fromBuf) {
//	
//}


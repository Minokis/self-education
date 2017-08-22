// реализация класса Man
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "Man.h"





Man::Man(int lName) { 
	std::cout << "Constructor is working\n";
	pName = new char[lName + 1];
}
Man::~Man() { 
	std::cout << "Destructor is working\n";
	delete[] pName;
}

void Man::SetName(const char* fromBuf) {
	strncpy_s(pName, l_name - 1, fromBuf, _TRUNCATE);
	pName[l_name] = '\0';
}
void Man::SetBirthYear(const char* fromBuf) {
	birth_year = atoi(fromBuf + l_name);
}
void Man::SetPay(const char* fromBuf) {
	pay = atof(fromBuf + l_name + l_year);
}

void Man::Print() {
	std::cout << pName << "\t" << birth_year << "\t" << std::setprecision(10) << pay << std::endl;
}

bool Man::CompareName(const char* name) {
	if (strstr(pName, name) && pName[strnlen_s(name, l_name)] == ' ')
		return true;
	else
		return false;
		
}

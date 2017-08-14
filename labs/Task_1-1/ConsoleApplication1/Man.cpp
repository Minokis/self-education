//
//  Man.cpp
//  Task_1-1
//
//  Created by Anna Korniychuk on 7/11/17.
//
// ���������� ������ Man
#include "stdafx.h"
#include <iostream>
#include <cstring>
#include "Man.h"
using namespace std;

Man::Man(int lName) {
	cout << "Constructor is working!" << endl;
	name = new char[lName + 1];
}
Man::~Man() {
	cout << "Destructor is working" << endl;
	delete[] name;
}

bool Man::CompareName(const char* suggested_name) const {
	if (strstr(name, suggested_name) && name[strlen(suggested_name)] == ' ')
		return true;
	else
		return false;
}

void Man::Print() const {
	cout << name << birth_year << ' ' << pay << endl;
}

void Man::SetName(const char* fromBuf) {
	strncpy_s(name, name_length, fromBuf, name_length - 1);
	name[name_length] = 0;
}

void Man::SetBirthYear(const char* fromBuf) {
	birth_year = atoi(fromBuf + name_length);
}

void Man::SetPay(const char* fromBuf) {
	pay = atof(fromBuf + name_length + year_length);
}

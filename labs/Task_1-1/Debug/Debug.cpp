// Debug.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Man.h"

void copy(char* dst, int size, const char* src) {
	strncpy_s(dst, size, src, _TRUNCATE);
	std::cout << dst << std::endl;
}

int main()
{		
	Man man;
	man.SetName("cats");
	// man.SetBirthYear(1999);
	std::cout << man.GetName();
		
    return 0;
}


// 2_ifs_and_loops.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	float x, y;
	printf("Введите значение аргумента x: ");
	scanf_s("%f", &x);	
	if (x < -2)                 y = 0;
	else if (x >= -2 && x < -1) y = -x - 2;
	else if (x >= -1 && x < 1)  y = x;
	else if (x >= 1 && x < 2)  y = -x + 2;
	else                        y = 0;
	printf("Для значения x = %5.2f y = %5.2f\n", x, y);
	return 0;
}



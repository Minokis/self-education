// 2_4_values_table.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <locale>
#include <math.h>

/*
		t,  x < 0
	y = tx, 0 <= x < 10
		2t, x >= 10

		Если t>100, показывать целые значения.
*/

int main()
{
	setlocale(LC_ALL, "Russian");
	double Xn, Xk, dX, t;
	printf("Введите начальное, конечное значение аргумента, шаг и параметр функции: ");
	scanf_s("%lf%lf%lf%lf", &Xn, &Xk, &dX, &t);
	printf("Контрольный вывод: %lf %lf %lf %lf\n", Xn, Xk, dX, t);

    return 0;
}


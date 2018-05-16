// 2_4_values_table.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <stdio.h>
#include <locale>
#include <math.h>

/*
		t,  x < 0
	y = tx, 0 <= x < 10
		2t, x >= 10

		If t>100, output is in integers.
*/

int main()
{
	setlocale(LC_ALL, "Russian");
	double Xn, Xk, dX, t, y;
	printf("Enter Xn, Xk, dX, t:");
	scanf_s("%lf%lf%lf%lf", &Xn, &Xk, &dX, &t);
	printf("Control output: %lf %lf %lf %lf\n", Xn, Xk, dX, t);
	printf("---------------------\n");
	printf("|       X    |    Y    |\n");
	printf("---------------------\n");
	for (double x = Xn; x <= Xk; x +=dX) {
		if (x < 0)            y = t;
		if (x >= 0 && x < 10) y = t * x;
		if (x >= 10)          y = 2 * t;
		
		if (t > 100) printf("|%9.2lf    |%9d    |\n", x, static_cast<int>(y));
		else printf("|%9.2lf    |%9.2lf    |\n", x, y);

	}
    printf("---------------------\n");
    return 0;
}

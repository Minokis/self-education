// 2_homework_var_14.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>


int main()
{
	double a, b, c, Xn, Xk, dX, y;
	printf("Enter a, b, c: ");
	scanf_s("%lf%lf%lf", &a, &b, &c);
	printf("\nEnter Xn, Xk, dX: ");
	scanf_s("%lf%lf%lf", &Xn, &Xk, &dX);
	printf("Control output: %5.2lf %5.2lf %5.2lf %5.2lf %5.2lf %5.2lf\n", a, b, c, Xn, Xk, dX);
	printf("---------------------\n");
	printf("|    X    |    Y    |\n");
	printf("---------------------\n");
	for (double x = Xn; x < Xk; x += dX) {
		if (x + c < 0 && a != 0) y = -a*x*x*x - b;
		else if (x + c > 0 && a == 0) y = (x - a) / (x - c);
		else y = x / c + c / x;

		printf("|%9.2lf|%9.2lf|\n", x, y);
	}
	
	
    return 0;
}


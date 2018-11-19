// 7_1_standard_types.cpp: определяет точку входа для консольного приложения.
// Write a program which outputs a table of values of function Ch(x) - hyperbolic cos
// for x changing in input boundaries with input step. Taylor, precision is epsilon

#include "stdafx.h"
#include <stdio.h>
#include <math.h>

double custom_cosh(double x, double eps, int &err);


int main()
{
	using namespace std;
	puts("Enter Xn, Xk, step, epsilon: ");
	double Xn, Xk, dX, eps, y;
	int err;
	scanf_s("%lf%lf%lf%lf", &Xn, &Xk, &dX, &eps);
	// cntrl output
	printf("\nYou entered %lf, %lf, %lf, %lf", Xn, Xk, dX, eps);
	printf("---------------------\n");
	printf("|      X      |         Y        |       math.h     |\n");
	printf("---------------------\n");
	for (double x = Xn; x <= Xk; x += dX) {
		y = custom_cosh(x, eps, err);
		if (err == 1) printf("|%9.2lf    |     Diverged!    |%14.6g    |\n", x, cosh(x));
		else printf("|%9.2lf    |%14.6g    |%14.6g    |\n", x, y, cosh(x));
	}
	printf("---------------------\n");
	
    return 0;
}

double custom_cosh(double x, double eps, int &err) {
	err = 0;
	double current=1, y=current;
	const int MaxIter = 500;
	for (int i = 0; fabs(current) > eps; ++i) {
		current *= x * x / (2 * i + 1) / (2 * i + 2);
		y += current;
		if (i > MaxIter) { err = 1; return err; }
	}
	return y;

}

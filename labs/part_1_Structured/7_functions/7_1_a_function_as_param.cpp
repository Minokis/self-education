// Write a program which outputs a table of values of function Ch(x) - hyperbolic cos
// for x changing in input boundaries with input step. Taylor, precision is epsilon
// We'll encapsulate table printing in a separate function!
// We also won't use err for error diagnostic - troublesome

//#include "stdafx.h" // uncomment in Visual Studio
#include <stdio.h>
#include <math.h>

// we define a type "pointer to the function which takes 2 double params and returns a double" as Pfun:
typedef double (*Pfun)(double, double);
// Now we use const to show values that we won't change in the function
// We can't use a default parameter as this function is going to be a parameter of print_tabl
double custom_cosh(const double x, const double eps);
void print_tabl(Pfun fun, const double Xn, const double Xk, const double dX, const double eps);

int main()
{
	using namespace std;
	puts("Enter Xn, Xk, step, epsilon: ");
	double Xn, Xk, dX, eps, y;
	int err;
	// scanf_s("%lf%lf%lf%lf", &Xn, &Xk, &dX, &eps); // uncomment in Visual Studio and comment the next line
	scanf("%lf%lf%lf%lf", &Xn, &Xk, &dX, &eps);
	// cntrl output
	printf("\nYou entered %lf, %lf, %lf, %lf", Xn, Xk, dX, eps);

	print_tabl(&custom_cosh, Xn, Xk, dX, eps);

    return 0;
}

double custom_cosh(const double x, const double eps){
	double current=1, y=current;
	const int MaxIter = 500;
	for (int i = 0; fabs(current) > eps; ++i) {
		current *= x * x / (2 * i + 1) / (2 * i + 2);
		y += current;
		if (i > MaxIter) { return 0; }
	}
	return y;
}

void print_tabl(Pfun fun, const double Xn, const double Xk, const double dX, const double eps) {
	printf("---------------------\n");
	printf("|      X      |         Y        |       math.h     |\n");
	printf("---------------------\n");
	for (double x = Xn; x <= Xk; x += dX) {
		printf("|%9.2lf    |%14.6g    |%14.6g    |\n", x, fun(x, eps), cosh(x));
	}
	printf("---------------------\n");
}

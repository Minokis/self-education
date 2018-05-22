// Сходимость ряда гиперболического косинуса

#include "stdafx.h"
#include <iostream>
#include <math.h>


int main()
{
	setlocale(LC_ALL, "Russian");
	using namespace std;
	cout << "x and epsilon: ";
	double y = 1, current = 1, x, eps;
	cin >> x >> eps;
	const int MaxIter = 500;

	//for (int n = 0; n < 100; ++n) {
	//	current *= x * x / (2 * n + 1) / (2 * n + 2);
	//	y += current;
	//	cout << "current = " << current << ", y = " << y << endl;
	//}
	int n = 0;
	for (; n < MaxIter && fabs(current)>eps; ++n) {
		current *= x * x / (2 * n + 1) / (2 * n + 2);
		y += current;
	}
	if (n < MaxIter) {
		cout << "Result: y = " << y << ", with x = " << x << " after " << n << " iterations." << endl;
		cout << "Math.h function result: " << cosh(x) << endl;
	}
	else
		cout << "The series diverges!" << endl;
    return 0;
}


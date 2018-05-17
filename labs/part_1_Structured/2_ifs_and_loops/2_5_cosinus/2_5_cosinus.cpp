// 2_5_cosinus.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>


int main()
{
	using namespace std;
	const int MaxIter = 500;
	double x, epsilon;
	cout << "Enter x and epsilon: ";
	cin >> x >> epsilon;
	double current = 1.0, result = 1;
	for (int n = 2; current > epsilon || n <= MaxIter; ++n) {
		current *= x * x / (2 * n + 1) / (2 * n + 2); 
		result += current;		
	}
	cout << "\nEnd result is " << result << endl;
	cout << "Math cos is " << cos(x) << endl;
    return 0;
}


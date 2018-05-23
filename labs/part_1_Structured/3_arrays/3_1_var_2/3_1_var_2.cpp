// 3_arrays.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	const int n = 10;
	int a[n];
	cout << "Enter array elements: ";
	for (int j = 0; j < n; ++j)
		cin >> a[j];

	int imin = 0, imax = 0;
	for (int i = 0; i < n; i++) {
		if (fabs(a[i]) < fabs(a[imin])) imin = i;
		if (fabs(a[i]) > fabs(a[imax])) imax = i;
	}

	int product = 1;
	int ibeg = imin < imax ? imin : imax;
	int iend = imax > imin ? imax : imin;
	cout << "ibeg = " << ibeg << ", iend = " << iend << endl;

	for (int j = ibeg + 1; j < iend; j++) {
		if (a[j] < 0) {
			product *= a[j];
			cout << "\na[j] = " << a[j] << ", prod = " << product;
		}
	}


	cout << "\nmin = " << a[imin] << ", imin = " << imin << endl;
	cout << "max = " << a[imax] << ", imax = " << imax << endl;
	cout << "product of negative elements between: " << product << endl;

	return 0;
}


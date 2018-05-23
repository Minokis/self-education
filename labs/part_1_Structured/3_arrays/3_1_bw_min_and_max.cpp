// 3_arrays.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	const int n = 10;
	int a[n], count = 0;
	cout << "Enter array elements: ";
	for (int j = 0; j < n; ++j)
		cin >> a[j];
	
	int i, imin, imax;
	for (i = imin = imax = 0; i < n; i++) {
		if (a[i] < a[imin]) imin = i;
		if (a[i] > a[imax]) imax = i;
	}
	int ibeg, iend;
	ibeg = imin < imax ? imin : imax;
	iend = imax > imin ? imax : imin;
	for (int j = ibeg+1; j < iend; j++) 
		if (a[j] > 0) count++;


	//int d = 0;
	//if (imin < imax) d = 1;
	//else if (imax < imin) d = -1;
	//
	//for (int j = imin+d; j != imax; j+=d)
	//	if (a[j] > 0) count++; 

	cout << "\nmin = " << a[imin] << ", imin = " << imin << endl;
	cout << "max = " << a[imax] << ", imax = " << imax << endl;
	cout << "number of elements between: " << count << endl;

    return 0;
}


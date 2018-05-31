// 3_3_quicksort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	const int n = 20;
	//float arr[n], middle, temp;
	float middle, temp;
	int *stackl = new int[n], *stackr = new int[n], sp = 0;
	int i, j, left, right;
	/*cout << "Enter elements: ";
	for (i = 0; i < n; i++) cin >> a[i];*/
	float arr[n] = { 1.7, -18, 34.1, 1.8, 2.8, -9.2, -3, 0.6, 26.1, 100, 11, -2.5, -3, 0, 2.6, 7.1, -5, 5.9, 19, 0.7 };

	// Поехали!
//	sp = 1; stackl[1] = 0; stackr[1] = n - 1;

	left = 0; right = n - 1;
	middle = arr[(left + right) / 2];

	while()




    return 0;
}


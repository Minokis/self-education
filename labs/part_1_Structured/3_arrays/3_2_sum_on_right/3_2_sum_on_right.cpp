// 3_2_sum_on_right.cpp: определяет точку входа для консольного приложения.
// Написать программу, которая считает сумму элементов правее самого крайнего отрицательного
// (для вещественного массива из n элементов)

#include "stdafx.h"
#include <iostream>


int main()
{
	setlocale(LC_ALL, "Russian");
	using namespace std;
	int n;
	cout << "Enter number of elements: ";
	cin >> n;
	double *a = new double[n];
	cout << "\nEnter elements: ";
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	double sum = 0;
	for (int i = n - 1; i > 0 && a[i] >= 0; i--) {
		sum += a[i];
	}
	delete[] a;
	cout << "\nSum: " << sum << endl;
    return 0;
}


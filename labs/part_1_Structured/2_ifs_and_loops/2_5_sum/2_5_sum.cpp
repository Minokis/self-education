// 2_5_sum.cpp: ���������� ����� ����� ��� ����������� ����������.
// ������ �� ���������� ����� ����

#include "stdafx.h"
#include <iostream>
#include <math.h>


int main()
{
	setlocale(LC_ALL, "Russian");
	using namespace std;
	cout << "������� �������� x � ��������: ";
	double y = 1, current = 1, x, eps;
	cin >> x >> eps;
	const int MaxIter = 500;

	for (int n = 1; n < 5; ++n) {
		current *= x * x / (2 * n + 1) / (2 * n + 2);
		y += current;
		cout << "current"
	}
    return 0;
}


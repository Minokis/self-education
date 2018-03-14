// 1_var_6_cos.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	const double pi = 3.14159265;
	setlocale(LC_ALL, "Russian");
	double alpha, result1, result2;
	cout << "Введите угол в градусах: ";
	cin >> alpha;
	double radians = alpha*pi/180;
	cout << "\nУгол в градусах: " << alpha;
	result1 = cos(radians) + cos(2 * radians) + cos(6 * radians) + cos(7 * radians);
	result2 = 4 * cos(radians / 2) * cos(5.0 / 2 * radians) * cos(4.0 * radians);
	cout << "\nПо формуле 1: " << result1;
	cout << "\nПо формуле 2: " << result2 << endl;
  return 0;
}

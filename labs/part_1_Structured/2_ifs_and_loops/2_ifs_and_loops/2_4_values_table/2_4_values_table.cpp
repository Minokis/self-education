// 2_4_values_table.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <stdio.h>
#include <locale>
#include <math.h>

/*
		t,  x < 0
	y = tx, 0 <= x < 10
		2t, x >= 10

		���� t>100, ���������� ����� ��������.
*/

int main()
{
	setlocale(LC_ALL, "Russian");
	double Xn, Xk, dX, t;
	printf("������� ���������, �������� �������� ���������, ��� � �������� �������: ");
	scanf_s("%lf%lf%lf%lf", &Xn, &Xk, &dX, &t);
	printf("����������� �����: %lf %lf %lf %lf\n", Xn, Xk, dX, t);
	printf("-------------------------\n");
	printf("|    X    |    Y    |\n");
	printf("-------------------------\n");

	// Initial statements
	double x = Xn;

    return 0;
}

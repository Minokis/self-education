// 2_2_target.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	cout << "������ �� ����� � �������? ����� ��������!" << endl;
	float x, y;	
	cout << "������� �������� x � y : ";
	cin >> x >> y;
	if (x * x + y * y <= 1 || x <= 0 && y <= 0 && y >= -x - 2)
		cout << "����� � �������!" << endl;
	else
		cout << "����� �� � �������." << endl;
    return 0;
}


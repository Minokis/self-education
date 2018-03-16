// 2_2_target.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Попадёт ли точка в область? Давай проверим!" << endl;
	float x, y;	
	cout << "Введите значения x и y : ";
	cin >> x >> y;
	if (x * x + y * y <= 1 || x <= 0 && y <= 0 && y >= -x - 2)
		cout << "Точка в области!" << endl;
	else
		cout << "Точка не в области." << endl;
    return 0;
}


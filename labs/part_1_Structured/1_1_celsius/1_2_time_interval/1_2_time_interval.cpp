// 1_2_time_interval.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	short hour, min, sec, hour1, min1, sec1, hour2, min2, sec2;
	cout << "Введите время начала интервала (час мин сек): ";
	cin >> hour1 >> min1 >> sec1;
	cout << "\nВведите время конца интервала (час мин сек): ";
	cin >> hour2 >> min2 >> sec2;
	long sum_sec = (hour2 - hour1) * 3600 + (min2 - min1) * 60 + sec2 - sec1;
	hour = sum_sec / 3600;
	short min_test = sum_sec % 3600 / 60;
	min = (sum_sec - 3600 * hour) / 60;
	sec = sum_sec - 3600 * hour - 60 * min;
	short sec_test = sum_sec % 60;
	cout << "\nПродолжительность промежутка от " <<
		hour1 << ':' << min1 << ':' << sec1 << " до " <<
		hour2 << ':' << min2 << ':' << sec2 << " равна " <<
		hour << ':' << min << ':' << sec << endl;
	cout << "min_test " << min_test << endl;
	cout << "sec_test " << sec_test << endl;

    return 0;
}


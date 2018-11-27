// 7_3_str_to_func.cpp: определ€ет точку входа дл€ консольного приложени€.
// Ќаписать программу, котора€ подсчитывает количество чисел в каждой строке тестового файла
// ƒлина строки не превышает 100 символов
// ƒл€ простоты считаем, что числа либа целый, либо вещественные с фиксированной точкой и непустой дробной частью

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <ctype.h>

using namespace std;

//int num_num()

int main()
{
	ifstream fin("test.txt", ios::in);
	if (!fin) { cout << "Could not open the file test.txt!\n"; return 1; }
	
    return 0;
}


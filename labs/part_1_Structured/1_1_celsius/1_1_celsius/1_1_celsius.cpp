// 1_1_celsius.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Windows.h>
//#include <stdio.h>
//int global;
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	float cels, fahr;
//	printf("Введите температуру по Фаренгейту: ");
//	scanf_s("%f", &fahr);
//	cels = 5 * (fahr - 32) / 9;
//	printf(" Температура по Фаренгейту: %6.2f, по Цельсию: %6.2f\n", fahr, cels);
//	return 0;
//
//}
#include <iostream>
// Эксперимент с инициализацией глобальной переменной: почему-то при печати с printf - ненулевое значение
int global;
char* Rus(const char* text);

int main()
{
	//setlocale(LC_ALL, "Russian");
	std::cout << "global: " << global << std::endl;
	// Эксперимент с инициализацией статической переменной:
	static int st_var;
	std::cout << "static: " << st_var << std::endl;
	float cels, fahr;
	std::cout << Rus(" Введите температуру по Фаренгейту: ") << std::endl;
	std::cin >> fahr;
	cels = 5.0f / 9.0f * (fahr - 32.0f);
	std::cout << Rus(" Температура по Фаренгейту: ") << fahr << Rus(", по Цельсию: ") << cels << std::endl;
	return 0;
}

char bufRus[256];
char * Rus(const char* text) {
	CharToOem(text, bufRus);
	return bufRus;
}
// 1_1_celsius.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <Windows.h>
//#include <stdio.h>
//int global;
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	float cels, fahr;
//	printf("������� ����������� �� ����������: ");
//	scanf_s("%f", &fahr);
//	cels = 5 * (fahr - 32) / 9;
//	printf(" ����������� �� ����������: %6.2f, �� �������: %6.2f\n", fahr, cels);
//	return 0;
//
//}
#include <iostream>
// ����������� � �������������� ���������� ����������: ������-�� ��� ������ � printf - ��������� ��������
int global;
char* Rus(const char* text);

int main()
{
	//setlocale(LC_ALL, "Russian");
	std::cout << "global: " << global << std::endl;
	// ����������� � �������������� ����������� ����������:
	static int st_var;
	std::cout << "static: " << st_var << std::endl;
	float cels, fahr;
	std::cout << Rus(" ������� ����������� �� ����������: ") << std::endl;
	std::cin >> fahr;
	cels = 5.0f / 9.0f * (fahr - 32.0f);
	std::cout << Rus(" ����������� �� ����������: ") << fahr << Rus(", �� �������: ") << cels << std::endl;
	return 0;
}

char bufRus[256];
char * Rus(const char* text) {
	CharToOem(text, bufRus);
	return bufRus;
}
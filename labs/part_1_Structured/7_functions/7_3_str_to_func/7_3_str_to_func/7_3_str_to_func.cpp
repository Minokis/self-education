// 7_3_str_to_func.cpp: ���������� ����� ����� ��� ����������� ����������.
// �������� ���������, ������� ������������ ���������� ����� � ������ ������ ��������� �����
// ����� ������ �� ��������� 100 ��������
// ��� �������� �������, ��� ����� ���� �����, ���� ������������ � ������������� ������ � �������� ������� ������

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <ctype.h>

using namespace std;

int num_num(const char *str);

int main()
{
	ifstream fin("test.txt", ios::in);
	if (!fin) { cout << "Could not open the file test.txt!\n"; return 1; }

	const int len = 101;
	char str[len];
	int i = 1; 

	while (fin.getline(str, len)) {
		cout << "Line " << i << " has " << num_num(str) << " numbers." << endl;
		i++;
	}
	
    return 0;
}

// Won't work if there's a  sentence with number at the end (with period)
int num_num(const char *str) {
	int count = 0;
	while (*str) {
		if (isdigit(*str) && !isdigit(*(str+1)) && *(str + 1) != '.') count++;
		str++;
	}
	return count;
}

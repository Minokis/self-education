// 7_3_str_to_func.cpp: ���������� ����� ����� ��� ����������� ����������.
// �������� ���������, ������� ������������ ���������� ����� � ������ ������ ��������� �����
// ����� ������ �� ��������� 100 ��������
// ��� �������� �������, ��� ����� ���� �����, ���� ������������ � ������������� ������ � �������� ������� ������

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


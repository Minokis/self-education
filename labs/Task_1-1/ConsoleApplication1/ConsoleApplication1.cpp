//  Task_1-1
//
//  Created by Anna Korniychuk on 7/11/17.
//
/* �������: � ��������� ����� �������� ���� ������ ������,
����� 100 �����������. ������ ������ ����� �������� ������ �� ����� ����������:
������� � �������� (30 �������), ��� �������� (5 �������), ����� (10 �������).
�������� ���������, ������� �� �������� ������� ������� �� ����� ��������
� ����������, ����������� ������� ����� ���� ����������� �����������.
*/

#include "stdafx.h"
#include <fstream>
#include "Man.h"
#include <iostream>
using namespace std;

const char filename[] = "dbase.txt";

int main() {
	setlocale(LC_ALL, "Russian");
	const int max_number_of_records = 10;
	Man men[max_number_of_records];
	char buf[buf_length + 1];
	char suggested_name[name_length + 1];

	// open file
	ifstream fin(filename);
	if (!fin) {
		cout << "��� ����� " << filename << endl;
		return 1;
	}
	// set parameters for each person
	int i = 0;
	while (fin.getline(buf, buf_length)) {
		if (i >= max_number_of_records) {
			cout << "������� ������� ����." << endl;
			return 1;
		}
		men[i].SetName(buf);
		men[i].SetBirthYear(buf);
		men[i].SetPay(buf);
		i++;
	}
	int n_record = i, n_man = 0;
	float mean_pay = 0;

	while (true) {
		cout << "������� ������� ��� ����� end: ";
		cin >> suggested_name;
		if (0 == strcmp(suggested_name, "end"))
			break;
		bool not_found = true;
		for (i = 0; i < n_record; ++i) {
			if (men[i].CompareName(suggested_name)) {
				men[i].Print();
				n_man++;
				mean_pay += men[i].GetPay();
				not_found = false;
				break;
			}
		}
		if (not_found) cout << "������ ���������� ���" << endl;
	}
	if (n_man) cout << "������� �����: " << mean_pay / n_man << endl;
	return 0;
}

// 2_3_control_keys.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <locale>


int main()
{
	setlocale(LC_ALL, "Russian");
	printf("������� �������. � ������ ������� ��� ������ ��� �������.\n��� ������ ������� 0.\n");
	int key=0;
	while (key != 48) {
		key = _getch(); key = _getch();
		switch (key) {
		case 72: printf("�����!\n"); break;
		case 75: printf("�����!\n"); break;
		case 77: printf("������!\n"); break;
		case 80: printf("����!\n"); break;
		default: printf("� ��� ����� %d\n", key);
		}
	}
	return 0;
}


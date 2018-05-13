// 2_3_control_keys.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <locale>


int main()
{
	setlocale(LC_ALL, "Russian");
	printf("Нажмите клавишу. Я угадаю стрелку или выведу код клавиши.\nДля выхода нажмите 0.\n");
	int key=0;
	while (key != 48) {
		key = _getch(); key = _getch();
		switch (key) {
		case 72: printf("Вверх!\n"); break;
		case 75: printf("Влево!\n"); break;
		case 77: printf("Вправо!\n"); break;
		case 80: printf("Вниз!\n"); break;
		default: printf("А это номер %d\n", key);
		}
	}
	return 0;
}


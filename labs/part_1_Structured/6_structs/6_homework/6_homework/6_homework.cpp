/*
ќписать структуру с именем TRAIN, содержащую следующие пол€:
- название пункта назначени€,
- номер поезда,
- врем€ отправлени€.
Ќаписать программу, выполн€ющую следующие действи€:
- ввод с клавиатруы данных в массив, состо€щий из шести элементов типа TRAIN;
записи должны быть упор€дочены по времени отправлени€ поезда
- вывод на экран информации о поездах, направл€ющис€ в пункт, название которого введено с клавиатуры
- если таких поездов нет, выдать на дисплей соответствующее сообщение
*/

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <ctime>

using namespace std;

int main() {
	const int l_dest = 41;
	const int l_num = 5; // номер воспринимаетс€ не как число, а как строка, котора€ может начинатьс€ с нул€
	const int l_time = 6;

	struct TRAIN {
		char destination[l_dest];
		char number[l_num];
		char departure_time[l_time];
	};

	const int l_dbase = 6;
	TRAIN dbase[l_dbase];

	// universal counter i
	int i;
	// hours and minutes - temporary variables
	int hh, mm;
	char timestring[l_time];

	puts("Let's enter the data in the database.\n");
	for (i = 0; i < l_dbase; i++) {
		printf("Enter the data for the train %i: destination, number, time:  ", i);

		fgets(dbase[i].destination, l_dest, stdin);
		dbase[i].destination[strcspn(dbase[i].destination, "\n")] = '\0';
		fgets(dbase[i].number, l_num, stdin);
		dbase[i].number[strcspn(dbase[i].number, "\n")] = '\0';
		//fgets(dbase[i].departure_time, l_time, stdin);
		//dbase[i].departure_time[strcspn(dbase[i].departure_time, "\n")] = '\0';
		fgets(timestring, l_time, stdin);
		timestring[strcspn(timestring, "\n")] = '\0';
		int hh = atoi(timestring);
		if (hh < 0 || hh>23) { puts("Invalid hours. Skipping.\n"); i--; continue; }
		int mm = atoi(&timestring[3]);
		if (mm < 0 || mm>59) { puts("Invalid minutes. Skipping.\n"); i--; continue; }

		printf("You entered: train %i, dest = %s, num = %s, time = %i:%i\n", i, dbase[i].destination, dbase[i].number, hh, mm);
		/*int hh = atoi(dbase[i].departure_time);
		printf("Hours: %i", hh);
		int mm = atoi(&dbase[i].departure_time[3]);
		printf("Minutes: %i", mm);*/


		//TODO: врем€ лучше будем хранить числом (scanf hh, mm), затем time=hh*60+mm
		// обратно hh = time/60, mm = time%60
		// можно непосредственно сравнивать между собой по числу минут
		// сортировка (можно qsort попробовать снова)
		// поиск по destination
		//  bool not_found = 1;
		// for (int i = 0; i< l_dbase; i++) {
		//   if (strstr(dbase[i].destination, str) == 0) {
		//    printf(<...>); not_found = 0;}
		// }
		// if(not_found) puts("Not found.\n");
	}
	return 0;

}


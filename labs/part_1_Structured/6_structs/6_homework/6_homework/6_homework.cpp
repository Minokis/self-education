/*
������� ��������� � ������ TRAIN, ���������� ��������� ����:
- �������� ������ ����������,
- ����� ������,
- ����� �����������.
�������� ���������, ����������� ��������� ��������:
- ���� � ���������� ������ � ������, ��������� �� ����� ��������� ���� TRAIN;
������ ������ ���� ����������� �� ������� ����������� ������
- ����� �� ����� ���������� � �������, ������������� � �����, �������� �������� ������� � ����������
- ���� ����� ������� ���, ������ �� ������� ��������������� ���������
*/

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <ctime>

using namespace std;

int main() {
	const int l_dest = 41;
	const int l_num = 5; // ����� �������������� �� ��� �����, � ��� ������, ������� ����� ���������� � ����; 
	const int l_time = 6;

	struct TRAIN {
		char destination[l_dest];
		char number[l_num];
		int departure_time;
	};

	const int l_dbase = 3;
	TRAIN dbase[l_dbase];

	// universal counter i
	int i;
	// hours and minutes - temporary variables
	int hh, mm;
	char timestring[l_time];
	char *p;
	

	puts("Let's enter the data in the database.\n");
	for (i = 0; i < l_dbase; i++) {
		printf("Enter the data for the train %i:", i);

		puts("\nDestination (40 symbols): ");
		fgets(dbase[i].destination, l_dest, stdin);
		if (p = strchr(dbase[i].destination, '\n')) { // check newline in the read string
			*p = '\0';
		}
		else {
			scanf_s("%*[^\n]"); scanf_s("%*c"); // clear up to newline
		}

		puts("Number up to 4 symbols: ");
		fgets(dbase[i].number, l_num, stdin);		
		if (p = strchr(dbase[i].number, '\n')) { // check newline in the read string
			*p = '\0';
		}
		else {
			scanf_s("%*[^\n]"); scanf_s("%*c"); // clear up to newline
		}

		//fgets(dbase[i].departure_time, l_time, stdin);
		//dbase[i].departure_time[strcspn(dbase[i].departure_time, "\n")] = '\0';
		
		puts("Time in format 23:12 : ");
		fgets(timestring, l_time, stdin);
		if (p = strchr(timestring, '\n')) { // check newline in the read string
			*p = '\0';
		}
		else {
			scanf_s("%*[^\n]"); scanf_s("%*c"); // clear up to newline
		}

		hh = atoi(timestring);
		if (hh < 0 || hh > 23) { puts("Invalid hours. Skipping.\n"); i--; continue; }
		char *ku = strchr(timestring, ':');
		if(ku) mm = atoi(ku+1); else { puts("Invalid format. Skipping.\n"); i--; continue; }
		//mm = atoi(&timestring[3]);
		if (mm < 0 || mm > 59) { puts("Invalid minutes. Skipping.\n"); i--; continue; }
		dbase[i].departure_time = hh * 60 + mm;

		// TODO: ��������� ������ �����, ���� ����� < 10 ��� �������
		printf("You entered: train %i, dest = %s, num = %s, time = %i:%i\n", i, dbase[i].destination, dbase[i].number, hh, mm);
		//printf("You entered: train %i, dest = %s, num = %s, \n", i, dbase[i].destination, dbase[i].number);
		/*int hh = atoi(dbase[i].departure_time);
		printf("Hours: %i", hh);
		int mm = atoi(&dbase[i].departure_time[3]);
		printf("Minutes: %i", mm);*/


		//TODO: ����� ����� ����� ������� ������ (scanf hh, mm), ����� time=hh*60+mm
		// ������� hh = time/60, mm = time%60
		// ����� ��������������� ���������� ����� ����� �� ����� �����
		// ���������� (����� qsort ����������� �����)
		// ����� �� destination
		//  bool not_found = 1;
		// for (int i = 0; i< l_dbase; i++) {
		//   if (strstr(dbase[i].destination, str) == 0) {
		//    printf(<...>); not_found = 0;}
		// }
		// if(not_found) puts("Not found.\n");
	}
	return 0;

}


/*
Описать структуру с именем TRAIN, содержащую следующие поля:
- название пункта назначения,
- номер поезда,
- время отправления.
Написать программу, выполняющую следующие действия:
- ввод с клавиатруы данных в массив, состоящий из шести элементов типа TRAIN;
записи должны быть упорядочены по времени отправления поезда
- вывод на экран информации о поездах, направляющися в пункт, название которого введено с клавиатуры
- если таких поездов нет, выдать на дисплей соответствующее сообщение
*/

#include <stdio.h>
#include <string>
#include <ctime>

using namespace std;

int main() {
  const int l_dest = 41;
  const int l_time = 6;

  struct TRAIN {
    char destination[l_dest];
    int number;
    char departure_time[l_time];
  };

  const int l_dbase = 6;
  TRAIN dbase[l_dbase];

  puts("Let's enter the data in the database.\n");
  for (int i = 0; i < l_dbase; i++) {
    printf("Enter the data for the train %i: ", i);
    fgets(dbase[i].destination, l_dest, stdin);
    dbase[i].destination[strcspn(dbase[i].destination, "\n")] = '\0';
    scanf("%i ", &dbase[i].number);
    fgets(dbase[i].departure_time, l_time, stdin);
    dbase[i].departure_time[strcspn(dbase[i].departure_time, "\n")] = '\0';

    printf("You entered: train %i, dest = %s, num = %i, time = %s\n", i, dbase[i].destination, dbase[i].number, dbase[i].departure_time);
    int hh = atoi(dbase[i].departure_time);
    printf("Hours: %i", hh);
    int mm = atoi(&dbase[i].departure_time[3]);
    printf("Minutes: %i", mm);


    //TODO: время лучше будем хранить числом (scanf hh, mm), затем time=hh*60+mm
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

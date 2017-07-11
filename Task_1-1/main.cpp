//
//  main.cpp
//  Task_1-1
//
//  Created by Anna Korniychuk on 7/11/17.
//
/* Задание: в текстовом файле хранится база отдела кадров,
всего 100 сотрудников. Каждая строка файла содержит запись об одном сотруднике:
фамилия и инициалы (30 позиций), год рождения (5 позиций), оклад (10 позиций).
Написать программу, которая по заданной фамилии выводит на экран сведения
о сотруднике, подсчитывая средний оклад всех запрошенных сотрудников.
 */


#include <fstream>
#include "Man.h"

const char filename[] = "dbase.txt";

int main() {
    const int max_number_of_records = 10;
    Man men[max_number_of_records];
    char buf[buf_length + 1];
    char suggested_name[name_length + 1];

    // open file
    ifstream fin(filename);
    if(!fin) {
      cout << "Нет файла " << filename << endl;
      return 1;
    }
    // set parameters for each person
    int i = 0;
    while(fin.getline(buf, buf_length)) {
      if (i >= max_number_of_records) {
        cout << "Слишком длинный файл." << endl;
        return 1;
      }
      men[i].SetName(buf);
      men[i].SetBirthYear(buf);
      men[i].SetPay(buf);
      i++;
    }

    return 0;

}

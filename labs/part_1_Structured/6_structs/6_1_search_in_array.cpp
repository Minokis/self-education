/* Задание: в текстовом файле хранится база отдела кадров,
всего 100 сотрудников. Каждая строка файла содержит запись об одном сотруднике:
фамилия и инициалы (30 позиций), год рождения (5 позиций), оклад (10 позиций).
Написать программу, которая по заданной фамилии выводит на экран сведения
о сотруднике, подсчитывая средний оклад всех запрошенных сотрудников.
 */

// Исходные данные
// Текстовый файл; так как поиск осуществляется неоднократно, удобно весь
// его перенести в оперативную память в виде массива структур
// Результаты
// Выведена информация о сотруднике на экран. По завершении - средний оклад
// Промежуточные
// массив структур, вещественная для суммарного оклада, счетчик сотрудников

// Алгоритм
// 1. Ввести из файла в массив сведения
// 2. Организовать цикл (до ввода слова end):
// - ввод фамилии с клавиатуры
// - поиск в массиве
// - увеличение счетчика и суммарного оклада
// - вывод информации о сотруднике / сбщ об ошибке
// 3. Вывести средний оклад

#include <fstream>
#include <iostream>
#include <limits>
//#include <windows.h>
using namespace std;

int main(int argc, char *argv[])
{
  if(argc != 2) { cout << "Usage: enter the file with HR data.\n"; return 1; }
  const int l_name = 30, l_year = 5, l_pay = 10, l_buf = l_name+l_year+l_pay;

  struct Man {
    char name[l_name + 1];
    int birth_year;
    float pay;
  };
  const int l_dbase = 100;
  Man dbase[l_dbase];


  char name[l_name + 1];
  char buf[l_buf + 1];

  ifstream input(argv[1]);
  if(!input) { cout << "Cannot open the file.\n"; return 1; }


  // Reading from a file
  int i = 0;
  while( input.getline(buf, l_buf)) {
    if (i >= l_dbase) { cout << "The file is too long. Stopping.\n"; return 1; }
    strncpy(dbase[i].name, buf, l_name);
    dbase[i].name[l_name] = '\0';
    dbase[i].birth_year = atoi(&buf[l_name]);
    dbase[i].pay = atof(&buf[l_name + l_year]);
    i++;
  }
  int n_record = i, n_man = 0;
  float mean_pay = 0;

  while(true) {
    cout << "Enter a name or a word \"end\": ";
    // OemToChar(name, name);
    cin.get(name, l_name+1);
    cin.clear();
    cin.ignore( numeric_limits<streamsize>::max(), '\n');

    if ( strcmp(name, "end") == 0 ) break;

    bool not_found = true;
    for( i = 0; i < n_record; i++) {
      if ( strstr( dbase[i].name, name ) )
        if ( dbase[i].name[strlen(name)] == ' ') { // check if it is a part of namespace
          strcpy(name, dbase[i].name);
          // CharToOem(name, name);
          cout << name << dbase[i].birth_year << ' ' << dbase[i].pay << endl;
          n_man++; mean_pay += dbase[i].pay;
          not_found = false;
        }
    }
    if(not_found) cout << "No person with this name." << endl;
  }
    if(n_man>0) cout << "Average pay: " << mean_pay / n_man << endl;
    return 0;
}

//
// Скорректировать программу: сделать так, чтобы "не мешали" пробельные символы перед фамилией
// привести все в один регистр tolower(c), toupper(c)
// адаптировать для русского языка и кодировок ASCII и ANSI (раскомментировать и попробовать)
// функции для регистров русского языка tolower/toupper
// вариант с библиотечными функциями ввода-вывода
